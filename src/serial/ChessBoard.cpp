#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#include "ChessBoard.hpp"

#define WHITE 0
#define BLACK 1


ChessBoard::ChessBoard(){
	initiate();
}

ChessBoard::ChessBoard(const ChessBoard &obj ){

	turn = 0;

	for(int i=0;i<64;i++){
		boardMap[i]=obj.boardMap[i];
	}
	for(int i=0;i<15;i++){
		pieceNum[i]=-1;
	}
	pieceMap[epc_wpawn]		= 	new Pawn(epc_wpawn);
	pieceMap[epc_wknight]	=	new Knight(epc_wknight);
	pieceMap[epc_wbishop]	=	new Bishop(epc_wbishop);
	pieceMap[epc_wrook]		= 	new Rook(epc_wrook);
	pieceMap[epc_wqueen]	= 	new Queen(epc_wqueen);
	pieceMap[epc_wking]		= 	new King(epc_wking);
	pieceMap[epc_bpawn]		= 	new Pawn(epc_bpawn);
	pieceMap[epc_bknight]	=	new Knight(epc_bknight);
	pieceMap[epc_bbishop]	=	new Bishop(epc_bbishop);
	pieceMap[epc_brook]		= 	new Rook(epc_brook);
	pieceMap[epc_bqueen]	= 	new Queen(epc_bqueen);
	pieceMap[epc_bking]		= 	new King(epc_bking);

	pieceNum[epc_wpawn]		=  obj.getNum(epc_wpawn);
	pieceNum[epc_wknight]	=  obj.getNum(epc_wknight);
	pieceNum[epc_wbishop]	=  obj.getNum(epc_wbishop);
	pieceNum[epc_wrook]		=  obj.getNum(epc_wrook);
	pieceNum[epc_wqueen]	=  obj.getNum(epc_wqueen); 
	pieceNum[epc_wking]		=  obj.getNum(epc_wking); 
	pieceNum[epc_bpawn]		=  obj.getNum(epc_bpawn); 
	pieceNum[epc_bknight]	=  obj.getNum(epc_bknight);
	pieceNum[epc_bbishop]	=  obj.getNum(epc_bbishop);
	pieceNum[epc_brook]		=  obj.getNum(epc_brook); 
	pieceNum[epc_bqueen]	=  obj.getNum(epc_bqueen); 
	pieceNum[epc_bking]		=  obj.getNum(epc_bking);
}

void ChessBoard::initiate(){

	turn = 0;

	pieceMap[epc_wpawn]		= 	new Pawn(epc_wpawn);
	pieceMap[epc_wknight]	=	new Knight(epc_wknight);
	pieceMap[epc_wbishop]	=	new Bishop(epc_wbishop);
	pieceMap[epc_wrook]		= 	new Rook(epc_wrook);
	pieceMap[epc_wqueen]	= 	new Queen(epc_wqueen);
	pieceMap[epc_wking]		= 	new King(epc_wking);
	pieceMap[epc_bpawn]		= 	new Pawn(epc_bpawn);
	pieceMap[epc_bknight]	=	new Knight(epc_bknight);
	pieceMap[epc_bbishop]	=	new Bishop(epc_bbishop);
	pieceMap[epc_brook]		= 	new Rook(epc_brook);
	pieceMap[epc_bqueen]	= 	new Queen(epc_bqueen);
	pieceMap[epc_bking]		= 	new King(epc_bking);

	for(int i=0;i<15;i++){
		pieceNum[i]=-1;
	}

	pieceNum[epc_wpawn]		= 	8;	
	pieceNum[epc_wknight]	=	2;
	pieceNum[epc_wbishop]	=	2;
	pieceNum[epc_wrook]		= 	2;
	pieceNum[epc_wqueen]	= 	1;
	pieceNum[epc_wking]		= 	1;
	pieceNum[epc_bpawn]		= 	8;
	pieceNum[epc_bknight]	=	2;
	pieceNum[epc_bbishop]	=	2;
	pieceNum[epc_brook]		= 	2;
	pieceNum[epc_bqueen]	= 	1;
	pieceNum[epc_bking]		= 	1;

	boardMap[a1] = epc_brook;
	boardMap[b1] = epc_bknight;
	boardMap[c1] = epc_bbishop;
	boardMap[d1] = epc_bqueen;
	boardMap[e1] = epc_bking;
	boardMap[f1] = epc_bbishop;
	boardMap[g1] = epc_bknight;
	boardMap[h1] = epc_brook;
	boardMap[a8] = epc_wrook;
	boardMap[b8] = epc_wknight;
	boardMap[c8] = epc_wbishop;
	boardMap[d8] = epc_wqueen;
	boardMap[e8] = epc_wking;
	boardMap[f8] = epc_wbishop;
	boardMap[g8] = epc_wknight;
	boardMap[h8] = epc_wrook;

	for( int i=8 ; i<=55 ; i++ ){
		if ( i<=15 ){
			boardMap[i] = epc_bpawn;
		}
		else if ( i>=48 ){
			boardMap[i] = epc_wpawn;
		}
		else{
			boardMap[i] = epc_empty;
		}
	}

}

void ChessBoard::print(){
	cout << " - - - - - - - - " << endl;
	for(int i = 0 ; i < 8 ; i++){
		cout << "|" ;
		for(int j = 0 ; j < 8 ; j++){
			switch (boardMap[i*8+j]) {
				case epc_wpawn:		cout << "P|";
									break;
				case epc_wknight:	cout << "K|";
									break;
				case epc_wbishop:	cout << "B|";
									break;
				case epc_wrook:		cout << "R|";
									break;
				case epc_wqueen:	cout << "Q|";
									break;
				case epc_wking:		cout << "C|";
									break;
				case epc_bpawn:		cout << "p|";
									break;
				case epc_bknight:	cout << "k|";
									break;
				case epc_bbishop:	cout << "b|";
									break;
				case epc_brook:		cout << "r|";
									break;
				case epc_bqueen:	cout << "q|";
									break;
				case epc_bking:		cout << "c|";
									break;
				default:			cout << " |";
									break;
			}
		}
		cout << "  " << i+1 << endl ;
	}
	cout << " - - - - - - - - " << endl << " a b c d e f g h " << endl;

}

bool checkPiecePosition(char piece, int position){
	return true ;
}

bool ChessBoard::movePiece(char piece, int origin, int dest, int turn){
	int check=0;
	bool finish=false;
	if ( boardMap[origin] != epc_empty ){
		if( pieceMap[boardMap[origin]]->color == turn ){
			if( boardMap[dest] == epc_empty ) check=1;
			else if ( pieceMap[boardMap[dest]]->color != pieceMap[boardMap[origin]]->color ) check=1;

			if( check == 1){
				if( pieceMap[boardMap[origin]]->checkmove(origin, dest, boardMap) ){
					if( boardMap[dest] != 0){
						removePiece(dest);
					}
					boardMap[dest]=boardMap[origin];
					boardMap[origin]=0;

					finish=true;
				}
			}
		}
	}

	return finish;
}

int ChessBoard::getTurn() {
	return turn;
}

vector<ChessBoard*> ChessBoard::listAllMove(int turn){
	vector<ChessBoard*> moves;
	ChessBoard* temp = new ChessBoard;
	*temp = *this;

	for(int i = 0; i < 64; i++){
		if ( boardMap[i] != epc_empty && pieceMap[boardMap[i]]->color == turn ){
            for( int j = 0; j < 64; j++){
                if( i != j && temp->pieceMap[boardMap[i]]->checkmove(i,j,boardMap) && temp->movePiece('c', i, j, turn) ){
                    ChessBoard* input = new ChessBoard;
                    *input = *temp;
                    moves.push_back(input);
                    *temp = *this;
                }
            }
		}
	}

    delete temp;
	return moves;
}


void ChessBoard::messageError(){
	cout << "Error" << endl;
}

void ChessBoard::showTurn(){
	int i = getTurn();
	if( i == 1 )	cout << "Black's turn" << endl;
	else	cout << "White's turn" << endl;
}

void ChessBoard::removePiece (int position ){
	pieceNum[boardMap[position]]--;
}


ChessBoard::~ChessBoard(){
	//cout << "end" << endl;
}

