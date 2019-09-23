#include <iostream>
#include "structs.h"

using namespace std;

int main(){

    deque D;
    for (int i = 1; i < 102; i++)
        D.pushR(i);

    int elemL = D.popL(), elemR = D.popR();
    cout << "Pop from left: " << elemL << "\nPop from right: " << elemR << endl;

    D.print();

    //poping 40 elem by RIGHT and LEFT
    for (int i = 0; i < 20; i++){
        D.popR();
        D.popL();
    }

    D.print();
    int length = D.lenght();
    cout << "Length of deque is " << length << endl;

    return 0;
}
