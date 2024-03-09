#include <iostream>
using namespace std;

template <typename T>
class Node2
{
public:
    T item;
    Node2 *next;

    Node2(T& item, Node2* next = NULL)
    {
        this-> item = item;
        this-> next = next;
    }

    Node2(Node2 *next = NULL)
    {
        this-> next= next;
    }
};

template <typename T>
class Queue
{
    Node2 <T> *front;
    Node2 <T> *rear;
    int maxSize;

    void init()
    {
        front = rear = new Node2 <T> ();
        maxSize = 0;
    }

    void removeAll()
    {
        while(front != NULL)
        {
            rear = front ;
            front = front -> next; // deleting till rear
            delete rear;
        }
    }

public:
    Queue()
    {
        init();
    }

    Queue(int p)
    {
        init();
    }

    ~Queue()
    {
        removeAll();
    }

    void clear()
    {
        removeAll();
        init();
    }

    void enqueue (T it)
    {
        rear = rear -> next = new Node2 <T> (it, NULL);
        maxSize ++;
    }

    T dequeue()
    {
        if(maxSize > 0)
        {
            Node2 <T> *tmp = front -> next;
            T t = tmp-> item;
            front -> next = tmp->next;

            if(rear == tmp)
                rear = front;

//            if(rear == tmp->next)
//                rear = front;




            delete tmp;
            maxSize -- ;
            return t;
        }

        return -1;

    }

    int length()
    {
        return maxSize;
    }

    T frontValue()
    {
        if(maxSize > 0)
            return front->next->item;

        return -1;
    }

    T rearValue()
    {
        if(maxSize > 0)
            return rear->item;
        return -1;
    }

    T leaveQueue()
    {
        if(maxSize > 0)
        {
            Node2 <T>* tmp = front;
            T item = rear -> item;

            while(tmp -> next != rear)
                tmp = tmp-> next;
            tmp -> next = rear -> next;
            maxSize--;
            delete rear;
            rear = tmp;
            return item;
        }

        return -1;
    }

    void print()
    {
        cout << "< | ";
        if(maxSize > 0)
        {
             Node2 <T>* tmp = front->next;

        while(tmp-> next != NULL )
        {
            cout << tmp->item << " ";
            tmp = tmp ->next;
        }

        cout << tmp->item << " ";
        }



        cout << ">" << endl;

    }


};



//int main()
//{
//    Queue <int> q1;
//    for(int i=0;i<10;i++)
//        q1.enqueue(i*i);
//    q1.print();
//    q1.dequeue();
//    q1.print();
//    for(int i=0;i<8;i++)
//        q1.dequeue();
//    q1.print();
//   cout <<  q1.dequeue() << endl;
//    q1.print();
//    q1.enqueue(19);
//    q1.print();
//    cout << q1.rearValue() << endl;
////    q1.dequeue();
////    q1.print();  // problem here // fixed
////    q1.clear();
////    q1.print();
////    cout << q1.leaveQueue() << endl;
////    q1.print();
////}
//}
//
//
//
//
//
//
