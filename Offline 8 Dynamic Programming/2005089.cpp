#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    int weight_remaining;
    int num;

    in >> num;

    int items_value[num];
    int items_weight[num];

    for(int i = 0 ; i<num ; i++)
        in >> items_weight[i] >> items_value[i];
    in >> weight_remaining;
    int array[num+1][weight_remaining+1];
    int taken_arr[num];
    int flag = 0;
    vector<int> itemsTaken;

    for(int i = 0 ; i<=weight_remaining ; i++)
    {
        for(int j = 0 ; j<=num; j++)
        {
            if(i == 0 || j == 0)
            {

                array[j][i] = 0;
            }
            else
            {
                if(items_weight[j-1] > i)
                {
                    array[j][i] = array[j-1][i];

                }
                else
                {
                    if(array[j-1][i] > (items_value[j-1] + array[j-1][i-items_weight[j-1]]))
                    {
                        array[j][i] = array[j-1][i];
                    }
                    else
                    {
                        array[j][i] = items_value[j-1] + array[j-1][i-items_weight[j-1]];

                    }
                }
            }
        }
    }

    cout << array[num][weight_remaining] << endl;

int i = num;
int j = weight_remaining;
while (i > 0 && j > 0) {
    if (array[i][j] != array[i - 1][j]) {
        itemsTaken.push_back(i - 1);
        j -= items_weight[i - 1];
    }
    i--;
}

reverse(itemsTaken.begin(), itemsTaken.end());
for (int item : itemsTaken) {
    cout << items_weight[item] << " ";
}

}




