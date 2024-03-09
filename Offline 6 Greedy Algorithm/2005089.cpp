#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    int s_time, f_time;
    int customers;
    in >> customers;

    int starting_time[customers];
    int finishing_time[customers];
    int output_s[customers];
    int output_f[customers];

    for(int i = 0; i<customers; i++)
    {
        in >> s_time >> f_time;
        starting_time[i] = s_time;
        finishing_time[i] = f_time;
    }

    for(int i=0; i<customers; i++)
    {
        for(int j = i+1 ; j<customers; j++)
        {
            if(finishing_time[j] < finishing_time[i])
            {
                int tmp = finishing_time[j];
                finishing_time[j] = finishing_time[i];
                finishing_time[i] = tmp;
                tmp = starting_time[j];
                starting_time[j] = starting_time[i];
                starting_time[i] = tmp;
            }
        }
    }

    int i = 0;
    int flag = 0;
    output_s[flag] = starting_time[i];
    output_f[flag] = finishing_time[i];
    flag++;
    for(int j = 1; j<customers; j++)
    {
        if(starting_time[j] >= finishing_time[i])
        {
            output_s[flag] = starting_time[j];
            output_f[flag] = finishing_time[j];
            flag++;
            i=j;
        }
    }

    cout << flag << endl;

    for(int i=0; i<flag; i++)
        cout << output_s[i] << " " << output_f[i] << endl;





}
