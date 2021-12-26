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
 
    // Checking for Columns for X or O victory.
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
 
    // Checking for Diagonals for X or O victory.
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
    int bestVal = -1000;
    int movei,movej;
 
    // Traverse all cells, evaluate minimax function for
    // all empty cells. And return the cell with optimal
    // value.
    for (int i = 0; i<3; i++)
    {
        for (int j = 0; j<3; j++)
        {
            // Check if cell is empty
            if (ground[i][j] == "_")
            {
                // Make the move
                ground[i][j] = "O";
 
                // compute evaluation function for this
                // move.
                int moveVal = minimax(ground, 0, false);
 
                // Undo the move
                ground[i][j] = '_';
 
                // If the value of the current move is
                // more than the best value, then update
                // best/
                if (moveVal > bestVal)
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
 
    // If Maximizer has won the game return his/her
    // evaluated score
    if (score == 10)
        return score;
 
    // If Minimizer has won the game return his/her
    // evaluated score
    if (score == -10)
        return score;
 
    // If there are no more moves and no winner then
    // it is a tie
    if (isMoveLeft()==false)
        return 0;
 
    // If this maximizer's move
    if (isMaximizer)
    {
        int best = -1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j] == "_")
                {
                    // Make the move
                    board[i][j] = "X";
 
                    // Call minimax recursively and choose
                    // the maximum value
                    best = max( best,
                        minimax(board, depth+1, !isMaximizer) );
 
                    // Undo the move
                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
 
    // If this minimizer's move
    else
    {
        int best = 1000;
 
        // Traverse all cells
        for (int i = 0; i<3; i++)
        {
            for (int j = 0; j<3; j++)
            {
                // Check if cell is empty
                if (board[i][j] =="_")
                {
                    // Make the move
                    board[i][j] = "O";
 
                    // Call minimax recursively and choose
                    // the minimum value
                    best = min(best,
                           minimax(board, depth+1, !isMaximizer));
 
                    // Undo the move
                    board[i][j] = "_";
                }
            }
        }
        return best;
    }
}
