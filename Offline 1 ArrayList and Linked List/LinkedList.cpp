#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T item;
    Node* next;

    Node(const T& item, Node *next = NULL)
    {
        this->item = item;
        this->next = next;
    }

    Node(Node *next = NULL)
    {
        this->next = next;
    }
};

template <typename T>
class MyList
{
    Node <T> * head;
    Node <T> *  tail;
    Node <T> * curr;
    long listSize;

    void init()
    {
        head=tail=curr=new Node<T>;
        listSize = 0;
    }

    void removeAll()
    {
        while( head != NULL )
        {
            curr = head;
            head = head->next;
            delete curr;
        }
    }

public :

    MyList (long p_size = 0)
    {
        init();
    }

    MyList(T arr[], int len)
    {
        init();
        for(int i=0 ; i<len; i++)
            pushBack(arr[i]);
        curr = head;
    }

    MyList(Node <T> *start)
    {
        init();
        tail = head ->next= start;

        while( tail -> next != NULL)
        {
            tail = tail-> next;
            listSize++;
        }
    }

    ~MyList()
    {
        removeAll();
    }

    long size()
    {
        return listSize;
    }

    void clear()
    {
        removeAll();
        init();
    }

    void push(const T& item)
    {
        curr -> next = new Node<T> (item, curr -> next);
        if(tail == curr)
        {
            tail = curr-> next;
        }

        listSize++;
    }

    void pushBack(const T& item)
    {
        tail = tail -> next = new Node<T>(item, NULL);
        listSize++;
    }

    T erase()
    {
//        Node <T> *temp = curr->next;
//        T item = temp->item;
//        curr->next= temp->next;
//
//        listSize--;
//        delete temp;
//        return item;

        T t= curr->next->item;
        Node <T>* tmp = curr->next;
        if(tail == curr->next)
            tail = curr;
        curr -> next = curr ->next ->next;
        delete tmp;
        listSize--;
        return t;
}

    void setToBegin()
    {
        curr = head;
    }

    void setToEnd()
    {
        Node <T> *t= head;
        while(t->next != tail)
        {
            t= t->next;
        }
        curr = t;
    }

    void next()
    {
        if (curr -> next != tail)
            curr = curr-> next;
    }

    void prev()
    {
        if(curr != head)
        {
            Node<T> *temp = head;
            while(temp-> next != curr)
                temp = temp-> next;
            curr = temp;
        }
    }

    long currPos()
    {
        long pos;
        Node <T> *temp = head;
        for(pos = 0; curr != temp ; pos ++ )
            temp = temp->next;

        return pos;
    }

    void setToPos(long pos)
    {
        if(pos >= 0 && pos <listSize)
        {
            curr = head;
            for(int i=0 ; i< pos ; i++)
                curr = curr->next;
        }
    }

    T getValue()
    {
        return curr->next->item;
    }

    long find(const T& item)
    {
        Node <T> *temp= head;
        for(int i=0; i< listSize; i++)
        {
            temp = temp ->next;
            if(item == temp->item)
                return (i+1);
        }
        return -1;
    }

    void print()
    {


         int position = currPos();
         setToBegin();
         cout << "< ";
         while(currPos() < size() -1)
         {
             if(currPos() == position )
                cout << "| ";
            cout << getValue() << " ";
            next();
         }

         if(currPos() == position )
                cout << "| ";

         if(size()!=0)
            cout << getValue();
         cout << " >" << endl;
         setToPos(position);

    }


};


//int main()
//{
//    MyList <int> L1;
//    L1.pushBack(1);
//    L1.pushBack(2);
//    L1.setToPos(1);
//    L1.push(2);
//    L1.push(124);
//    L1.pushBack(4);
//    L1.pushBack(5);
//    L1.pushBack(6);
//    L1.setToPos(5);
//    L1.push(11);
////
//    L1.erase();
////
////
////    L1.print();
////    L1.clear();
//    L1.print();
//
//}
