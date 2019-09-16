#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H
#define N 1000

#include<iostream>

using namespace std;

class stack{
private:

    int mas[N];
    int uS = -1;
    //только для работы с помятью ;)
    int S = N;

public:
    //создание массива данных

    //без указания максимальной длинны стека в конструкторе


    //добавление в стек элемента
    int push(int elem){
        if (uS == S - 1)
            return 1;
        mas[++uS] = elem;
        return 0;
    }

    //проверка на пустоту
    int isEmpty(){
        if (uS == -1)
            return 1;
        else
            return 0;
    }

    //узнать индекс верхушки
    int len(){
        return uS + 1;
    }


    //изымание из стека элемента
    int pop(){
        if (uS < 0)
        {
            cout << "ERROR" << endl;
            return 0;
        }
        return mas[uS--];
    }

    //очищение стека
    int clean(){
        uS = -1;
        return 0;
    }

};

//круговая модель очереди
class queue{
private:
    int uL = -1;
    int uR = -1;
    int S = N;
    int mas[N];
public:

    //без указания максимальной длины очереди

    //добавление в очередь
    int push(int elem){
        if (uL == (uR + 1) % S)
            return 1;
        if (uL == uR){
            uL = 0;
            uR = 0;
        }

            uR += 1;
            uR %= S;

        mas[uR] = elem;
        return 0;
    }

    //проверка на пустоту очереди
    int isEmpty(){
        if (uL == -1)
            return 1;
        else
            return 0;
    }
    int len(){
        return (uR - uL + 1) % S;
    }

    //удаление элемента из очереди
    int pop(){
        int elem;
        if (uL == uR){
            if (uL == -1){
                cout << "ERROR" << endl;
                return 0;
            }
            elem = mas[uL];
            uL = uR = -1;

        }
        else{
            elem = mas[uL];
            uL = (uL + 1) % S;
        }
        return elem;
    }

    //очищение очереди
    int clean(){
        uL = uR = -1;
        return 0;
    }

    //печать с удалением
    int printQ(){
        while (!this->isEmpty()){
            int current;
            current = this->pop();
            cout << current << " ";
        }
        cout << endl;
        return 0;
    }
};

//односвязный список
class list{


private :
    //информационное звено списка
    struct Node{
    public:
        int Data;
        Node *Next;
    };
    Node *Head = NULL;
public:

   //создание N элементов списка и заполнение нулями
    int Create(int n )
    {
        for ( int i = 0; i < n; i++){
            Node *Current = new Node;
            if (Head == NULL){
                Head = Current;
                Current->Next = NULL;
                Current->Data = 0;
            }
            else{
                Current->Next = new Node;
                Current = Current->Next;
                Current->Next = NULL;
                Current->Data = 0;
            }
        }

        return 0;
    }

    //получить голову списка
    Node *GetHead(){
        return Head;
    }

    //вставить после n-ного элемента
    int add(int n, int Data){
        int i = 0;//считчик текущего элемента
        //если элемента с таким номером не существует, нода будет добавлена в конец
        Node *Current = Head;
        while ((i < n)&&(Current->Next != NULL)){
            i++;
            Current = Current->Next;

        }
        //пришли к n-ному элементу, либо к последнему
        Node *NewEl = new Node;
        NewEl->Next = Current->Next;
        NewEl->Data = Data;
        Current->Next = NewEl;
        return 0;

    }

    //очистка памяти листа
    int Clear(){
        Node *Current = Head;
        while (Head->Next != NULL){
               Current = Head;
               Head = Head->Next;
               delete Current;
        }
    }
};
