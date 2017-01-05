#include "Search.hpp"
#include "ABSearch.hpp"
#include "ChessBoard.hpp"
#include <iostream>
#include <climits>
using namespace std;

ChessBoard* ABMinMax(ChessBoard* board, int dept_limit){
    return ABMinMaxMove(board, dept_limit, 1, FIND_MAX, -INT_MAX, INT_MAX);
}

ChessBoard* ABMinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta)
{
    if (dept >= dept_limit) {//if depth limit is reached
        return board;
    }

    vector<ChessBoard*> moves = board->listAllMove(action);
    ChessBoard* best_move = NULL;
    int best_real_move = 0;
    for (int i = 0; i < moves.size(); i++) {
        ChessBoard* move = ABMinMaxMove( moves[i], dept_limit, dept+1, child(action), alpha, beta);
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
    ChessBoard* res = new ChessBoard;
    *res = *moves[best_real_move];
    for (int i = 0; i < moves.size(); i++) {
        delete moves[i];
    }
    return res;
}


