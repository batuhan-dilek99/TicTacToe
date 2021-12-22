#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include <iostream>
#include "human.h"
#include "ai.h"
using namespace std;



struct Move{
    int x;
    int y;
}typedef mov;

class PlayGround{
private:
public:

    const string human = "O";
    const string ai = "X";
    string ground[3][3];

    PlayGround();
    void aiMove();
    void humanMove(int row, int col);
    void printGround();
    bool isMovePossible(int row, int col);
    bool isMoveLeft();
    int checkWinner();
    int minimax(string board[3][3], int depth, bool isMaximizer);


    
};

#endif
