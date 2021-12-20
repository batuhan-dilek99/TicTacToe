#include <stdio.h>
#include <iostream>
#include "PlayGround.h"



using namespace std;
void print(string a, bool endline){
    if (endline){
        cout << a << endl;

    }
    else{
        cout << a;
    }
};

PlayGround::PlayGround(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            this->ground[i][j] = "_";
        }
    }
};
void PlayGround::aiMove(int row, int col){
    if (isMovePossible(row, col)){
        this->ground[row - 1][col - 1] = "O";
        this->printGround();
    }
    else{
        print("The position is not empty", true);

    }
};
void PlayGround::humanMove(int row, int col){
    if (isMovePossible(row, col)){
        this->ground[row - 1][col - 1] = "X";
        this->printGround();
    }
    else{
        print("The position is not empty", true);
        print("row col : ", false);
        cin >> row >> col;
        humanMove(row, col);
    }
};
void PlayGround::printGround(){
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << this->ground[i][j] << " ";
        }
        cout << endl;
    }
};

bool PlayGround::isMovePossible(int row, int col){
    if (this->ground[row - 1][col - 1] == "_"){
        return true;
    }
    else{
        return false;
    }
};

string PlayGround::setWinner(){
    winner = "";
    for (int i = 0; i < 3; i++){      //Horizontal checking
        if (ground[i][0] == ground[i][1] && ground[i][0] == ground[i][2]){
            winner = ground[i][0];
            return winner;
        }
    }

    for (int i = 0; i < 3; i++){      //Vertical checking
        if (ground[0][i] == ground[1][i] && ground[0][i] == ground[2][i]){
            winner = ground[0][i];
            return winner;
        }
    } 

    if (ground[0][0] == ground[1][1] && ground[0][0] == ground[2][2]){
        winner = ground[0][0];
        return winner;
    }
    else if (ground[2][0] == ground[1][1] && ground[2][0] == ground[0[2]){
        winner = ground[2][0];
        return winner;
    }

}
