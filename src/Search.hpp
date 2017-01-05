#ifndef SEARCH_HPP
#define SEARCH_HPP
#include "ChessBoard.hpp"

// for search
enum FindAction {
    FIND_MIN = 0, // WHITE
    FIND_MAX // BLACK
};
ChessBoard* MinMax(ChessBoard* board, int dept_limit);
bool cmp_move(enum FindAction action, ChessBoard *move, ChessBoard *best_move);
enum FindAction child(enum FindAction action);

#endif

