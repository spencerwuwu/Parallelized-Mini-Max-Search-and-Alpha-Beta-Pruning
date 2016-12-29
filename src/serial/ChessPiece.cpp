#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#define WHITE 0
#define BLACK 1

#include "ChessBoard.hpp"

Piece::Piece(const Piece &obj){
	color	= obj.getcol();
}

bool King::checkmove( int origin, int dest){
	return false;
}


bool Queen::checkmove(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 9 == 0 	 	 // right-up
			||	(dest - origin) % 7 == 0 //	left-up
			||	dest%8 == origin%8		 // file
			||  dest/8 == origin/8	)	 // rank
	{
		// dest clean
		return true;
	}
	else return false;
}

bool Bishop::checkmove(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 9 == 0 	 	 // right-up
			||	(dest - origin) % 7 == 0 //	left-up
	  ){
		//apply move
		return true;
	}
	else return false;
}

bool Rook::checkmove(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 8 == 0 	 	 // same file
			||	( dest/8 == origin/8 )   // same rank
	  ){
		//apply move
		return true;
	}
	else return false;
}
bool Knight::checkmove(int origin, int dest){
	// check aviability of movement
	if( (dest - origin) % 17 == 0 	 	  // right-up
			||	(dest - origin) % 15 == 0 // left-up
	  ){
		//apply move
		return true;
	}
	else return false;
}
bool Pawn::checkmove(int origin, int dest){
	// check aviability of movement
	// if haven't moved
	if( this->color==WHITE ){  // white
		if ( origin/8==6 ){					 // haven't been moved
			if ( ( dest==origin-8 ) || ( dest==origin-16 ) ){
				//apply move
				return true;
			}
		}
		else {	//have been moved
			if (  dest==origin-8 ){
				//apply move
				return true;
			}
		}
	}
	else { // white
		if ( origin/8==1 ){					 // haven't been moved
			if ( ( dest==origin+8 ) || ( dest==origin+16 ) ){
				//apply move
				return true;
			}
		}
		else {	//have been moved
			if (  dest==origin+8 ){
				//apply move
				return true;
			}
			else return false;
		}
	}
}
