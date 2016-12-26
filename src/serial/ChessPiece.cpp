#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define WHITE 0
#define BLACK 1

#include "ChessBoard.hpp"

Piece::Piece(const Piece &obj){
	number	= obj.number;
	color	= obj.color;
}

bool King::move( int origin, int dest){
	return false;
}


bool Queen::move(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 9 == 0 	 	 // right-up
			||	(dest - origin) % 7 == 0 //	left-up
			||	dest%8 == origin%8		 // file
			||  dest/8 == origin/8	)	 // rank
	{
		// dest clean
		if ( chboard->boardMap[dest] == epc_empty ){
			chboard->boardMap[dest] = chboard->boardMap[origin];
			chboard->boardMap[origin] = epc_empty;
			return true;
		}
		else{
			if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
				chboard->removePiece(dest);
				chboard->boardMap[dest] = chboard->boardMap[origin];
				chboard->boardMap[origin] = epc_empty;
				return true;
			}
			else return false;
		}
	}
	else return false;
}

bool Bishop::move(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 9 == 0 	 	 // right-up
			||	(dest - origin) % 7 == 0 //	left-up
	  ){
		//apply move
		if ( chboard->boardMap[dest] == epc_empty ){
			chboard->boardMap[dest] = chboard->boardMap[origin];
			chboard->boardMap[origin] = epc_empty;
			return true;
		}
		else{
			if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
				chboard->removePiece(dest);
				chboard->boardMap[dest] = chboard->boardMap[origin];
				chboard->boardMap[origin] = epc_empty;
				return true;
			}
			else return false;
		}
	}
	else return false;
}
bool Knight::move(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 17 == 0 	 	  // right-up
			||	(dest - origin) % 15 == 0 // left-up
	  ){
		//apply move
		if ( chboard->boardMap[dest] == epc_empty ){
			chboard->boardMap[dest] = chboard->boardMap[origin];
			chboard->boardMap[origin] = epc_empty;
			return true;
		}
		else{
			if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
				chboard->removePiece(dest);
				chboard->boardMap[dest] = chboard->boardMap[origin];
				chboard->boardMap[origin] = epc_empty;
				return true;
			}
			else return false;
		}
	}
	else return false;
}
bool Pawn::move(int origin, int dest){
	// check aviability of movement
	// if haven't moved
	if( this->color==WHITE ){  // white
		if ( origin/8==6 ){					 // haven't been moved
			if ( ( dest==origin-8 ) || ( dest==origin-16 ) ){
				//apply move
				if ( chboard->boardMap[dest] == epc_empty ){
					chboard->boardMap[dest] = chboard->boardMap[origin];
					chboard->boardMap[origin] = epc_empty;
					return true;
				}
				else{
					if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
						chboard->removePiece(dest);
						chboard->boardMap[dest] = chboard->boardMap[origin];
						chboard->boardMap[origin] = epc_empty;
						return true;
					}
					else return false;
				}
			}
		}
		else {	//have been moved
			if (  dest==origin-8 ){
				//apply move
				if ( chboard->boardMap[dest] == epc_empty ){
					chboard->boardMap[dest] = chboard->boardMap[origin];
					chboard->boardMap[origin] = epc_empty;
					return true;
				}
				else{
					if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
						chboard->removePiece(dest);
						chboard->boardMap[dest] = chboard->boardMap[origin];
						chboard->boardMap[origin] = epc_empty;
						return true;
					}
					else return false;
				}
			}
		}
	}
	else { // white
		if ( origin/8==1 ){					 // haven't been moved
			if ( ( dest==origin+8 ) || ( dest==origin+16 ) ){
				//apply move
				if ( chboard->boardMap[dest] == epc_empty ){
					chboard->boardMap[dest] = chboard->boardMap[origin];
					chboard->boardMap[origin] = epc_empty;
					return true;
				}
				else{
					if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
						chboard->removePiece(dest);
						chboard->boardMap[dest] = chboard->boardMap[origin];
						chboard->boardMap[origin] = epc_empty;
						return true;
					}
					else return false;
				}
			}
		}
		else {	//have been moved
			if (  dest==origin+8 ){
				//apply move
				if ( chboard->boardMap[dest] == epc_empty ){
					chboard->boardMap[dest] = chboard->boardMap[origin];
					chboard->boardMap[origin] = epc_empty;
					return true;
				}
				else{
					if ( chboard->pieceMap[chboard->boardMap[dest]]->color != this->color ){
						chboard->removePiece(dest);
						chboard->boardMap[dest] = chboard->boardMap[origin];
						chboard->boardMap[origin] = epc_empty;
						return true;
					}
					else return false;
				}
			}
			else return false;
		}
	}
}
