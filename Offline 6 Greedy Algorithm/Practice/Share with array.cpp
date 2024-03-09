#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] =  {7,1,5,3,6,4};
//    sort(arr,arr+6);
//    for(int i = 0; i < 6 ; i++)
//        cout << arr[i] << " ";

    int maxProfit = -11111;
    int index ;
    int minBuy = 1111111;
    int index2;

    for(int i = 0 ; i<6 ;  i++)
    {
        if(minBuy > arr[i])
        {
            minBuy = arr[i];
            index = i+1;
        }

        if(arr[i] - minBuy > maxProfit)
        {
            maxProfit = arr[i] - minBuy;
            index2 = i+1;
        }
}

cout << "Best time to buy on day " << index << " and sell on day " << index2 << endl;
cout << "Maximum profit is " << maxProfit ;

}
