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

bool King::checkmove( int origin, int dest, int* myboard){
	bool finish = false;
	if ( dest > origin ){
			if( dest ==  origin+9 )			finish=true;
			else if( dest ==  origin+8 )	finish=true;
			else if( dest ==  origin+7 )	finish=true;
			else if( dest ==  origin+1 )	finish=true;
	}
	else {
			if( dest ==  origin-9 )			finish=true;
			else if( dest ==  origin-8 )	finish=true;
			else if( dest ==  origin-7 )	finish=true;
			else if( dest ==  origin-1 )	finish=true;
	}

	return finish;
}


bool Queen::checkmove(int origin, int dest, int* myboard){
	// check aviability of movement
	bool finish = false;
	bool check = false;
	int count=0;
	if ( (dest - origin) % 9 == 0 ){	 	 // right-up
		if ( dest > origin ){
			count = (dest - origin) / 9;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 9 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 9;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 9 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	else if ( (dest - origin) % 7 == 0 ){	 //	left-up
		if ( dest > origin ){
			count = (dest - origin) / 7;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 7 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 7;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 7 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	else if ( dest%8 == origin%8 ){			// file
		if ( dest > origin ){
			count = (dest - origin) / 8;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 8 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 8;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 8 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	else if ( dest/8 == origin/8 ){			 // rank
		if ( dest > origin ){
			for( int i = 1 ; i < dest - origin ; i++){
				if ( myboard[ origin + i ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else { 
			for( int i = 1 ; i < origin - dest ; i++){
				if ( myboard[ origin - i ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
	}
			
	return finish;
}

bool Bishop::checkmove(int origin, int dest, int* myboard){
	bool finish = false;
	bool check = false;
	int count=0;
	if ( (dest - origin) % 9 == 0 ){	 	 // right-up
		if ( dest > origin ){
			count = (dest - origin) / 9;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 9 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 9;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 9 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	else if ( (dest - origin) % 7 == 0 ){	 //	left-up
		if ( dest > origin ){
			count = (dest - origin) / 7;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 7 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 7;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 7 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	return finish;
}

bool Rook::checkmove(int origin, int dest, int* myboard){
	bool finish = false;
	bool check = false;
	int count=0;
	if ( dest%8 == origin%8 ){			// file
		if ( dest > origin ){
			count = (dest - origin) / 8;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin+i * 8 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else {
			count = ( origin - dest ) / 8;
			for( int i = 1 ; i < count ; i++ ){
				if ( myboard[ origin - i * 8 ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}

	}
	else if ( dest/8 == origin/8 ){			 // rank
		if ( dest > origin ){
			for( int i = 1 ; i < dest - origin ; i++){
				if ( myboard[ origin + i ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
		else { 
			for( int i = 1 ; i < origin - dest ; i++){
				if ( myboard[ origin - i ] != epc_empty ){
					check = true;
					break;
				}
			}
			if ( !check ) finish = true;
		}
	}
			
	return finish;
}
bool Knight::checkmove(int origin, int dest, int* myboard){
	// check aviability of movement
	if( (dest - origin) % 17 == 0 	 	  // right-up
			||	(dest - origin) % 15 == 0 // left-up
	  ){
		//apply move
		return true;
	}
	else return false;
}
bool Pawn::checkmove(int origin, int dest, int* myboard){
	bool finish = false;
	// check aviability of movement
	// if haven't moved
	if( this->color==WHITE ){  // white
		if ( origin/8==6 ){					 // haven't been moved
			if ( ( dest==origin-8 ) || ( dest==origin-16 ) ){
				//apply move
				finish = true;
			}
		}
		else {	//have been moved
			if (  dest==origin-8 ){
				//apply move
				finish = true;
			}
		}

		if ( dest == origin - 7 || dest == origin - 9 ){
			if ( myboard[dest] != epc_empty && myboard[dest] > epc_blacky){
				finish = true;
			}
		}
	}
	else { // white
		if ( origin/8==1 ){					 // haven't been moved
			if ( ( dest==origin+8 ) || ( dest==origin+16 ) ){
				//apply move
				finish = true;
			}
		}
		else {	//have been moved
			if (  dest==origin+8 ){
				//apply move
				finish = true;
			}
		}

		if ( dest == origin + 7 || dest == origin + 9 ){
			if ( myboard[dest] != epc_empty && myboard[dest] < epc_blacky){
				finish = true;
			}
		}
	}
	return finish;
}
