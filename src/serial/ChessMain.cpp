#include <iostream>

#include "ChessBoard.hpp"

using namespace std;

int main(){
	cout << "Start" << endl;
	ChessBoard myboard;

	myboard.print();

	cout  << endl << "input: piece origin destination"<< endl;

	char piece;
	int origin;
	int dest;

	myboard.turn = 0;
	//cout << myboard.pieceMap[myboard.boardMap[51]]->color << endl;
	while(1){
		myboard.showTurn();

		cin >> piece >> origin >> dest;
		while ( !myboard.movePiece(piece, origin, dest) ){
			cout << "try again" << endl;
			cin >> piece >> origin >> dest;
		}

		myboard.print();

	}

	return 0;

}
