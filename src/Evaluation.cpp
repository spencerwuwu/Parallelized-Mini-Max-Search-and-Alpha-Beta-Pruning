#include <iostream>
#include <cstring>

using namespace std;

#include "ChessBoard.hpp"
int t = 0;
PieceTable::PieceTable(int tag){

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
	// king end game
	int score_king_end[64] = {
		-50,-40,-30,-20,-20,-30,-40,-50,
		-30,-20,-10,  0,  0,-10,-20,-30,
		-30,-10, 20, 30, 30, 20,-10,-30,
		-30,-10, 30, 40, 40, 30,-10,-30,
		-30,-10, 30, 40, 40, 30,-10,-30,
		-30,-10, 20, 30, 30, 20,-10,-30,
		-30,-30,  0,  0,  0,  0,-30,-30,
		-50,-30,-30,-30,-30,-30,-30,-50
	};

    memset((void *)score[epc_empty], 0, sizeof(int)*64);
    memset((void *)score[epc_blacky], 0, sizeof(int)*64);
    for(int i=0; i<64; i++){
        // value of white
        score[epc_bpawn][i]   = score_pawn[63 - i];
        score[epc_boff][i]    = score_off[63 - i];
        score[epc_bknight][i] = score_knight[63 - i];
        score[epc_bbishop][i] = score_bishop[63 - i];
        score[epc_brook][i]   = score_rook[63 - i];
        score[epc_bqueen][i]  = score_queen[63 - i];
		if(tag == 0)
			score[epc_bking][i]   = score_king[63 - i];
		else if(tag == 1)
			score[epc_bking][i]   = score_king_end[63 - i];

        // value of black
        score[epc_wpawn][i]   = score_pawn[i];
        score[epc_woff][i]    = score_off[i];
        score[epc_wknight][i] = score_knight[i];
        score[epc_wbishop][i] = score_bishop[i];
        score[epc_wrook][i]   = score_rook[i];
        score[epc_wqueen][i]  = score_queen[i];
		if(tag == 0)
			score[epc_wking][i]   = score_king[i];
		else if(tag == 1)
			score[epc_wking][i]   = score_king_end[i];
    }
}

PieceTable::~PieceTable(){
    // free memory ?
}

// temporarily declared here, maybe change to the other place but not in ChessBoard::eval, 
// for the reason that we only need to create the table once in the bigin.

int ChessBoard::eval(int color){
	// color: white 0 negative, black 1 positive
    int eval=0;
	int queen = 0;
	PieceTable myscore(t);
	for(int i = 0 ; i < 64 ; i++){
		if(boardMap[i] >= color * 10 && boardMap[i] <= color * 10 + 7){
			eval += myscore.score[boardMap[i]][i];
		}else {
			if(boardMap[i] == epc_wpawn || boardMap[i] == epc_bpawn){
				eval -= 100;
			}else if(boardMap[i] == epc_wknight || boardMap[i] == epc_bknight){
				eval -= 320;
			}else if(boardMap[i] == epc_wbishop || boardMap[i] == epc_bbishop){
				eval -= 330;
			}else if(boardMap[i] == epc_wrook || boardMap[i] == epc_brook){
				eval -= 500;
			}else if(boardMap[i] == epc_wqueen || boardMap[i] == epc_bqueen){
				eval -= 900;
			}else if(boardMap[i] == epc_wking || boardMap[i] == epc_bking){
				eval -= 20000;
			}
			
		}
		if(t == 0){
			if(boardMap[i] == epc_wqueen || boardMap[i] == epc_bqueen){
				queen++;
			}
		}
	}
	if(queen == 0 && t == 0){// change to king end game
		t = 1;
	}

	// check
	if ( color == BLACK ){
		if ( pieceNum[epc_bking] == 0 ){
			eval -= 100000;
		}
	}
	else {
		if ( pieceNum[epc_wking] == 0 ){
			eval += 100000;
		}
	}


	return eval;
}

