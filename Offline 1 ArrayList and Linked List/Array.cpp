#include <iostream>
#include <fstream>

using namespace std;

template <typename E>
class MyList
{
public:
    E* arr;
    int length;
    int capacity;
    int curr;



    MyList(int cap=0)
    {
        length=0;
        curr= 0;
        capacity=cap;
        arr = new E[capacity];
    }

//    MyList(int len, int cap)
//    {
//
//        length=0;
//        curr= 0;
//        capacity=cap;
//        arr = new E[capacity];
//    }

    MyList(MyList p_arr, int p_cap)
    {
        capacity = p_cap;
        arr= new E[capacity];
        length = p_arr.size();
        for(int i=0; i<length; i++)
            arr[i] = p_arr.arr[i];

        curr = 0 ;

    }

    ~MyList()
    {
        delete [] arr;
    }



    void setToBegin()
    {
        curr = 0;
    }

    void clear()
    {
        delete [] arr;
        length = curr = 0;

        arr= new E[capacity];
    }

    void setToEnd()
    {
        curr = length-1;
    }

    void setToPos(int pos)
    {
        if(!(pos >=0 && pos <=length))
        {
            cout << "Position is out of range." << endl;
            return;
        }

        curr= pos;

    }

    void prev()
    {
        if(curr != 0) curr-- ;
    }

    void next()
    {
        if(curr < length-1) curr++;

    }

    int currPos()
    {
        return curr;
    }

    int size()
    {
        return length;
    }

    E getValue()
    {
        return arr[curr];
    }

    void push(const E &item)
    {
        if(length >= capacity)
        {
            E* temp_array= new E[capacity];
            for(int i=0; i< length; i++)
                temp_array[i] = arr[i];
            delete [] arr ;

            capacity = 2 * capacity;

            arr = new E[capacity];

            for(int i=0 ; i< length; i++)
                arr[i] = temp_array[i];

            delete [] temp_array;
        }

        for(int i=length; i > curr; i--)
            arr[i] = arr[i-1];

        arr[curr] = item;

        length++;
    }

    void pushBack(const E &item)
    {
        if(length >= capacity)
        {
            E* temp_array= new E[capacity];
            for(int i=0; i<length ; i++)
                temp_array[i] = arr[i];
            delete [] arr ;

            capacity = 2 * capacity;

            arr = new E[capacity];

            for(int i=0 ; i< length; i++)
                arr[i] = temp_array[i];


            delete [] temp_array;
        }

        arr[length] = item;
        length++;
    }

    E erase()
    {

        if(!((curr >= 0) && (curr < length)) )
        {
            cout << "No such element ... " << endl;
            return 0;
        }
        E item = arr[curr];
        for(int i= curr; i<length-1; i++)
            arr[i] = arr[i+1];

        length--;
        if(length <= ( 0.5 * capacity))
        {
            capacity = capacity/ 2;
            E *temp_array = new E[length];

            for(int i=0; i<length ; i++)
                temp_array[i] = arr[i];

            delete [] arr;

            arr= new E[capacity];

            for(int i=0; i<length; i++)
                arr[i] = temp_array[i];

            delete [] temp_array ;

        }
        return item;
    }

    int find(E param)
    {
        for(int i=0; i<length; i++)
        {
            if(arr[i] == param)
                return (i+1);
        }

        return -1;
    }




    void print()
    {


//
//        ifstream in;
//        ofstream out;
//        in.open("list_input.txt");
//        out.open("list_output.txt");
////        cout << "< ";
////        if(curr == 0)
////            cout << "| ";
////        for(int i=0; i<length; i++)
////        {
////            cout << arr[i] << " " ;
////            if(i == curr-1 && curr !=0)
////                cout << "| ";
////
////        }
////        cout << ">" <<  endl;

//        cout << "navid noob" << endl;


//        cout << "current position is in " << curr << endl;
//        cout << "size of array now is " << length << endl;
//        cout << "capacity is " << capacity << endl;

//        out.close();
//        in.close();

         int position = currPos();
         setToBegin();
         cout << "< ";
         while(curr < length -1)
         {
             if(curr == position )
                cout << "| ";
            cout << getValue() << " ";
            next();
         }

         if(curr == position )
                cout << "| ";





         if(length!=0)
            cout << getValue();
         cout << " >" << endl;
         setToPos(position);

    }


};

//int main()
//{
//    MyList <int>  m(10);
//
//    int n;
//    for(int i=0; i<4; i++)
//    {
//        cin >> n;
//        m.pushBack(n);
//    }
//    m.setToEnd();
//
//    cout << "Found at " << m.find(3) << endl;
//
//    m.print();
//
//}
