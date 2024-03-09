#include <iostream>
using namespace std;

template <typename T>
class Queue
{
    int front;
    int rear;
    int maxSize;
    T* q_arr;

    void mem_inc()
    {
        T* temp = new T[maxSize];
        for(int i=0; i<maxSize; i++)
            temp[i] = q_arr[i];

        delete [] q_arr;

        maxSize = maxSize *2 ;

        q_arr = new T[maxSize];

        for(int i=0; i<maxSize; i++)
            q_arr [i] = temp[i];
        delete [] temp;
    }

public:
    Queue(int s)
    {
        front = rear = 0;
        maxSize = s;
        q_arr  = new T[maxSize];
    }

    ~Queue() {delete [] q_arr;}

    void enqueue(T item)
    {
        if(maxSize == rear)
            mem_inc();

        q_arr[rear] = item;
        rear ++ ;
    }

    T dequeue()
    {
        if(front == rear)
            return -1;

        T tmp = q_arr[front];
        for(int i=0; i<rear -1 ; i++)
            q_arr[i] = q_arr[i+1];
        rear -- ;

        return tmp;
    }

    T frontValue()
    {
        if(front == rear)
            return -1;
        return q_arr[front];
    }

    T rearValue()
    {
//        if(rear == 0)
//            return q_arr[0];
        if(front == rear)
            return -1;
        return q_arr[rear-1];
    }

    int length()
    {
        return rear-front;
    }

    void clear()
    {
        front = rear = 0;
    }

    T leaveQueue()
    {
        if(rear != front)
        {
            T tmp = q_arr[rear-1];
            rear --;
            return tmp;
        }

        return -1;
    }



    void print()
    {
        cout << "< | ";
        if(front != rear)
        {
            for(int i = front ; i<rear; i++)
                cout << q_arr[i] << " ";
        }

        cout << ">" << endl;
    }



};

//int main()
//{
//    Queue <int> q1(10);
//    for(int i=0;i<10;i++)
//        q1.enqueue(i*i);
//    q1.print();
//    q1.dequeue();
//    q1.print();
//    cout << q1.length() << endl;
//    for(int i=0;i<8;i++)
//        q1.dequeue();
//    q1.print();
//    cout << "meow " << q1.rearValue() << endl;
//    q1.print();
//    q1.dequeue();
//    q1.print();
//    q1.clear();
//    q1.print();
//    cout << q1.leaveQueue() << endl;
//    q1.print();
//}
