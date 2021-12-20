#ifndef PLAYGROUND_H
#define PLAYGROUND_H
#include <iostream>
using namespace std;


class PlayGround{
private:
public:
    string ground[3][3];
    string winner;
    PlayGround();
    void aiMove(int row, int col);
    void humanMove(int row, int col);
    void printGround();
    bool isMovePossible(int row, int col);
    string setWinner();


    
};

#endif
