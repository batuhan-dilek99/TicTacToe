#include <iostream>
#
#include "PlayGround.cpp"


using namespace std;


int main(void){

    //PlayGround* a = new PlayGround();
    PlayGround a;
    int row, col;
    int b = a.checkWinner();
    a.printGround();
    while(b == 0){
        print("Enter your move (row, col) : ", false);
        cin >> row >> col;
        a.humanMove(row, col);
        a.aiMove();
        puts("");
        b = a.checkWinner();
    }
    if (b == 10){
        print("X is the winner", true);
    }
    else if(b == -10){
        print("O is the winner", true);
    }
    else{
        print("draw", true);
    }
    
    return 0;
}
