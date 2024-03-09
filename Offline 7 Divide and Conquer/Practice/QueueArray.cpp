#include <iostream>
using namespace std;

class Queue
{
    int front;
    int rear;
    int *arr;
    int maxSize;


public:
    Queue(int size)
    {
        front = 0;
        rear = -1;
        arr = new int[size+1];
        maxSize = size+1;
    }

    void enqueue(int param)
    {
        if(rear == maxSize-1)
        {
            cout << "FULL." << endl;
            return;
        }

        rear++;
        arr[rear%maxSize] = param;
    }


    void print()
    {
        for(int i=front; i<=rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }




};


int main()
{
    Queue q1(2);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.print();
    q1.enqueue(3);
    q1.print();

}

