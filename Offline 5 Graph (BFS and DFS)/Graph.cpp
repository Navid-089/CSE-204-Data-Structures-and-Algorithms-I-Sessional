#include <iostream>
#include <fstream>
#include "QueueArray.cpp"
using namespace std;

int graph[100][100];
int visited[100];
int d_visited[100];
int d_v[100];
int d_flag=2;
Queue <int> q(100);

class Graph
{

public:
    Graph() {}
    void bfs(int source,int vertices)
    {
        cout << "BFS :\n\nEdges: {";

        int v[100];
        v[1] = source;
        int flag = 2;
        visited[source] = 1;
        q.enqueue(source);
        while(q.length() != 0)
        {
            int tmp = q.dequeue();
            for(int i = 1; i<=vertices ; i++)
            {
                if(graph[tmp][i] == 1 && visited[i] == 0)
                {
                    cout << "(" << tmp << "," << i << "),";
                    v[flag] = i;
                    visited[i] = 1;
                    q.enqueue(i);
                    flag++;
                }
            }
        }
        cout << "}" <<  endl;

        cout << "Traversal: " ;
        for(int i = 1; i<flag; i++)
            cout << v[i] << " ";
        cout << endl;
    }

    void dfs(int source, int vertices)
    {
        d_visited[source] = 1;

        for(int i=1; i<= vertices ; i++)
        {
            if(graph[source][i] == 1 && d_visited[i] == 0)
            {
                cout << "(" << source << "," << i << "),";
                d_v[d_flag] = i;
                d_flag++;
                dfs(i,vertices);

            }
        }
    }

};


int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output.txt","w",stdout);
    in.open("input.txt");

    int vertices, edges;
    int spoint,epoint;
    int source;

    in >> vertices >> edges;

    for(int i = 0 ; i<=vertices ; i++)
        visited[i] = 0;

    for(int i=0; i<=vertices; i++)
        for(int j=0; j<=vertices; j++)
            graph[i][j] = 0;

    // taking the vertices to be starting from 1
    for(int i = 0; i<edges ; i++)
    {
        in >> spoint >> epoint;
        graph[spoint][epoint] = 1;
    }

    in >> source;
    d_v[1] = source; // needs to be handled
    Graph gp;

    gp.bfs(source,vertices);
    cout << "\n\nDFS:\n\nEdges: {";
    gp.dfs(source,vertices);
    for(int i = 1 ; i<=vertices; i++)
    {
        if(d_v[i] == 0)
        {
             d_v[d_flag] = i;
             d_flag++;
             gp.dfs(i,vertices);
        }
    }
    cout << "}" << endl;

cout << "Traversal: " ;
    for(int i = 1; i<d_flag; i++)
        cout << d_v[i] << " ";
    cout << endl;

    return 0;

}



