#include <iostream>
#include "structs.h"

using namespace std;

int main()
{

    queue Q;
    cout << "Creating queue and work with him" << endl;

    //fill the queue from 1 to 20
    cout << "\nPushing 125 elements in queue\n";
    for (int i = 1; i <= 125; i++)
        if (!Q.push(i)){
            cout << "OVERLOAD QUEUE\n";
            break;
        }

    //print endings of the queue
    Q.inp();
    //print queue
    Q.fullPrint();

    //poping 2 elements
    int elem;
    if ((elem = Q.pop()) != 0)
        cout << "Element-pop: " << elem << endl;
    if ((elem = Q.pop()) != 0)
        cout << "Element-pop: " << elem << endl;

    Q.inp();
    Q.fullPrint();
    int length = Q.len();
    cout << "Length of queue: " << length << endl;
    for (int i = 0; i < 30; i++)
        if ((elem = Q.pop()) != 0)
            cout << "Element-pop: " << elem << endl;
    //print queue with deleting elem
    Q.fullPrintWithDelete();

    if (Q.isEmpty())
        cout << "Queue is empty!\n";

    return 0;
}
