#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include<iostream>
#include<map>
#include<string>
#include<vector> 


using namespace std;

typedef unsigned long long  U64;

#define WHITE 0
#define BLACK 1

enum enumSquare{
	a1, b1, c1, d1, e1, f1, g1, h1,
	a2, b2, c2, d2, e2, f2, g2, h2,
	a3, b3, c3, d3, e3, f3, g3, h3,
	a4, b4, c4, d4, e4, f4, g4, h4,
	a5, b5, c5, d5, e5, f5, g5, h5,
	a6, b6, c6, d6, e6, f6, g6, h6,
	a7, b7, c7, d7, e7, f7, g7, h7,
	a8, b8, c8, d8, e8, f8, g8, h8
};
enum EPieceType
{
	ept_pnil   = 0, // empty
	ept_wpawn  = 1,
	ept_bpawn  = 2,
	ept_knight = 3,
	ept_bishop = 4,
	ept_rook   = 5,
	ept_queen  = 6,
	ept_king   = 7,
};
enum EPieceCode
{
	epc_empty   = ept_pnil,
	epc_wpawn   = ept_wpawn,
	epc_woff    = ept_bpawn, // may be used as off the board blocker in mailbox
	epc_wknight = ept_knight,
	epc_wbishop = ept_bishop,
	epc_wrook   = ept_rook,
	epc_wqueen  = ept_queen,
	epc_wking   = ept_king,

	epc_blacky  = 8, // color code, may used as off the board blocker in mailbox
	epc_boff    = ept_wpawn  + epc_blacky, // may be used as off the board blocker in mailbox
	epc_bpawn   = ept_bpawn  + epc_blacky,
	epc_bknight = ept_knight + epc_blacky,
	epc_bbishop = ept_bishop + epc_blacky,
	epc_brook   = ept_rook   + epc_blacky,
	epc_bqueen  = ept_queen  + epc_blacky,
	epc_bking   = ept_king   + epc_blacky,
};

class ChessBoard; 
class Piece;
class PieceTable;

class ChessBoard {

	public:
		int boardMap[64]; 
		map<int,Piece*> pieceMap;
		int pieceNum[15];
		int turn;


		void initiate	();


		ChessBoard			();
		void 	print		();
		void	resetBoard	();
		void	messageError();
		void	showTurn	();
		int		getTurn		();


		vector<ChessBoard*> listAllMove(int turn);

		int getNum(int chess) const{
			return pieceNum[chess];
		}

		ChessBoard			(const ChessBoard &obj );


	friend class Piece;

	// value obtain
	bool 	checkPiecePosition(string piece, int position);

	// Piece function
	bool 	movePiece	(char piece, int origin, int dest);
	int 	eval		(int score);
	void	removePiece	(int position);
	~ChessBoard			();
};

class PieceTable{
	public:
		int score[8][64];
		PieceTable();
		~PieceTable();
};

class Piece {
	friend class ChessBoard;

	protected:
	public:
		int			color;

		virtual bool checkmove(int orgin, int dest, int* myboard){
		};
		void messageError();

		int getcol() const{
			return color;
		}

		Piece		(){
			color=0;
		}
		Piece		(const Piece &obj);
		~Piece		();
};

class King : public Piece {
	private:
	public:
		King() {
			color=0;
		}
		King(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~King() {}
};
class Queen : public Piece {
	private:
	public:
		Queen() {
			color=0;
		}
		Queen(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~Queen() {}
};
class Bishop : public Piece {
	private:
	public:
		Bishop() {
			color=0;
		}
		Bishop(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~Bishop() {}
};
class Knight : public Piece {
	private:
	public:
		Knight() {
			color=0;
		}
		Knight(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~Knight() {}
};
class Rook : public Piece {
	private:
	public:
		Rook() {
			color=0;
		}
		Rook(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~Rook() {}
};
class Pawn : public Piece {
	private:
	public:
		Pawn() {
			color=0;
		}
		Pawn(int c) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
		}
		virtual bool checkmove(int orgin, int dest, int* myboard);
		~Pawn() {}
};
#endif
