#ifndef SEARCH_HPP
#define SEARCH_HPP
#include "ChessBoard.hpp"

ChessBoard* MinMax(ChessBoard* board, int dept_limit);
ChessBoard* MinMove(ChessBoard* board, int dept_limit, int dept);
ChessBoard* MaxMove(ChessBoard* board, int dept_limit, int dept);

#endif
