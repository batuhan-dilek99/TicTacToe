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

int PlayGround::checkWinner(string board[3][3]){
    string winner = "";
    for (int i = 0; i < 3; i++){      //Horizontal checking
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            winner = board[i][0];
            if(winner == "X"){
                return 10;
            }
            else if(winner == "O"){
                return -10;
            }
        }
    }


    for (int i = 0; i < 3; i++){      //Vertical checking
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            winner = board[0][i];
            if(winner == "X"){
                return 10;
            }
            else if(winner == "O"){
                return -10;
            }
        }
    } 

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        winner = board[0][0];
        if(winner == "X"){
            return 10;
        }
        else if(winner == "O"){
            return -10;
        }
        
    }
    else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        winner = board[0][2];
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
    int score = checkWinner(ground);    //this variable checks whether the game is still running or the game has stopped
    int movei, movej;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if (ground[i][j] == "_"){   //is the spot available
                ground[i][j] = "O";
                newScore = minimax(ground, 0, true);  
                ground[i][j] = "_";
                if (newScore > bestScore){ 
                    bestScore = newScore;
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
    int score = checkWinner(board);
    int newScore, bestScore;
    if (score == +10){
        return score;
    }
    else if(score == -10){
        return score;
    }
    if(!isMoveLeft()){
        return 0;
    }

    if(isMaximizer){
        bestScore = -INFINITY;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if (board[i][j] == "_"){   //is the spot available
                    board[i][j] = "X";   
                    newScore = minimax(board, depth + 1, false); 
                    board[i][j] = "_";
                    bestScore = max(bestScore, newScore);  // comparing the new minimax result and the best score
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
                    board[i][j] = "O";   
                    newScore = minimax(board, depth + 1, true);
                    board[i][j] = "_";
                    bestScore = min(bestScore, newScore);
                }
            }
        }
        return bestScore;
    }
}
