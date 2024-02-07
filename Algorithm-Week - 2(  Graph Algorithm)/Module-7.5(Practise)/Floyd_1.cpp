// personal floyd -1
#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long adj[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
            if (adj[i][j] == -1)
            {
                adj[i][j] = INT_MAX;
            }
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (adj[i][k] != INT_MAX && adj[k][j] != INT_MAX &&
                    (adj[i][k] + adj[k][j] < adj[i][j]))
                {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] == INT_MAX)
            {
                cout << -1;
            }
            else
            {
                cout << adj[i][j] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}