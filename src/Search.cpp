#include "Search.hpp"
#include "ChessBoard.hpp"
#include <iostream>
using namespace std;

ChessBoard* MinMax(ChessBoard* board, int dept_limit){
	return MaxMove(board, dept_limit, 0);
}

static ChessBoard* _MinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action);
ChessBoard* MaxMove(ChessBoard* board, int dept_limit, int dept){
    return _MinMaxMove(board, dept_limit, dept, FIND_MAX);
}

ChessBoard* MinMove(ChessBoard* board, int dept_limit, int dept) {
    return _MinMaxMove(board, dept_limit, dept, FIND_MIN);
}


static bool cmp_move(enum FindAction action, ChessBoard *move, ChessBoard *best_move)
{
    if (action == FIND_MIN) {
        return move->eval(WHITE) < best_move->eval(WHITE);
    } 

    return move->eval(BLACK) > best_move->eval(BLACK);
}

static inline enum FindAction another(enum FindAction action)
{
    if (action == FIND_MIN) {
        return FIND_MAX;
    }

    return FIND_MIN;
}

static ChessBoard* _MinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action) {
	vector<ChessBoard*> moves;
	ChessBoard* best_move = NULL;
    int best_real_move = 0;
	ChessBoard* move = NULL;

	if (dept >= dept_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove(action);
		for (int i = 0; i < (int)moves.size(); i++) {
			move = _MinMaxMove( moves[i], dept_limit, dept+1, another(action));
			if (best_move == NULL || cmp_move(action, move, best_move)) {
				best_move = move;
                best_real_move = i;
			}
		}

        ChessBoard* res = new ChessBoard;
        *res = *moves[best_real_move];
        for (int i = 0; i < (int)moves.size(); i++) {
            delete moves[i];
        }
		return res;
	}
}

