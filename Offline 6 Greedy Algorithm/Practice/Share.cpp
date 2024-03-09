#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector <int> arr = {7,1,5,3,6,4};
    pair <int,int> ans;

    int maxProfit = 0 ;
    int minBuy = INT_MAX;
    int ind;

    for(int i  = 0 ; i< arr.size() ; i++)
    {
        if(minBuy > arr[i])
        {
            ind = i ;
            minBuy = arr[i];
        }

        if(maxProfit < arr[i] - minBuy)
        {
            maxProfit = arr[i] - minBuy;
            ans = {ind,i};
        }

    }

    cout << "Best time to buy on day " << ans.first+1 << " and sell on " << ans.second+1 << endl;
    cout << "Maximum profit is " << maxProfit;
}
