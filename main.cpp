#include <iostream>
#include "PlayGround.cpp"


using namespace std;


int main(void){

    //PlayGround* a = new PlayGround();
    PlayGround a;
    int row, col;
    for(int i = 0; i < 9; i++){
        print("Enter your move (row, col) : ", false);
        cin >> row >> col;
        a.humanMove(row, col);
    }
    
    return 0;
}
