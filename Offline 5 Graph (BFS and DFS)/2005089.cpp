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
int bi_arr[200];
int bi_flag=0;

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
                bi_arr[bi_flag] = source;
                bi_flag++;
                bi_arr[bi_flag] = i;
                bi_flag++;


                d_v[d_flag] = i;
                d_flag++;
                dfs(i,vertices);

            }
        }

    }



    int is_bipartite(int i,int j, int vertices)
    {
        for(int n = 0 ; n<vertices; n++)
        {
            if(graph[i][n] == 1 && graph[j][n] == 1)
                return -1;
            else if(graph[n][i] == 1 && graph[j][n] == 1)
                return -1;
        }

        return 1;

    }

    int check_bipartite(int vertices)
    {
        for(int i = 0 ; i<vertices; i++)
        {
            for( int j = 0 ; j<vertices ; j++)
            {
                int tmp = is_bipartite(i,j,vertices);
                if(tmp == - 1)
                    return -1;
            }
        }

        return 1;
    }




};


int main()
{
    FILE *fp;
    ifstream in;
    fp = freopen("output_online.txt","w",stdout);
    in.open("input_online.txt");

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
        graph[epoint][spoint] = 1;
    }

    source = 1;
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

    cout << "BIPARTITE STATUS : " ;

    int flag = gp.check_bipartite(vertices);
    if(flag == -1)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;

}



