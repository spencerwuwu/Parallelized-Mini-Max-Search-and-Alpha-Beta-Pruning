#include <iostream>
#include <cstdio>
#include <cstring>
#include "ChessBoard.hpp"
#include "Search.hpp"
#include "ABSearch.hpp"
#include "PVSplit.hpp"
#include <time.h>
#include <fstream>

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

int main(int argc, char *argv[])
{
    int type = 0;
    string in0,in1,in2;
    char piece;
    int origin;
    int dest;
    clock_t begin, end;

    ofstream time_out("time.txt");
    ofstream move_out("move.txt");

    ChessBoard* myboard = new ChessBoard();
    ChessBoard* tmp = new ChessBoard();


    cout << "Start" << endl;
    if ( argc > 1 ){
        if ( argv[1][1] == 'p' ){
            cout << "Parallel Minimax" << endl;
            type = 1;
        } else if ( argv[1][1] == 'a' ){
            cout << "Alpha-beta Search" << endl;
            type = 2;
        } else if ( argv[1][1] == 'm' ){
            cout << "Mini-Max Search" << endl;
        }
    }

    int dept_limit = 4;
    if (argc > 2) {
        sscanf(argv[2], "%d", &dept_limit);
    }
	cout << "dept" << dept_limit << endl;

    myboard->print();

    cout  << endl << "input: piece origin destination"<< endl;


    myboard->turn = 0;

    // Alpha-Beta Search
    while (1) {
        if ( myboard->pieceNum[epc_bking] == 0 ){
            cout << "White win!! " << endl << "=======================================";
            cout << endl << "+++++++++++++++++++++++++++++++++++++++" << endl;
            break;
        }
        cout << "White's turn" << endl;
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

        while ( !myboard->movePiece(piece, origin, dest, 0) ){
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

        move_out << in0 << " " << in1 << " " << in2 << endl;
        cout << "==============================" << endl;

        myboard->print();
        myboard->turn = BLACK;
        cout << "Black's turn" << endl;

        //timing
        begin = clock();
        switch (type) {
            case 1:
                tmp = PVMinMax( myboard, dept_limit);
                break;
            case 2:
                tmp = ABMinMax( myboard, dept_limit);
                break;
            case 0:
            default:
                tmp = MinMax( myboard, dept_limit);
                break;
        }
        end = clock();
        //timing

        delete myboard;
        myboard = tmp;

        cout << "++++++++++++++++++++++++++++++" << endl;
        cout << "time: " << (double)(end - begin)/CLOCKS_PER_SEC << endl;
        cout << "++++++++++++++++++++++++++++++" << endl;

        time_out << (double)(end - begin)/CLOCKS_PER_SEC << endl;

        myboard->print();

        if ( myboard->pieceNum[epc_wking] == 0 ){
            cout << "Black win!! " << endl << "=======================================";
            cout << endl << "+++++++++++++++++++++++++++++++++++++++" << endl;
            break;
        }
        else if( myboard->pieceNum[epc_bking] == 0 ){
            cout << "White win!! " << endl << "=======================================";
            cout << endl << "+++++++++++++++++++++++++++++++++++++++" << endl;
            break;
        }
    }

    return 0;

}


