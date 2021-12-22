#include <stdio.h>
#include <iostream>
#include "PlayGround.h"
#define INFINITY 999



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
        puts("");
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

bool PlayGround::isMoveLeft(){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (ground[i][j] == "_"){
                return true;
            }
        }
    }
    return false;
};

int PlayGround::checkWinner(){
    string winner = "";
    int result;
    for (int i = 0; i < 3; i++){      //Horizontal checking
        if (ground[i][0] == ground[i][1] && ground[i][0] == ground[i][2]){
            winner = ground[i][0];
            if(winner == "X"){
                return 10;
            }
            else if(winner == "O"){
                return -10;
            }
        }
    }


    for (int i = 0; i < 3; i++){      //Vertical checking
        if (ground[0][i] == ground[1][i] && ground[0][i] == ground[2][i]){
            winner = ground[0][i];
            if(winner == "X"){
                return 10;
            }
            else if(winner == "O"){
                return -10;
            }
        }
    } 

    if (ground[0][0] == ground[1][1] && ground[0][0] == ground[2][2]){
        winner = ground[0][0];
        if(winner == "X"){
            return 10;
        }
        else if(winner == "O"){
            return -10;
        }
        
    }
    else if (ground[2][0] == ground[1][1] && ground[2][0] == ground[0][2]){
        winner = ground[2][0];
        if(winner == "X"){
            return 10;
        }
        else if(winner == "O"){
            return -10;
        }
    }

    return 0;
}
void PlayGround::aiMove(){
    int bestScore = -INFINITY;
    int newScore;
    int score = checkWinner();
    int movei, movej;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (ground[i][j] == "_"){   //is the spot available
                ground[i][j] = "O";
                newScore = minimax(ground, 0, false);  //Olmaz ise false yap
                ground[i][j] = "_";
                if (score > bestScore){
                    bestScore = score;
                    movei = i;
                    movej = j;

                }
            }
        }
    }
    this->ground[movei][movej] = "O";
    this->printGround();
};

int PlayGround::minimax(string board[3][3], int depth, bool isMaximizer){
    int score = checkWinner();
    int newScore, bestScore;
    if (score == +10){
        return score;
    }
    else if(score == -10){
        return score;
    }
    if(isMoveLeft()){
        return score;
    }

    if(isMaximizer){
        bestScore = -INFINITY;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (board[i][j] == "_"){   //is the spot available
                    board[i][j] = "O";
                    newScore = minimax(board, depth + 1, false); 
                    board[i][j] = "_";
                    bestScore = max(score, newScore);
                }
            }
        }
        return bestScore;
    }
    else{
        bestScore = INFINITY;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (board[i][j] == "_"){   //is the spot available
                    board[i][j] = "X";
                    newScore = minimax(board, depth + 1, true);
                    board[i][j] = "_";
                    bestScore = min(score, newScore);
                }
            }
        }
        return bestScore;
    }
}
