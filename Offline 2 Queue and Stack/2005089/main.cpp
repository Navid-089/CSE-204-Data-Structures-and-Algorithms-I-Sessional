#include "StackArray.cpp"
//#include "QueueArray.cpp"

//#include "StackLinkedList.cpp"
#include "QueueLL.cpp"

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    int length1,capacity1,length2,capacity2;
    int temp;


    in >> length1 >> capacity1;

Stack <int> s1(capacity1);


for(int i=0; i<length1; i++)
    {
        in >> temp;
        s1.push(temp);
    }




    in >> length2 >> capacity2;

    Queue <int> q1(capacity2);

    for(int i=0; i<length2; i++)
    {
        in >> temp;
        q1.enqueue(temp);
    }


    int com,val;
    int num;

    in >> num;

    q1.print();
    s1.print();


    int ret_val;

    for(int i=0; i<num; i++)
    {
        in >> com >> val;

//        cout << com << val << endl;

        if(com == 1)
        {
            q1.clear();
            ret_val = -1;
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 2)
        {
            q1.enqueue(val);
            ret_val = -1;
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 3)
        {
            ret_val = q1.dequeue();
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 4)
        {
            ret_val = q1.length();
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 5)
        {
            ret_val = q1.frontValue();
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 6)
        {
            ret_val = q1.rearValue();
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 7)
        {
            ret_val  = q1.leaveQueue();
            q1.print();
            cout << ret_val << endl;
        }

        else if(com == 8)
        {
            s1.clear();
            ret_val = -1;
            s1.print();
            cout << ret_val << endl;
        }

        else if(com == 9)
        {
            s1.push(val);
            ret_val = -1;
            s1.print();
            cout << ret_val << endl;

        }

        else if(com == 10)
        {
            ret_val = s1.pop();
            s1.print();
            cout << ret_val << endl;

        }

        else if(com == 11)
        {
            ret_val = s1.length();
            s1.print();
            cout << ret_val << endl;

        }

        else if(com == 12)
        {
            ret_val = s1.topValue();
            s1.print();
            cout << ret_val << endl;

        }




    }

    in.close();

}
