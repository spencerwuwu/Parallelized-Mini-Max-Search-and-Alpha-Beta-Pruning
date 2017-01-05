#include "Search.hpp"
#include "PVSplit.hpp"
#include "ChessBoard.hpp"
#include "ABSearch.hpp"
#include <climits>
#include <iostream>
#include <pthread.h>
#include <vector>
#include <cstdlib>
#include <algorithm>

struct SearchArg {
    ChessBoard *board;
    ChessBoard *res;
    int dept_limit;
    int dept;
    enum FindAction action;
    int alpha;
    int beta;
    pthread_t thread_id;
};

static ChessBoard* PVNode(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta);
ChessBoard* PVMinMax(ChessBoard* board, int dept_limit)
{
	return PVNode(board, dept_limit, 1, FIND_MAX, -INT_MAX, INT_MAX);
}

static void *thread_start(void *arg);
static ChessBoard* PVNode(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta) 
{
    if (dept >= dept_limit) {//if depth limit is reached
        return board;
    }

    std::vector<ChessBoard*> moves = board->listAllMove(action);

    /* pv node */
    ChessBoard* best_move = PVNode(moves[0], dept_limit, dept + 1, child(action), alpha, beta);
    int best_real_move = 0;
    if ( child(action) == FIND_MAX ){
        beta = best_move->eval(BLACK); // upper bound
    } else {
        alpha = best_move->eval(WHITE); // lower bound
    }

    if (alpha > beta) {
        goto cut_this_node;
    }

    { 
        /* cut nodes */
        struct SearchArg *children = (struct SearchArg*)malloc(sizeof(struct SearchArg) * (moves.size()));
        for (int i = 1; i < moves.size(); i++) {
            children[i].dept_limit = dept_limit;
            children[i].dept = dept + 1;
            children[i].action = child(action);
            children[i].alpha = alpha;
            children[i].beta = beta;
            children[i].board = moves[i];
            pthread_create(&children[i].thread_id, NULL, thread_start, &children[i]);
        }

        for (int i = 1; i < moves.size(); i++) {
            pthread_join(children[i].thread_id, NULL);
            ChessBoard* move = children[i].board;
            if (cmp_move(action, move, best_move)) {
                best_move = move;
                best_real_move = i;
            }
        }
        free(children);
    }

cut_this_node:
    ChessBoard* res = new ChessBoard;
    *res = *moves[best_real_move];
    for (int i = 0; i < moves.size(); i++) {
        delete moves[i];
    }
    return res;
}

static void *thread_start(void *arg)
{
    struct SearchArg *sarg = (struct SearchArg*)arg;
    ChessBoard* board = sarg->board;
    int dept_limit = sarg->dept_limit;
    int dept = sarg->dept;
    enum FindAction action = sarg->action;
    int alpha = sarg->alpha;
    int beta = sarg->beta;

    sarg->res = ABMinMaxMove(board, dept_limit, dept, action, alpha, beta);
    return NULL;
}

