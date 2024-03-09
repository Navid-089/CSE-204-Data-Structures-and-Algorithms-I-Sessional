#include <iostream>
#include <fstream>
#include "LinkedList.cpp"
//#include "Array.cpp"

using namespace std;

template <typename T>
class LRUCache
{
    int capacity;

    MyList <T> m1;
    MyList <T> m2;
public:

    LRUCache(int capacity) : m1(capacity), m2(capacity)
    {
        this->capacity = capacity;
    }

    void put(T key, T val)
    {
        if(m1.size() >= capacity)
        {
            m1.setToEnd();
            m1.erase();
        }

        if(m2.size() >= capacity)
        {
            m2.setToEnd();
            m2.erase();
        }

        m1.setToBegin();
        m1.push(key);
        m2.setToBegin();
        m2.push(val);
    }

    T get(T key)
    {
        T found = m1.find(key);
        if(found == -1)
            return -1;
//        T tmp1= m1.arr[found-1];
//        T tmp2= m2.arr[found-1];
        m1.setToPos(found-1);
        T tmp1= m1.getValue();
        m2.setToPos(found-1);
        T tmp2 = m2.getValue();
        m1.setToBegin();
        m1.push(tmp1);
        m2.setToBegin();
        m2.push(tmp2);
        m1.setToPos(found);
        m1.erase();
        m2.setToPos(found);
        m2.erase();

        return tmp2;
    }


};

int main()
{
//    LRUCache <int> l1(5);
//    l1.put(1,111);
//    l1.put(2,222);
//    l1.put(3,333);
//
//   cout << l1.get(2) << endl;
//   l1.put(4,444);
//   cout << l1.get(1) << endl;
//   cout << l1.get(3) << endl;
//   l1.put(5,555);
//   l1.put(6,666);
//   l1.put(7,777);
//   cout << l1.get(1) << endl;

    FILE *fp;
    ifstream in;
    fp = freopen("lru_output.txt","w",stdout);
    in.open("lru_input.txt");

    if(in.eof())
    {
        cout << "Error! Empty file." << endl;
        return -1;
    }

    int cap;
    in >> cap;
    LRUCache <int> lru(cap);

    int num;
    in >> num ;

    for(int i=0; i<num ; i++)
    {
        int operation, key, value, tmp;
        in >> operation ;



        if(operation == 1)
        {
            in >> key;
            tmp = lru.get(key);
            cout << tmp << endl;
        }

        else if(operation == 2)
        {
            in >> key >> value;
            lru.put(key,value);
        }




    }

    in.close();

}


