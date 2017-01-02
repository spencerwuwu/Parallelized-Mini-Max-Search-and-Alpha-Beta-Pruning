#include <iostream>
using namespace std;

#include "ChessBoard.hpp"

ChessBoard* MinMax(ChessBoard* board, int dept_limit);
ChessBoard* MinMove(ChessBoard* board, int dept_limit, int dept);
ChessBoard* MaxMove(ChessBoard* board, int dept_limit, int dept);


ChessBoard* MinMax(ChessBoard* board, int dept_limit){
	return MaxMove(board, dept_limit, 0);
}

ChessBoard* MaxMove(ChessBoard* board, int dept_limit, int dept){
	vector<ChessBoard*> moves;
	ChessBoard* best_real_move = NULL;
	ChessBoard* best_move = NULL;
	ChessBoard* move = NULL;

	if (dept >= dept_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove(BLACK);
		for (int i = 0; i < moves.size(); i++) {
			move = MinMove( moves[i], dept_limit, dept+1);
			if (best_move == NULL || move->eval(BLACK)
					> best_move->eval(BLACK)) {
				best_move = move;
				*best_real_move = *moves[i];
			}
		}
		return best_real_move;
	}
}

ChessBoard* MinMove(ChessBoard* board, int dept_limit, int dept) {
	vector<ChessBoard*> moves;
	ChessBoard* best_move = NULL;
	ChessBoard* best_real_move = NULL;
	ChessBoard* move = NULL;

	if (dept >= dept_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove(BLACK);
		for (int i = 0; i < moves.size(); i++) {
			move = MaxMove( moves[i], dept_limit, dept+1);
			if (best_move == NULL || move->eval(WHITE)
					< best_move->eval(WHITE)) {
				best_move = move;
				*best_real_move = *moves[i];
			}
		}
		return best_real_move;
	}
}
