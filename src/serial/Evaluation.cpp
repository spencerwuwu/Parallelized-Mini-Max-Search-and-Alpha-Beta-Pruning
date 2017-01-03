#include <iostream>
#include <cstring>

using namespace std;

#include "ChessBoard.hpp"


PieceTable::PieceTable(){

	int score_pawn[64]  =   {
		0,   0,   0,   0,   0,   0,   0,   0,
		50,  50,  50,  50,  50,  50,  50,  50,
		10,  10,  20,  30,  30,  20,  10,  10,
		5,   5,  10,  25,  25,  10,   5,   5,
		0,   0,   0,  20,  20,   0,   0,   0,
		5,  -5, -10,   0,   0, -10,  -5,   5,
		5,  10,  10, -20, -20,  10,  10,   5,
		0,   0,   0,   0,   0,   0,   0,   0  
	};
	int score_off[64]	=	{
		0,   0,   0,   0,   0,   0,   0,   0,
		50,  50,  50,  50,  50,  50,  50,  50,
		10,  10,  20,  30,  30,  20,  10,  10,
		5,   5,  10,  25,  25,  10,   5,   5,
		0,   0,   0,  20,  20,   0,   0,   0,
		5,  -5, -10,   0,   0, -10,  -5,   5,
		5,  10,  10, -20, -20,  10,  10,   5,
		0,   0,   0,   0,   0,   0,   0,   0  
	};
	int score_knight[64]	=	{
		-50, -40, -30, -30, -30, -30, -40, -50,
		-40, -20,   0,   0,   0,   0, -20, -40,
		-30,   0,  10,  15,  15,  10,   0, -30,
		-30,   5,  15,  20,  20,  15,   0, -30,
		-30,   0,  15,  20,  20,  15,   0, -30,
		-30,   5,  10,  15,  15,  10,   5, -30,
		-40, -20,   0,   5,   5,   0, -20, -40,
		-50, -40, -30, -30, -30, -30, -40, -50
	};
	int score_bishop[64]	=	{
		-20, -10, -10, -10, -10, -10, -10, -20,
		-10,   0,   0,   0,   0,   0,   0, -10,
		-10,   0,   5,  10,  10,   5,   0, -10,
		-10,   5,   5,  10,  10,   5,   5, -10,
		-10,   0,  10,  10,  10,  10,   0, -10,
		-10,  10,  10,  10,  10,  10,  10, -10,
		-10,   5,   0,   0,   0,   0,   5, -10,
		-20, -10, -10, -10, -10, -10, -10, -20
	};
	int score_rook[64]	=	{
		0,   0,   0,   0,   0,   0,   0,   0,
		5,  10,  10,  10,  10,  10,  10,   5,
		-5,   0,   0,   0,   0,   0,   0,  -5,
		-5,   0,   0,   0,   0,   0,   0,  -5,
		-5,   0,   0,   0,   0,   0,   0,  -5,
		-5,   0,   0,   0,   0,   0,   0,  -5,
		-5,   0,   0,   0,   0,   0,   0,  -5,
		0,   0,   0,   5,   5,   0,   0,   0
	};
	int score_queen[64]	=	{
		-20, -10, -10,  -5,  -5, -10, -10, -20,
		-10,   0,   0,   0,   0,   0,   0, -10,
		-10,   0,   5,   5,   5,   5,   0, -10,
		-5,   0,   5,   5,   5,   5,   0,  -5,
		0,   0,   5,   5,   5,   5,   0,  -0,
		-10,   5,   5,   5,   5,   5,   0, -10,
		-10,   0,   5,   0,   0,   0,   0, -10,
		-20, -10, -10,  -5,  -5, -10, -10, -20	
	};
	//king middle game
	int score_king[64]	=	{
		-30, -40, -40, -50, -50, -40, -40, -30,
		-30, -40, -40, -50, -50, -40, -40, -30,
		-30, -40, -40, -50, -50, -40, -40, -30,
		-30, -40, -40, -50, -50, -40, -40, -30,
		-20, -30, -30, -40, -40, -30, -30, -20,
		-10, -20, -20, -20, -20, -20, -20, -10,
		20,  20,   0,   0,   0,   0,  20,  20,
		20,  30,  10,   0,   0,  10,  30,  20
	};

    memset((void *)score[epc_empty], 0, sizeof(int)*64);
    memset((void *)score[epc_blacky], 0, sizeof(int)*64);
    for(int i=0; i<64; i++){
        // value of white
        score[epc_wpawn][i]   = -score_pawn[i];
        score[epc_woff][i]    = -score_off[i];
        score[epc_wknight][i] = -score_knight[i];
        score[epc_wbishop][i] = -score_bishop[i];
        score[epc_wrook][i]   = -score_rook[i];
        score[epc_wqueen][i]  = -score_queen[i];
        score[epc_wking][i]   = -score_king[i];

        // value of black
        score[epc_bpawn][i]   = score_pawn[i];
        score[epc_boff][i]    = score_off[i];
        score[epc_bknight][i] = score_knight[i];
        score[epc_bbishop][i] = score_bishop[i];
        score[epc_brook][i]   = score_rook[i];
        score[epc_bqueen][i]  = score_queen[i];
        score[epc_bking][i]   = score_king[i];
    }
}

PieceTable::~PieceTable(){
    // free memory ?
}

// temporarily declared here, maybe change to the other place but not in ChessBoard::eval, 
// for the reason that we only need to create the table once in the bigin.
PieceTable myscore;

int ChessBoard::eval(int color){
	// color: white 0 negative, black 1 positive
    int eval=0;
	for(int i = 0 ; i < 64 ; i++){
		eval += myscore.score[boardMap[i]][i];
	}
    /*
	if ( color == 0 ){
		eval = -eval;
	}
    */
	return eval;
}
