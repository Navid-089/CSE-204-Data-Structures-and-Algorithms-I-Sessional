#include <bits/stdc++.h>
using namespace std;

#define V 100

vector<int> wins(V);           // array for storing wins
vector<int> losses(V);         // array for storing losses
vector<int> remaining(V);      // array for storing remaining matches
vector<int> adjGraph[V * V];   // adjGraph where every node stores a vector of adjacent nodes
vector<int> parent(V, -1);     // for backtracking
int flowCapacity[V][V];        // adjacency matrix
vector<int> minCutArray(V);

void addEdge(int u, int v)
{
    adjGraph[u].push_back(v);
    adjGraph[v].push_back(u);
}

int BFS(int source, int sink)
{
    for (int i = 0; i < V; i++)
        parent[i] = -1;
    queue<pair<int, int>> q;
    q.push(make_pair(source, INT_MAX));
    parent[source] = -INT_MAX;

    while (!q.empty())
    {
        int from = q.front().first;
        int val = q.front().second;
        q.pop();
        for (auto to : adjGraph[from])
        {
            if (to >= 0 && to < V && parent[to] == -1 && flowCapacity[from][to] != 0)
            {
                parent[to] = from;
                val = min(val, flowCapacity[from][to]);
                if (to == sink)
                    return val;
                q.push(make_pair(to, val));
            }
        }
    }

    return 0;
}

int edmond_karp(int source, int sink)
{
    int n_f, flow = 0, flag, flag_before;

    while (n_f = BFS(source, sink)) // finds the flow in every way from source to sink
    {
        flag = sink;
        flow += n_f;
        while (flag != source)
        {
            flag_before = parent[flag];
            flowCapacity[flag_before][flag] -= n_f;
            flowCapacity[flag][flag_before] += n_f; // reverse edge
            flag = flag_before;                     // iterating backwards until source is found
        }
    }
    return flow; // returns max flow for a source and sink
}

void minCut(int currTeam, int dest)
{
    vector<bool> isVisited(dest, false); // initialize isVisited with appropriate size
    isVisited[currTeam] = true;
    queue<int> bq;
    bq.push(currTeam);

    while (!bq.empty())
    {
        int tmp = bq.front();
        bq.pop();

        for (int i = 0; i < dest; i++)
        {
            if (i == currTeam)
                continue;
            if (isVisited[i] == false && flowCapacity[tmp][i] > 0)
            {
                isVisited[i] = true;
                if (i != currTeam && i < 4)
                    minCutArray.push_back(i);
                bq.push(i);
            }
        }
    }
}

int main()
{
    int num;
    cin >> num;
    int games[num + 1][num + 1];
    string teamNames[num + 1];
    for (int i = 1; i <= num; i++)
    {
        cin >> teamNames[i];
        cin >> wins[i] >> losses[i] >> remaining[i];

        for (int j = 1; j <= num; j++)
            cin >> games[i][j];
    }

    for (int i = 0; i <= num; i++)
        games[i][i] = 0;

    int source = 0, dest = num + ((num - 1) * (num)) / 2 + 1;

    for (int k = 1; k <= num; k++)
    {
        minCutArray.clear();
        for (int i = 0; i < V; i++)
        {
            adjGraph[i].clear();
            for (int j = 0; j < V; j++)
                flowCapacity[i][j] = 0;
        }

        int flag = 1;
        int nodes = ((num - 1) * (num)) / 2;
        for (int i = 1; i <= num; i++)
        {
            if (i == k)
                continue;
            for (int j = i + 1; j <= num; j++)
            {
                if (j == k)
                    continue;
                addEdge(source, flag);
                flowCapacity[source][flag] = games[i][j];
                addEdge(flag, nodes + i);
                flowCapacity[flag][nodes + i] = 10000;
                addEdge(flag, nodes + j);
                flowCapacity[flag][nodes + j] = 10000;
                flag++;
            }
        }
        bool Eliminated = true;
        for (int i = 1; i <= num; i++)
        {
            if (i == k)
                continue;
            addEdge(nodes + i, dest);
            flowCapacity[nodes + i][dest] = wins[k] + remaining[k] - wins[i];
            if (flowCapacity[nodes + i][dest] < 0)
                Eliminated = false;
        }
        if (Eliminated == false)
        {
            cout << teamNames[k] << " is eliminated. " << endl;
            cout << "They can win at most " << wins[k] << "+" << remaining[k] << " matches." << endl;
            minCut(source, dest); // Pass the current team (k) to minCut function
            for (int m = 0; m < minCutArray.size(); m++)
                cout << teamNames[minCutArray[m]] << "-----" << endl; // Print team names instead of indices
        }
        else
        {
            int tmp = edmond_karp(source, dest);

            for (int i = 1; i <= nodes; i++)
            {
                if (flowCapacity[source][i] != 0)
                {
                    cout << teamNames[k] << " is eliminated. " << endl;
                    cout << "They can win at most " << wins[k] << "+" << remaining[k] << " matches." << endl;
                    break;
                }
            }
            if (tmp == nodes * 10000)
            {
                cout << teamNames[k] << " is eliminated. " << endl;
                cout << "They can win at most " << wins[k] << "+" << remaining[k] << " matches." << endl;
            }
        }
    }
    return 0;
}
