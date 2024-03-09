// C++ program for Gas Station Problem
#include <bits/stdc++.h>
using namespace std;


int gasStationIndex(vector <int> gas, vector <int> cost)
{
    int sum_gas = 0 ;
    int sum_cost = 0 ;
    int start = -1;
    for(int i = 0 ; i < gas.size() ; i++)
    {
        sum_gas += gas[i];
        sum_cost +=cost[i];
    }

    if(sum_gas != sum_cost) return -1;
    else
    {
        int balance = 0;
        for(int i = 0 ; i < gas.size() ; i++)
        {
            balance += gas[i] - cost[i];
            if(balance < 0)
            {
                start = i+1;
                balance = 0;

            }
        }

        return start;
    }
}

int main() {
    //Intializing the amount of gas at ith station in the array
    vector<int> gas = {1,2,3,4,5};
    //Intializing the cost of gas from ith station to (i+1)th station
    vector<int> cost = {3,4,5,1,2};

    int ans = gasStationIndex(gas,cost);

    //Printing the starting index from which we can complete the circuit
    if(ans!=-1){
        cout<<"Starting gas station's index that can travel around the circuit : "<<ans;
    }
    else{
        cout<<"Can't travel around the circuit once no matter where you start.";
    }
}
