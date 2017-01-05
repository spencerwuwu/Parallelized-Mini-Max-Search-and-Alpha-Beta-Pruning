all: build

build: 
	g++ ChessBoard.cpp ChessPiece.cpp Evaluation.cpp Search.cpp PVSplit.cpp ABSearch.cpp ChessMain.cpp -Wall -g -lpthread -o chess.out
	g++ ChessBoard.cpp ChessPiece.cpp Evaluation.cpp Search.cpp PVSplit.cpp ABSearch.cpp ChessMainAuto.cpp -Wall -g -lpthread -o Auto.out

clean:
	rm chess.out -f
