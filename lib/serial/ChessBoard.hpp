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


class ChessBoard {
	private:
		int boardMap[64]; 
		map<int,*Pieces> pieceMap;
		void initiate	();

	public:
	ChessBoard			();
	void	resetBoard	();
	void	messageError();

	//value obtain
	bool 	checkPiecePosition(string piece, int position);

	// Piece function
	void 	movePiece	(int origin, int dest);
	~ChessBoard			();
};

class Piece {
	friend class ChessBoard;

	protected:
		int number;
		int color;
		ChessBoard *chboard;	
	public:
		virtual bool move(int orgin, int dest);
		virtual void remove(int position);
		void messageError();
};

class King : public Piece {
	private:
	public:
		King() {}
		King(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=1;	
		}
		virtual bool move(int orgin, int dest);
		~King() {}
};
class Queen : public Piece {
	private:
	public:
		Queen() {}
		Queen(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=1;	
		}
		~Queen() {}
};
class Bishop : public Piece {
	private:
	public:
		Bishop() {}
		Bishop(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=2;
		}
		~Bishop() {}
};
class Knight : public Piece {
	private:
	public:
		Knight() {}
		Knight(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=2;
		}
		~Knight() {}
};
class Rook : public Piece {
	private:
	public:
		Rook() {}
		Rook(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=2;
		}
		~Rook() {}
};
class Pawn : public Piece {
	private:
	public:
		Pawn() {}
		Pawn(int c, ChessBoard* board) {
			if ( c >= epc_boff){
				color = BLACK;
			}
			else color = WHITE;
			chboard=board;
			number=8;
		}
		~Pawn() {}
};
