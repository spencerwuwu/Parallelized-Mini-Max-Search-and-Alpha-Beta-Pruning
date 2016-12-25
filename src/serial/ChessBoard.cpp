#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#include "ChessBoard.hpp"



ChessBoard::ChessBoard(){
	initiate();
}

ChessBoard::ChessBoard(const ChessBoard &obj ){
	for(int i=0;i<64;i++){
		ard* MinMax(Board* board, short int depth_limit);
		boardMap[i]=obj.boardMap[i];
	}
	pieceMap[epc_wpawn] = 	obj.pieceMap[epc_wpawn];
	pieceMap[epc_wknight] = obj.pieceMap[epc_knight];
	pieceMap[epc_wbishop] = obj.pieceMap[epc_wbishop];
	pieceMap[epc_wrook] = 	obj.pieceMap[epc_wrook];
	pieceMap[epc_wqueen] = 	obj.pieceMap[epc_wqueen];
	pieceMap[epc_wking] = 	obj.pieceMap[epc_wking];
	pieceMap[epc_bpawn] = 	obj.pieceMap[epc_bpawn];
	pieceMap[epc_bknight] = obj.pieceMap[epc_bknight];
	pieceMap[epc_bbishop] = obj.pieceMap[epc_bbishop];
	pieceMap[epc_brook] = 	obj.pieceMap[epc_brook];
	pieceMap[epc_bqueen] = 	obj.pieceMap[epc_bqueen];
	pieceMap[epc_bking] = 	obj.pieceMap[epc_bking];
}

void ChessBoard::initiate(){
	pieceMap[epc_wpawn] = 	new Pawn(epc_wpawn, this);
	pieceMap[epc_wknight] = new Knight(epc_wknight, this);
	pieceMap[epc_wbishop] = new Bishop(epc_wbishop, this);
	pieceMap[epc_wrook] = 	new Rook(epc_wrook, this);
	pieceMap[epc_wqueen] = 	new Queen(epc_wqueen, this);
	pieceMap[epc_wking] = 	new King(epc_wking, this);
	pieceMap[epc_bpawn] = 	new Pawn(epc_bpawn, this);
	pieceMap[epc_bknight] = new Knight(epc_bknight, this);
	pieceMap[epc_bbishop] = new Bishop(epc_bbishop, this);
	pieceMap[epc_brook] = 	new Rook(epc_brook, this);
	pieceMap[epc_bqueen] = 	new Queen(epc_bqueen, this);
	pieceMap[epc_bking] = 	new King(epc_bking, this);

	boardMap[a1] = epc_brook;
	boardMap[b1] = epc_bknight;
	boardMap[c1] = epc_bbishop;
	boardMap[d1] = epc_bqueen;
	boardMap[e1] = epc_bking;
	boardMap[f1] = epc_bbishop;
	boardMap[g1] = epc_bknight;
	boardMap[f1] = epc_brook;
	boardMap[a8] = epc_wrook;
	boardMap[b8] = epc_wknight;
	boardMap[c8] = epc_wbishop;
	boardMap[d8] = epc_wqueen;
	boardMap[e8] = epc_wking;
	boardMap[f8] = epc_wbishop;
	boardMap[g8] = epc_wknight;
	boardMap[f8] = epc_wrook;
	
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
			}
		}
		cout << "|" << i+1 << endl ;
	}
	cout << " - - - - - - - - " << endl << " a b c d e f g h " << endl;

}

bool checkPiecePosition(string piece, int position){
	return true ;
}

void ChessBoard::movePiece(string piece, int origin, int dest){
	if( this->checkPiecePosition(piece, origin) ){
		if( ! pieceMap[origin]->move(origin, dest) ) messageError();
	}
	else 
		messageError();

}
void ChessBoard::messageError(){
	cout << "Error" << endl;
}

void ChessBoard::removePiece (int position ){
	pieceMap[boardMap[position]]->number --;
}

ChessBoard::~ChessBoard(){
	cout << "end" << endl;
}
