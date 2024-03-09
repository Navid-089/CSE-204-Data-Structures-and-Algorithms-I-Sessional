#include <iostream>
using namespace std;

template <typename T>
class Stack
{
    int top;
    int maxSize;
    T* s_array;

    void mem_inc()
    {
//        int pos = top;
        T* temp = new T[maxSize];
        for(int i=0; i<maxSize; i++)
            temp[i] = s_array[i];

        delete [] s_array;

        maxSize *= 2;

        s_array = new T[maxSize];

        for(int i=0; i<maxSize; i++)
            s_array[i] = temp[i];

//        top = pos ;
        delete [] temp;
    }



    void init()
    {
        top = 0;
    }

public:
    Stack(int size = 0)
    {
        maxSize = size;
        s_array = new T[size];
        init();
    }

    ~Stack()
    {
        if(!(s_array == NULL))
            delete [] s_array;
    }

    void clear()
    {
        init();
    }

    void push(T item)
    {
        if(top == maxSize)
            mem_inc();

        s_array[top] = item;
        top++;

    }

    T pop()
    {
        if(top > 0)
        {
            top -- ;
            return s_array[top];
        }
    }

    int length()
    {
        return top;
    }

    T topValue()
    {
        if(top > 0)
            return s_array[top-1];
    }

    void print()
    {
        cout << "< ";
        for(int i=0; i<length() ; i++)
        {
            cout << s_array[i] << " ";
            if(i == top-1)
                cout << "| ";
        }

        cout << ">" << endl;
    }

};

//int main()
//{
//    Stack <int> s1(10);
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
//    s1.print();
//
//    return 0;
//
//}
