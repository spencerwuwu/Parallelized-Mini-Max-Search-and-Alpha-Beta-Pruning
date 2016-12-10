#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#include <ChessBoard.hpp>


bool King::move( origin, dest){
	return false;
}


bool Queen::move( origin, dest){
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
			if ( chboard->pieceMap[chboard->boardMap[dest]].color != this.color ){
				chboard->pieceMap[chboard->boardMap[dest]].number --;
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
		if ( chboard->boardMap[dest] == epc_empty ){
			chboard->boardMap[dest] = chboard->boardMap[origin];
			chboard->boardMap[origin] = epc_empty;
			return true;
		}
		else{
			if ( chboard->pieceMap[chboard->boardMap[dest]].color != this.color ){
				chboard->pieceMap[chboard->boardMap[dest]].number --;
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
		if ( chboard->boardMap[dest] == epc_empty ){
			chboard->boardMap[dest] = chboard->boardMap[origin];
			chboard->boardMap[origin] = epc_empty;
			return true;
		}
		else{
			if ( chboard->pieceMap[chboard->boardMap[dest]].color != this.color ){
				chboard->pieceMap[chboard->boardMap[dest]].number --;
				chboard->boardMap[dest] = chboard->boardMap[origin];
				chboard->boardMap[origin] = epc_empty;
				return true;
			}
			else return false;
		}
	}
	else return false;
}
