#include <iostream>
using namespace std;

#include "ChessBoard.hpp"

ChessBoard* Minmax(ChessBoard* board, int dept_limit);
ChessBoard* Minmove(ChessBoard* board, int dept_limit, int dept);
ChessBoard* Maxmove(ChessBoard* board, int dept_limit, int dept);


ChessBoard* Minmax(ChessBoard* board, int dept_limit){
	return Maxmove(board, int dept_limit, 0);
}

ChessBoard* Maxmove(ChessBoard* board, int dept_limit, int dept){
	vector<ChessBoard*> moves;
	ChessBoard* best_real_move = NULL;
	ChessBoard* best_move = NULL;
	ChessBoard* move = NULL;

	if (depth >= depth_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove();
		for (vector<ChessBoard*>::iterator it = moves.begin(); it != moves.end(); it++) {
			move = MinMove(*it, depth_limit, depth+1);
			if (best_move == NULL || move->eval(BLACK)
					> best_move->evaluate_board(BLACK)) {
				best_move = move;
				*best_real_move = it;
			}
		}
		return best_real_move;
	}
}

ChessBoard* MinMove(ChessBoard* board, int depth_limit, int depth) {
	vector<ChessBoard*> moves;
	ChessBoard* best_move = NULL;
	ChessBoard* best_real_move = NULL;
	ChessBoard* move = NULL;

	if (depth >= depth_limit) {//if depth limit is reached
		return board;
	} else {
		moves = board->listAllMove();
		for (vector<ChessBoard*>::iterator it = moves.begin(); it != moves.end(); it++) {
			move = MaxMove(*it, depth_limit, depth+1);
			if (best_move == NULL || move.evaluate_board(WHITE)
					< best_move->evaluate_board(WHITE)) {
				best_move = move;
				*best_real_move = it;
			}
		}
		return best_real_move;
	}
}
