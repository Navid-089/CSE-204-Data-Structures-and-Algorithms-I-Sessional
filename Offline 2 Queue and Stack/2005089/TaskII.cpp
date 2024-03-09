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
    in.open("Test5.txt");

    Queue <int> line1(10);
    Stack <int> line2;

    int l1_len, l2_len;

    int customers;
    int total_time;

    int c1_state = -1;
    int c2_state = -1;

    in >> customers >> total_time;

    int a_time[customers], duration[customers];
    int flags[customers] ;
    int dep_time[customers] ;

    for(int i=0; i<customers; i++)
        in >> a_time[i] >> duration[i];

    for(int t = 1; t<=total_time ; t++)
    {
        for(int i=0; i<customers; i++)
        {
            if(a_time[i] == t && c1_state == -1 && c2_state == -1)
            {
                c1_state = 1;
                flags[i] = 1;
                dep_time[i] = a_time[i] + duration[i];
                break;
            }

            // initial stage when both of the consoles are free

            l1_len = line1.length();
            l2_len = line2.length();


            if(a_time[i] == t && c1_state != -1 && l1_len < 3)
            {
                line1.enqueue(i);
                flags[i] = 1;
                break;
            }

            // one or two of them are standing in line 1

            l1_len = line1.length();
            l2_len = line2.length();


            if(a_time[i] == t && c1_state != -1 && l1_len ==3 && c2_state == -1)
            {
                c2_state = 1;
                flags[i] = 2;
                dep_time[i] = a_time[i] + duration[i];
                break;
            }

            // line 1 is full -> sent to line 2

            l1_len = line1.length();
            l2_len = line2.length();

            if(a_time[i] == t && c1_state != -1 && c2_state != -1 && l1_len == 3)
            {
                line2.push(i);
                flags[i] = 2;
                break;
            }

            // line 1 is full, line 2 is arranging and pushed

            l1_len = line1.length();
            l2_len = line2.length();

            if(dep_time[i] == t && flags[i] == 1 && l1_len >0)
            {
                int ret = line1.dequeue();
                c1_state = ret;
                dep_time[ret] = t + duration[ret];
                break;
            }

            // when t is equal to dep_time, get one of them out

            l1_len = line1.length();
            l2_len = line2.length();

            if(dep_time[i] == t && flags[i] == 2 && l2_len >0)
            {
                int ret = line2.pop();
                c2_state = ret;
                dep_time[ret] = t+ duration[ret];
            }

            l1_len = line1.length();
            l2_len = line2.length();
        }
    }




    for(int i=0; i<customers; i++)
    {
//        cout << "In console number : " << flags[i] << endl;
        cout << i+1 << ">" ;
        if(dep_time[i] > total_time)
            cout << total_time << endl;
        else
            cout << dep_time[i] << endl;
    }

}

