#include <bits/stdc++.h>
using namespace std;

static bool compare(vector <int> a, vector <int> b)
{
    return a[1] > b[1];
}



int main()
{
    vector<vector<int>> jobs = {{2,100},{1,19},{2,27},{1,25},{1,15}};
    int sz = jobs.size();

    sort(jobs.begin(),jobs.end(),compare);

    for(int i = 0 ; i<sz; i++)
        cout << jobs[i][0] << " " << jobs[i][1] << endl;

    vector<vector<int>> activities;








}
