#include "Search.hpp"
#include "PVSplit.hpp"
#include "ChessBoard.hpp"
#include "ABSearch.hpp"
#include <climits>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <glib.h>

struct ThreadData {
    ChessBoard *board;
    int dept;
    enum FindAction action;
    int task_id;
};

struct PoolData {
    int alpha;
    int beta;
    int dept_limit;
    ChessBoard *best_move;
    int best_real_move;
    GMutex ab_mutex; 
    GMutex res_mutex; 
};

static void *thread_start(gpointer data, gpointer user_data);
static ChessBoard* PVNode(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta, int nthreads);
ChessBoard* PVMinMax(ChessBoard* board, int dept_limit, int nthreads)
{
	return PVNode(board, dept_limit, 1, FIND_MAX, -INT_MAX, INT_MAX, nthreads);
}

static ChessBoard* PVNode(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta, int nthreads) 
{
    if (dept >= dept_limit) {//if depth limit is reached
        return board;
    }

    std::vector<ChessBoard*> moves = board->listAllMove(action);

    struct PoolData *pdata = new struct PoolData;
    pdata->best_move = PVNode(moves[0], dept_limit, dept + 1, child(action), alpha, beta, nthreads);
    pdata->best_real_move = 0;
    if ( child(action) == FIND_MAX ){
        pdata->beta = pdata->best_move->eval(BLACK); // upper bound
    } else {
        pdata->alpha = pdata->best_move->eval(WHITE); // lower bound
    }

    if (pdata->alpha > pdata->beta) {
        goto cut_this_node;
    }

    pdata->dept_limit = dept_limit;
    g_mutex_init(&pdata->ab_mutex);
    g_mutex_init(&pdata->res_mutex);

    {
        GThreadPool *pool = g_thread_pool_new((GFunc)&thread_start, pdata, nthreads, false, NULL);
        struct ThreadData *td = (struct ThreadData*)malloc(sizeof(struct ThreadData) * moves.size());
        for (int i = 1; i < moves.size(); i++) {
            td[i].board = moves[i];
            td[i].dept = dept + 1;
            td[i].action = child(action);
            td[i].task_id = i;
            g_thread_pool_push(pool, &td[i], NULL);
        }
        g_thread_pool_free(pool, false, true);
        free(td);
    }

cut_this_node:
    ChessBoard* res = new ChessBoard;
    *res = *moves[pdata->best_real_move];
    free(pdata);
    for (int i = 0; i < moves.size(); i++) {
        delete moves[i];
    }
    return res;
}

static ChessBoard* AB(ChessBoard* board, int dept, enum FindAction action, int alpha, int beta, struct PoolData *pdata);
static void *thread_start(gpointer data, gpointer user_data)
{
    struct PoolData *pdata = (struct PoolData*)user_data;
    struct ThreadData *td = (struct ThreadData*)data;

    g_mutex_lock(&pdata->ab_mutex);
    int alpha = pdata->alpha;
    int beta = pdata->beta;
    g_mutex_unlock(&pdata->ab_mutex);

    ChessBoard *res = AB(td->board, td->dept, td->action, alpha, beta, pdata);
    if (res == NULL) {
        return NULL;
    }

    bool ab_updated = false;
    g_mutex_lock(&pdata->res_mutex);
    /* 這裡要跟 ABSearch 相反 因為傳進來就是子樹了 */
    if (cmp_move(child(td->action), res, pdata->best_move)) { 
        pdata->best_move = res;
        pdata->best_real_move = td->task_id;
        ab_updated = true;
    }
    g_mutex_unlock(&pdata->res_mutex);

    if (ab_updated) {
        if (td->action == FIND_MAX) {
            g_mutex_lock(&pdata->ab_mutex);
            pdata->beta = res->eval(BLACK);
            g_mutex_unlock(&pdata->ab_mutex);
        } else {
            g_mutex_lock(&pdata->ab_mutex);
            pdata->alpha = res->eval(WHITE);
            g_mutex_unlock(&pdata->ab_mutex);
        }
    }

    return NULL;
}

static ChessBoard* AB(ChessBoard* board, int dept, enum FindAction action, int alpha, int beta, struct PoolData *pdata)
{
    g_mutex_lock(&pdata->ab_mutex);
    if (pdata->alpha > pdata->beta) {
        g_mutex_unlock(&pdata->ab_mutex);
        return NULL;
    }
    g_mutex_unlock(&pdata->ab_mutex);

    if (dept >= pdata->dept_limit) {//if depth limit is reached
        return board;
    }

    vector<ChessBoard*> moves = board->listAllMove(action);
    ChessBoard* best_move = NULL;
    int best_real_move = 0;
    bool cut = false;
    for (int i = 0; i < moves.size(); i++) {
        ChessBoard* move = AB( moves[i], dept+1, child(action), alpha, beta, pdata);
        if (move == NULL) {
            cut = true;
            break;
        }
        if (best_move == NULL || cmp_move(action, move, best_move)) {
            best_move = move;
            best_real_move = i;
            if ( child(action) == FIND_MAX ) {
                beta = move->eval(BLACK); // upper bound
            } else {
                alpha = move->eval(WHITE); // lower bound
            }
        }
        if (alpha > beta){
            break;
        }
    }
    ChessBoard *res;
    if (!cut) {
        res = new ChessBoard;
        *res = *moves[best_real_move];
    } else {
        res = NULL;
    }
    for (int i = 0; i < moves.size(); i++) {
        delete moves[i];
    }
    return res;
}

