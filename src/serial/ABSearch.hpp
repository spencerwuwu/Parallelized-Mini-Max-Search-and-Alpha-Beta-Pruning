#ifndef ABSERACH_HPP 
#define ABSEARCH_HPP
#include "ChessBoard.hpp"

ChessBoard* ABMinMax(ChessBoard* board, int dept_limit);
ChessBoard* ABMinMove(ChessBoard* board, int dept_limit, int dept, int a, int b);
ChessBoard* ABMaxMove(ChessBoard* board, int dept_limit, int dept, int a, int b);


#endif
