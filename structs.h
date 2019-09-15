#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H
#define N 1000
#include<iostream>
using namespace std;

class stack{
private:

    int *mas;
    int uS = -1;
    //только для работы с помятью ;)
    int S = N;

public:
    //создание массива данных

    //без указания максимальной длинны стека в конструкторе
    stack(){
         mas = new int(N);
    }
    //с указанием макс. длинны стека
    stack(int SIZE){
         mas = new int(SIZE);
        S = SIZE;
    }

    //очищение памяти
    ~stack(){
        delete mas;
    }

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
        return uS;
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
};

//круговая модель очереди
class queue{
private:
    int uL = -1;
    int uR = -1;
    int S = N;
    int *mas;
public:

    //без указания максимальной длины очереди
    queue(){
         mas = new int(N);
    }

    //с указанием макс. длинны очереди
    queue(int SIZE){
         mas = new int(SIZE);
        S = SIZE;
    }

    //очищение памяти
    ~queue(){
        delete mas;
    }

    //добавление в очередь
    int push(int elem){
        if (uL == (uR + 1) % S)
            return 1;
        if (uL == uR){
            uL = 0;
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
};
