#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T item;
    Node *next;

    Node(T& item, Node* next = NULL)
    {
        this-> item = item;
        this-> next = next;
    }

    Node(Node *next = NULL)
    {
        this-> next= next;
    }
};

template <typename T>
class Stack
{
    Node <T>* top;
    int maxSize;

    void init()
    {
        top = NULL;
        maxSize = 0;
    }

    void removeAll()
    {
        while(top != NULL)
        {
            Node <T> * tmp = top;
            top = top->next;
            delete tmp;
        }
    }



public:
    Stack()
    {
        init();
    }

    Stack(int p)
    {
        init();
    }

    ~Stack()
    {
        removeAll();
    }

    void clear()
    {
        removeAll();
        init();
    }

    void push(T item)
    {
        top = new Node<T> (item, top);
        maxSize++;
    }

    T pop()
    {
        if(maxSize > 0)
        {
            Node <T> * tmp = top;
            top  = top->next;
            T ret = tmp->item;
            delete tmp;
            maxSize--;
            return ret;

        }

        else
            return -1;
    }

    int length()
    {
        return maxSize;
    }

    T topValue()
    {
        if(maxSize > 0)
            return top->item;
        else
            return -1;
    }


    void print()
    {
        cout << "< ";

//        cout << " The length of the stack is :" << length() << endl;
        Stack <T> s2;
        int flag = 1;

        if(maxSize >0)
        {


        while(flag)
        {
            s2.push(topValue());
            T tmp = pop();
            if(length() == 0)
                flag = 0;
        }

//         cout << " The length of the  stack now is :" << s2.length() << endl;
        flag =1;
        while(flag)
        {
            T tmp = s2.pop();
            cout << tmp << " ";
            push(tmp);

            if(s2.length() == 0)
                flag = 0;
        }
        }

        cout << "| >" << endl;
    }
};

//int main()
//{
//    Stack <int> s1;
//
//    for(int i=0; i<11; i++)
//        s1.push(i*i);
//    s1.print();
//    s1.pop();
//    s1.print();
//
//    s1.push(36);
//    s1.push(49);
//    s1.push(64);
//
//
//    s1.print();
//
//    cout << s1.length() << endl;
//
//    s1.pop();
//    s1.print();
//    s1.clear();
//    for(int i=0; i<11; i++)
//        s1.push(i*i);
//    s1.print();
//     s1.pop();
//    s1.print();
//
//    for(int i=0; i<9;i++)
//        s1.pop();
//    s1.print();
//    s1.clear();
//    s1.print();
//
//    return 0;
//
//}
//
