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

int PlayGround::checkWinner(){
    string winner = "";
    int result;
    for (int i = 0; i < 3; i++){      //Horizontal checking
        if (ground[i][0] == ground[i][1] && ground[i][0] == ground[i][2]){
            winner = ground[i][0];
            if(winner == "X"){
                return 1;
            }
            else if(winner == "O"){
                return -1;
            }
            else{
                return 2;
            }
        }
    }

    for (int i = 0; i < 3; i++){      //Vertical checking
        if (ground[0][i] == ground[1][i] && ground[0][i] == ground[2][i]){
            winner = ground[0][i];
            if(winner == "X"){
                return 1;
            }
            else if(winner == "O"){
                return -1;
            }
            else{
                return 2;
            }
        }
    } 

    if (ground[0][0] == ground[1][1] && ground[0][0] == ground[2][2]){
        winner = ground[0][0];
        if(winner == "X"){
                return 1;
            }
            else if(winner == "O"){
                return -1;
            }
            else{
                return 2;
            }
    }
    else if (ground[2][0] == ground[1][1] && ground[2][0] == ground[0][2]){
        winner = ground[2][0];
        if(winner == "X"){
                return 1;
            }
            else if(winner == "O"){
                return -1;
            }
            else{
                return 2;
            }
    }

}
void PlayGround::aiMove(){
    int bestScore = -INFINITY;
    int newScore;
    int score;
    int movei, movej;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (this->ground[i][j] == "_"){   //is the spot available
                this->ground[i][j] == "O";
                newScore = minimax(this, 0, false);
                this->ground[i][j] == "_";
                if (score > bestScore){
                    bestScore = score;
                    movei = i;
                    movej = j;

                }
            }
        }
    }
    this->ground[movei][movej] = "O";
};

int PlayGround::minimax(PlayGround* playground, int depth, bool isMaximizer){
    int score = checkWinner();
    int newScore;
    if(score != 2){
        return score;
    }

    if(isMaximizer){
        int bestScore = -INFINITY;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (playground->ground[i][j] == "_"){   //is the spot available
                    playground->ground[i][j] == "O";
                    newScore = minimax(this, depth + 1, false);
                    playground->ground[i][j] == "_";
                    if (score > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
    }
    else{
        int bestScore = INFINITY;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (playground->ground[i][j] == "_"){   //is the spot available
                    playground->ground[i][j] == "X";
                    newScore = minimax(this, depth + 1, true);
                    playground->ground[i][j] == "_";
                    if (score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
    }

    

}
