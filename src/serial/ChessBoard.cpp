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
	for(int i=0;i<64;i++){
		boardMap[i]=obj.boardMap[i];
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

	/*
	pieceMap[epc_wpawn]->number		= 	obj.pieceMap[epc_wpawn]->getnum();
	pieceMap[epc_wknight]->number	=	obj.pieceMap[epc_wknight]->getnum();
	pieceMap[epc_wbishop]->number	=	obj.pieceMap[epc_wbishop]->getnum();
	pieceMap[epc_wrook]->number		= 	obj.pieceMap[epc_wrook]->getnum();
	pieceMap[epc_wqueen]->number	= 	obj.pieceMap[epc_wqueen]->getnum();
	pieceMap[epc_wking]->number		= 	obj.pieceMap[epc_wking]->getnum();
	pieceMap[epc_bpawn]->number		= 	obj.pieceMap[epc_bpawn]->getnum();
	pieceMap[epc_bknight]->number	=	obj.pieceMap[epc_bknight]->getnum();
	pieceMap[epc_bbishop]->number	=	obj.pieceMap[epc_bbishop]->getnum();
	pieceMap[epc_brook]->number	= 	obj.pieceMap[epc_brook]->getnum();
	pieceMap[epc_bqueen]->number	= 	obj.pieceMap[epc_bqueen]->getnum();
	pieceMap[epc_bking]->number		= 	obj.pieceMap[epc_bking]->getnum();
	*/
}

void ChessBoard::initiate(){
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
				case epc_wking:		cout << "K|";
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
				case epc_bking:		cout << "k|";
									break;
				default:			cout << " |";
									break;
			}
		}
		cout << "  " << i+1 << endl ;
	}
	cout << " - - - - - - - - " << endl << " a b c d e f g h " << endl;

}

bool checkPiecePosition(string piece, int position){
	return true ;
}

void ChessBoard::movePiece(string piece, int origin, int dest){
	int check=0;
	if( 1 ){
		if( boardMap[dest] == epc_empty ) check=1;
		else if ( pieceMap[boardMap[dest]]->color != pieceMap[boardMap[origin]]->color ) check=1;

		if( check == 1){
			if( pieceMap[origin]->checkmove(origin, dest) ){
				if( boardMap[dest] != 0){
					removePiece(dest);
				}
				boardMap[dest]=boardMap[origin];
				boardMap[origin]=0;
			}
			else messageError();
		}
		else messageError();
	}
}

/*
vector<ChessBoard*> ChessBoard::listAllMove(){
	vector<ChessBoard*> *moves = new vector<ChessBoard*> ();
	int turn = get_turn() ? Black : White;

	for(int i = 0; i < 64; i++){
		if ( pieceMap[boardMap[i]].color == turn ){
			for( int j = 0; j < 64; j++){
				ChessBoard* temp = new ChessBoard*;
				*temp = this;
				if( temp->pieceMap[boardMap[i]]->move(i,j) ){
					moves->push_back(temp);
				}
			}
		}
	}

	return moves;
}

*/

void ChessBoard::messageError(){
	cout << "Error" << endl;
}

void ChessBoard::removePiece (int position ){
	pieceMap[boardMap[position]]->number --;
}

ChessBoard::~ChessBoard(){
	cout << "end" << endl;
}

