#include <iostream>
#include <fstream>

#include "StackLinkedList.cpp"
#include "QueueLL.cpp"

using namespace std;

int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("task2_output.txt","w",stdout);
    in.open("test1.txt");


    Queue <int> line1; // line 1 works like a queue
    Stack <int> line2;

    int customers, total_time;
    int ser = 1;
    int sQueue,sStack;
    int nQueue,nStack;


    in >> customers >> total_time;

    int a_time[customers];
    int duration[customers];
    int dep_time[customers];


    for(int i=0; i<customers; i++)
    {
        in >> a_time[i] >> duration[i];

    }

    for(int t=1 ; t<= total_time ; t++)
    {
        // static int flag =


        int flag = 0;

        if(line1.length() == 0)
        {
            sQueue = a_time[ser - 1];
            nQueue = sQueue + duration[ser-1];
        }

        // check if line 1 is empty, if it is empty, one will go to the first console

        // keeping nQueue to keep track of the time when consoles will start to switch places

        if(nQueue == t)
        {
            int tmp = line1.dequeue();
            dep_time[tmp-1] = t;
            sQueue = t;    // keeping sQueue for the start time of the next person
            nQueue = sQueue + duration[line1.frontValue() -1];
        }

        // when nQueue gets equal, line1 will get dequeued once and the time of



        if(line1.length() <= 3 && ser <=customers)
        {
            while(a_time[ser - 1] == t)
            {
                line1.enqueue(ser++);
                flag = 1;
            }
        }

        // enqueue as long as people are there at the same time



        if(flag == 0)   // flag = 0 means the line1 is full
        {
            if(line2.length() == 0)
            {
                sStack = a_time[ser-1];
                nStack = sStack + duration[ser-1];
            }

            while(a_time[ser-1] == t)
            {
                if(line2.length() == 0)
                    line2.push(ser);
                else
                {
                    int tmp = line2.pop();
                    line2.push(ser);
                    line2.push(tmp);
                }

                ser++;
            }

            if(nStack == t)
            {
                int tmp = line2.pop();
                dep_time[tmp-1] = t;
                sStack = t;
                nStack = sStack + duration[line2.topValue() -1];
            }
        }
    }


    for(int i=0; i<customers; i++)
    {
        cout << i+1 << ">" ;

        if(dep_time[i] > total_time)
            cout << total_time << endl;

        else

            cout<< dep_time[i] << endl;
    }





}
