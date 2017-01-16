GLIB=$(shell pkg-config --cflags --libs glib-2.0)

all: build

build: 
	g++ ChessBoard.cpp ChessPiece.cpp Evaluation.cpp Search.cpp PVSplit.cpp ABSearch.cpp ChessMain.cpp -Wall -O1  -g $(GLIB) -o chess.out
	
clean:
	rm chess.out -f
