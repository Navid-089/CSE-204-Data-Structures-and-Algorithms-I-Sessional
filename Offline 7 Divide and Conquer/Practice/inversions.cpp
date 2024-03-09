#include <bits/stdc++.h>
using namespace std;

int count_inversions(vector <int> &arr)
{
    int sz = arr.size();
    int inversions = 0 ;
    for(int i = 0 ; i < sz; i++)
    {
        for(int j = i+1; j < sz; j++)
        {
            if(arr[j] < arr[i])
            {
                inversions++;

                cout << arr[i] << " " << arr[j] << endl;

                swap(arr[i],arr[j]);
            }

        }
    }


}

int main()
{
    vector <int> arr={2,4,1,3,5};
    cout << count_inversions(arr) << endl;

    for(int i = 0 ; i<arr.size(); i++)
        cout << arr[i] << " ";
}
