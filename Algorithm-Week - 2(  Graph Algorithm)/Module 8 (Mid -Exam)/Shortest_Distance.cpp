#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    ll n, e;
    cin >> n >> e;
    ll graph[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            graph[i][j] = 1e18;
            if (i == j)
            {
                graph[i][j] = 0;
            }
        }
    }
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        // graph[a][b] = c;
        if (graph[a][b] != 1e18)
        {
            if (graph[a][b] > c)
                graph[a][b] = c;
        }
        else
        {
            graph[a][b] = c;
        }
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (graph[i][k] + graph[k][j] < graph[i][j])
                {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }
        }
    }

    int q;
    cin >> q;
    while (q--)
    {
        ll x, y;
        cin >> x >> y;
        if (graph[x][y] != 1e18)
        {
            cout << graph[x][y] << endl;
        }

        else
        {

            cout << "-1" << endl;
        }
    }
    return 0;
}