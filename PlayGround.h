#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include <iostream>
#include "human.h"
#include "ai.h"
using namespace std;


class PlayGround{
private:
public:
    enum scores{
        X = 1,
        tie = 0,
        O = -1
    };
    string ground[3][3];
    //string winner;
    PlayerAI ai;
    PlayerHuman human;

    PlayGround();
    void aiMove();
    void humanMove(int row, int col);
    void printGround();
    bool isMovePossible(int row, int col);
    int checkWinner();
    int minimax(PlayGround* playground, int depth, bool isMaximizer);


    
};

#endif
