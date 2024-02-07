#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long graph[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == -1)
                graph[i][j] = INT_MAX;
        }
    }
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i != j && i != k && j != k && graph[i][k] != INT_MAX &&
                 graph[k][j] != INT_MAX && (graph[i][k] + graph[k][j]) < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    long long mx = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != INT_MAX)
            {
                mx = max(mx, graph[i][j]);
            }
        }
    }
    // if (mx == INT_MAX)
    //     mx = 0;
    cout << mx << "\n";
    return 0;
}





 //  if (adj[u][v] != N)
    // {
    //     if (adj[u][v] > c)
    //         adj[u][v] = c;
    // }