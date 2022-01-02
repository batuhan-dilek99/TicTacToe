#include <stdio.h>
#include <iostream>
#include "PlayGround.h"
#define INFINITY 999



using namespace std;
void print(string a, bool endline){
    if (endline){
        cout << a << " " << endl;

    }
    else{
        cout << a << " ";
    }
};

void print(int a, bool endline){
    if (endline){
        cout << " " << a << " " << endl;

    }
    else{
        cout << " " << a << " ";
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
   for (int row = 0; row<3; row++)
    {
        if (board[row][0]==board[row][1] &&
            board[row][1]==board[row][2])
        {
            if (board[row][0]=="X")
                return +10;
            else if (board[row][0]=="O")
                return -10;
        }
    }
 
    // Checking for Columns
    for (int col = 0; col<3; col++)
    {
        if (board[0][col]==board[1][col] &&
            board[1][col]==board[2][col])
        {
            if (board[0][col]=="X")
                return +10;
 
            else if (board[0][col]=="O")
                return -10;
        }
    }
 
    // Checking for Diagonals
    if (board[0][0]==board[1][1] && board[1][1]==board[2][2])
    {
        if (board[0][0]=="X")
            return +10;
        else if (board[0][0]=="O")
            return -10;
    }
 
    if (board[0][2]==board[1][1] && board[1][1]==board[2][0])
    {
        if (board[0][2]=="X")
            return +10;
        else if (board[0][2]=="O")
            return -10;
    }
 
    // Else if none of them have won then return 0
    return 0;
}
void PlayGround::aiMove(){
    int bestVal = INFINITY;
    int movei,movej;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            // Check if cell is empty
            if (ground[i][j] == "_")
            {
                ground[i][j] = "O";

                //calling minimax for maximizer
                //Because we want to know the score of the other iteration not our inital state. 
                //Our inital state is minimizing and the minimax() should be called for the maximizer
                int moveVal = minimax(ground, 0, true);  
                ground[i][j] = '_';
                
                //Thats why we move if moreVal < bestVal
                //Our initial node should pick the smallest result of the branches of the game tree.
                if (moveVal < bestVal)
                {
                    movei = i;
                    movej = j;
                    bestVal = moveVal;
                }
            }
        }
    }
    ground[movei][movej] = "O";
    printGround();
}

int PlayGround::minimax(string board[3][3], int depth, bool isMaximizer){
    int score = checkWinner(board);

    if (score == 10){
        return score;
    }
 
    if (score == -10){
        return score;
    }
    
    if (isMoveLeft()==false){
        return 0;
    }
    
    if (isMaximizer)
    {
        int best = -INFINITY;
 
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j] == "_")
                {
                    board[i][j] = "X";
                    best = max(best, minimax(board, depth+1, !isMaximizer) );
                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
    else
    {
        int best = INFINITY;
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                if (board[i][j] =="_")
                {
                    board[i][j] = "O";
                    best = min(best, minimax(board, depth+1, !isMaximizer));
                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
}
