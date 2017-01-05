#include "ABSearch.hpp"
#include "ChessBoard.hpp"
#include <iostream>
using namespace std;

ChessBoard* ABMinMax(ChessBoard* board, int dept_limit){
	return ABMaxMove(board, dept_limit, 1, 0, 0);
}

static ChessBoard* _ABMinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int a, int b);

ChessBoard* ABMaxMove(ChessBoard* board, int dept_limit, int dept, int a, int b){
	return _ABMinMaxMove(board, dept_limit, dept, FIND_MAX,  a, b);
}

ChessBoard* ABMinMove(ChessBoard* board, int dept_limit, int dept, int a, int b) {
	return _ABMinMaxMove(board, dept_limit, dept, FIND_MIN, a, b);
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

static ChessBoard* _ABMinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int a, int b) {
	vector<ChessBoard*> moves;
	ChessBoard* best_move = NULL;
	int best_real_move = 0;
	ChessBoard* move = NULL;
	int alpha = a, beta = b;

	if (dept >= dept_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove(action);
		for (int i = 0; i < (int)moves.size(); i++) {
			move = _ABMinMaxMove( moves[i], dept_limit, dept+1, another(action), alpha, beta);
			if (best_move == NULL || cmp_move(action, move, best_move)) {
				best_move = move;
				best_real_move = i;
				if ( another(action) == FIND_MAX ){
					alpha = move->eval(BLACK);
				}
				else {
					beta = move->eval(WHITE);
				}
			}
			if ( another(action) == FIND_MAX ){
				if ( beta > alpha ){
					ChessBoard* res = new ChessBoard;
					*res = *moves[best_real_move];
					for (int i = 0; i < (int)moves.size(); i++) {
						delete moves[i];
					}
					return res;
				}
			}
			else {
				if ( beta < alpha ){
					ChessBoard* res = new ChessBoard;
					*res = *moves[best_real_move];
					for (int i = 0; i < (int)moves.size(); i++) {
						delete moves[i];
					}
					return res;
				}
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


