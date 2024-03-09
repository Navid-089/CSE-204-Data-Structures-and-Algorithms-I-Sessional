#include <bits/stdc++.h>
using namespace std;

int main()
{
    int weight_remaining = 60;
    int num = 4;

    int items_value[num] = {40,100,50,60};
    int items_weight[num] = {20,10,40,30};
    int array[num+1][weight_remaining+1];

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
                    array[j][i] = max(array[j-1][i], (items_value[j-1] + array[j-1][i-items_weight[j-1]]));

                }
            }


        }
    }

    for(int i = 0; i<=num; i++)
    {
        for(int j = 0 ; j<= weight_remaining; j++)
        {
            cout << array[i][j] << "  ";
        }
        cout << endl;
    }


}
