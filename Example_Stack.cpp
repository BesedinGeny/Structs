#include <iostream>
#include "structs.h"

using namespace std;

int main()
{
    stack st;
    cout << "Creating stack and work with him" << endl;

    //check for empty stack
    if (st.isEmpty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack isn't empty!" << endl;

    //fill the stack from 1 to 20
    for (int i = 1; i <= 20; i++)
        st.push(i);

    if (st.isEmpty())
        cout << "Stack is empty!" << endl;
    else
        cout << "Stack isn't empty!" << endl;
    //get the length of the stack
    int length = st.len();
    cout << "Length the stack is " << length << endl;

    cout << "Choose 1 of the 2 options:\n";
    cout << "1. Clear stack without output elements\n";
    cout << "2. Clear stack with output elements\n";
    char choose;
    cin >> choose;
    switch (choose) {
    case '1':
        st.clean();
        cout << "Stack is clening...\n";
        if (st.isEmpty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Stack isn't empty!" << endl;
        break;
    case '2':
        cout << "Outputs elements: ";
        while (!st.isEmpty()){
            cout << st.pop() << " ";
        }
        if (st.isEmpty())
            cout << "\nStack is empty!" << endl;
        else
            cout << "\nStack isn't empty!" << endl;
        break;
    }
    ;
    ;
    ;
    ;
    ;
    ;
    ;

    return 0;

}
