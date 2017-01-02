#include <iostream>

#include "ChessBoard.hpp"
#include "Search.hpp"

using namespace std;

int parse(char a, char b){
	int rank = 0;
	int file = 0;
	char in[2];
	in[0] = a;
	in[1] = b;
	switch(in[0]){
		case 'a':	file=0;
					break;
		case 'b':	file=1;
					break;
		case 'c':	file=2;
					break;
		case 'd':	file=3;
					break;
		case 'e':	file=4;
					break;
		case 'f':	file=5;
					break;
		case 'g':	file=6;
					break;
		case 'h':	file=7;
					break;
		default	:	file=-1;
					break;
	}

	switch(in[1]){
		case '1':	rank=0;
					break;
		case '2':	rank=1;
					break;
		case '3':	rank=2;
					break;
		case '4':	rank=3;
					break;
		case '5':	rank=4;
					break;
		case '6':	rank=5;
					break;
		case '7':	rank=6;
					break;
		case '8':	rank=7;
					break;
		default	:	rank=-1;
					break;
	}

	return rank*8+file;
}

int main(){
	cout << "Start" << endl;
	ChessBoard* myboard = new ChessBoard();
	ChessBoard* tmp = new ChessBoard();

	myboard->print();

	cout  << endl << "input: piece origin destination"<< endl;

	string in0,in1,in2;
	char piece;
	int origin;
	int dest;

	myboard->turn = 0;

	while(1){
		myboard->showTurn();

		// input parser
		cin >> in0 >> in1 >> in2;
		piece	= in0[0];
		origin	= parse( in1[0], in1[1]);
		dest	= parse( in2[0], in2[1]);

		while( origin < 0 || dest < 0 || origin > 63 || dest > 63){
			cout << "Input error" << endl;
			// input parser
			cin >> in0 >> in1 >> in2;
			piece	= in0[0];
			origin	= parse( in1[0], in1[1]);
			dest	= parse( in2[0], in2[1]);
		}

		while ( !myboard->movePiece(piece, origin, dest) ){
			cout << "try again" << endl;
			//
			// input parser
			cin >> in0 >> in1 >> in2;
			piece	= in0[0];
			origin	= parse( in1[0], in1[1]);
			dest	= parse( in2[0], in2[1]);

			while( origin < 0 || dest < 0 ){
				cout << "Input error" << endl;
				// input parser
				cin >> in0 >> in1 >> in2;
				piece	= in0[0];
				origin	= parse( in1[0], in1[1]);
				dest	= parse( in2[0], in2[1]);
			}

		}

		cout << "==============================" << endl;

		myboard->print();

		tmp = MinMax( myboard, 4);
		myboard = tmp;
	}

	return 0;

}


