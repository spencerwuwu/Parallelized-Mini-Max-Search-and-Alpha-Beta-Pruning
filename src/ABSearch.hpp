#ifndef ABSERACH_HPP 
#define ABSEARCH_HPP
#include "ChessBoard.hpp"

ChessBoard* ABMinMax(ChessBoard* board, int dept_limit);
ChessBoard* ABMinMaxMove(ChessBoard* board, int dept_limit, int dept, enum FindAction action, int alpha, int beta);

#endif
