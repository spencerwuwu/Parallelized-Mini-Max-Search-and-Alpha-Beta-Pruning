#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#include <ChessBoard.hpp>


ChessBoard::ChessBoard(){
	initiate();
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
	boardMap[e8] = epc_wbking;
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

bool checkPiecePosition(string piece, int position){
	return true ;
}

void ChessBoard::movePiece(string piece, int origin, int dest){
	if( checkPiecePosition(piece, origin) ){
		if( ! pieceMap[origin]->move(origin, dest) ) messageError();
	}
	else 
		messageError();

}

void ChessBoard::removePiece (int position ){
	pieceMap[boardMap[position]]->number --;
}

