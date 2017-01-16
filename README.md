# Parallelized Mini-Max Search and Alpha-Beta Pruning
## with Terminal Chess
This is a comparsion between the performance of **parrallelized apha-beta search**, **normal apha-beta search**, and **Mini-max search**.

Run ```make clean``` then ```make``` to compile.

To start the game:
```bash
./chess -m | -a | -p  [depth]  [thread num]

[USAGE]
        -m    Mini-max Search
        -a    Alpha-beta Search
        -p    Parrallel Alpha-beta Search
        
        [depth]:        the depth of the search. Default: 4
        [thread num]:   The number of the thread created. Default: 4
```
After start, you'll see something like:
```bash
Start
 - - - - - - - - 
|r|k|b|q|c|b|k|r|  1
|p|p|p|p|p|p|p|p|  2
| | | | | | | | |  3
| | | | | | | | |  4
| | | | | | | | |  5
| | | | | | | | |  6
|P|P|P|P|P|P|P|P|  7
|R|K|B|Q|C|B|K|R|  8
 - - - - - - - - 
 a b c d e f g h 

input: piece origin destination
White's turn
```
Capital letters are white's pieces. Use ```piece origin destination``` to move a piece. For example:
```
P d7 d5
```
The board becomes
```
 - - - - - - - - 
|r|k|b|q|c|b|k|r|  1
|p|p|p|p|p|p|p|p|  2
| | | | | | | | |  3
| | | | | | | | |  4
| | | |P| | | | |  5
| | | | | | | | |  6
|P|P|P| |P|P|P|P|  7
|R|K|B|Q|C|B|K|R|  8
 - - - - - - - - 
 a b c d e f g h 
 ```
Castling and pawn promotion are not avaliable yet. And player can only be white for now. Feel free to contribute. 


This is the final project of NCTU 2016 fall Parallel Programming

Instsructor: <a href="https://people.cs.nctu.edu.tw/~ypyou/">Yi-Ping You 游逸平</a>
