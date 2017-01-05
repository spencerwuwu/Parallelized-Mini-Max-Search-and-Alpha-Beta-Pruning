all: build

build: 
	g++ ChessBoard.cpp ChessPiece.cpp Evaluation.cpp Search.cpp PVSplit.cpp ABSearch.cpp ChessMain.cpp -Wall -g -lpthread -o chess.out

clean:
	rm chess.out -f
