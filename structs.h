#ifndef STRUCTS_H
#define STRUCTS_H

#endif // STRUCTS_H
#define N 100

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


    //
    int inp(){
        cout <<"This is edges: " <<  uL << " " << uR << endl;
        return 0;
    }
    //добавление в очередь
    int push(int elem){
        if (uL == (uR + 1) % S)
            return 1;
        if (uL == uR){
            uL = 70;
            uR = 70;
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
        return (uR - uL + 1 + S) % S;
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
        cout << "Queue cleaned!" << endl;
        return 0;
    }

    int fullPrintWithDelete(){
            cout << "Full queue print with deleting elements: \n";
            if (this->isEmpty()){
                cout << "Queue is not created!\n";
                return 0;
            }

            while (!this->isEmpty()){
                int current = this->pop();
                cout << current << " ";
            }
            cout << endl;

            return 1;
        }
        //печать без удаления
        int fullPrint(){
            cout << "Full queue print: \n";
            if (this->isEmpty()){
                cout << "Queue is not created!\n";
                return 0;
            }

            if (uR - uL < 0){
                for (int i = uL + 1; i < S; i++)
                    cout << mas[i] << " ";
                for (int i = 0; i <= uR; i++)
                    cout << mas[i] << " ";
            }
            else{
                for (int i = uL + 1; i <= uR; i++)
                    cout << mas[i] << " ";
            }
            cout << endl;

            return 1;
        }
    };

//дек
class deque
{
private:
    int SIZE = N;
    int array[N];
    int ul = -1, ur = -1;
public:
    void pushL(int elem){
        if (ul == ur && ul == -1){
            ul = 0;
            ur = 0;
            array[ul] = elem;
        }
        else{
            if ((ur + 1 + N) % N == ul || (ul == 0 && ur == N - 1))
                //обработка переполнения
                cout << "DEQUE OVERFLOW!!!" << endl;
            else{
                ul = (ul - 1 + N) % N;
                array[ul] = elem;
            }
        }
    }
    void pushR(int elem)
    {
        if (ul == ur && ul == -1){
            ul = 0;
            ur = 0;
            array[ur] = elem;
        }
        else{
            if ((ur + 1 + N) % N == ul || (ul == 0 && ur == N - 1))
                //обработка переполнения
                cout << "DEQUE OVERFLOW!!!" << endl;
            else{
                ur = (ur + 1 + N) % N;
                array[ur] = elem;
            }
        }
    }
    int popL(){
        if (ul == ur && ul == -1){
            cout << "DEQUE IS EMPTY!" << endl;
        }
        else{
            if (ul == ur){
                int elem = array[ul];
                ul = ur = -1;
                return elem;
            }
            else{
                int elem = array[ul];
                ul = (ul + 1 + N) % N;
                return elem;
            }
        }
    }
    int popR(){
        if (ul == ur && ul == -1){
            cout << "DEQUE IS EMPTY!" << endl;
        }
        else{
            if (ul == ur){
                int elem = array[ur];
                ul = ur = -1;
                return elem;
            }
            else{
                int elem = array[ur];
                ur = (ur - 1 + N) % N;
                return elem;
            }
        }
    }
    int lenght(){
        if (ur - ul > 0)
            return ur - ul + 1;
        else
            return ur - ul + N + 1;
    }

    void clear(){
        ul = ur = -1;
    }

    void print(){
        if (ul != -1){
            cout << "Print deque: " << endl;
            if (ur - ul > 0)
                for (int i = ul; i <= ur; i++)
                    cout << array[i] << " ";
            else{
                for (int i = ul; i < N; i++)
                    cout << array[i] << " ";
                for (int i = 0; i <= ur; i++)
                    cout << array[i] << " ";
            }
            cout << endl;
        }
        else printf("ERROR: DEQUE IS EMPTY!");
    }
};
//односвязный список
class list{

private :

    //информационное звено списка
    struct Node{
        int Data;
        Node *Next;
    };

    //голова списка
    Node *Head = NULL;

public:


    /*
     * Debugged
    */
   //создание списка и заполнение из потока
    int Create( istream &is)
    {
        int data;
        Node *Current = new Node;
        //пока я могу считать из потока я буду добавлять в список новый элемент
        while (is >> data){

            //если элемент первый то изменяем голову
            if (Head == NULL){
                Head = Current;
                Current->Next = NULL;
                Current->Data = data;

            }
            //иначе создаем текущий элемент
            else{

                Current->Next = new Node;
                Current = Current->Next;
                Current->Next = NULL;
                Current->Data = data;
            }

        }

        return 0;
    }

    //получить голову списка
    Node *GetHead(){
        return Head;
    }

    //вставить после n-ного элемента
    //можно использовать для инициализации списка в цикле, начиная с -1
    //вставить после n-ного элемента
    //можно использовать для инициализации списка в цикле, начиная с -1
    //*DEBUGGED
    int AddNode(int n, int Data){
        int i = 0;//считчик текущего элемента

        //Если создаем первый элемент в списке,то переназначаем голову и создаем первую ноду
        Node *Current = Head;
        if (Head == NULL){
            Current = new Node;
            Head = Current;
            Current->Next = NULL;
            Current->Data = Data;
            return 1;
        }

        //если элемента с таким номером не существует, нода будет добавлена в конец
        while ((i < n)&&(Current->Next != NULL)){
            i++;
            Current = Current->Next;

        }
        //cout << i << ")";
        //пришли к n-ному элементу, либо к последнему
        Node *NewEl = new Node;
        NewEl->Next = Current->Next;
        NewEl->Data = Data;
        Current->Next = NewEl;
        return 0;

    }


    //удаление ноды после n
    int DeleteNode(int n){
        Node *Current = Head;
        int i =0;
        //конец и нет нужного элемента
        char isEnd = 0;
        if (n == 0){
            Head = Current->Next;
            delete Current;
            return 0;
        }

        while(!isEnd){
            if ((Current->Next == NULL) )
                isEnd = 1;
            if ((i == n - 1))
                break;
            Current = Current->Next;
            i++;
        }
        if (isEnd) return 1;

        Node *delNode = Current->Next;
        if (Current->Next != NULL)
            Current->Next = Current->Next->Next;
        else
            Current->Next = NULL;
        delete delNode;
        return 0;
    }

    //очистка памяти листа
    int Clear(){
        Node *Current = Head;
        while (Head != NULL){
               Current = Head;
               Head = Head->Next;
               delete Current;
        }
        return 0;
    }

    int printList(){
        Node *Current = Head;
        if (Current == NULL){
            cout << "List is empty" << endl;
            return 1;
        }
        while (Current != NULL){
            cout << Current->Data << " ";
            Current = Current->Next;
        }
        cout << endl;
        return 0;
    }

    //чтение из элемента
    int Read(Node *Current){
        return Current->Data;
    }

    //переход к нужному элементу
    Node * GoToELement(int n){
        char isFound = 0;
        Node *Current = Head;
        int i;
        //пока можем бежим по массиву
        for (i = 0; i < n && Current->Next!=NULL; i++){
            Current = Current->Next;
        }
        if (i == n-1) isFound = 1;
        //если такого элемента еще не создано, то вернуть нулпоинтер
        if (!isFound) return NULL;
        return Current;
    }
};
