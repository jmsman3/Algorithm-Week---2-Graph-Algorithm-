#include <bits/stdc++.h>
using namespace std;
bool vis[1005][1005];
int dis[1005][1005];
vector<pair<int, int>> d = {{-2, 1}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, 2}, {-1, -1}};
int n, m;
char a[1005][1005];
bool valid(int i, int j)
{
    if (i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
void bfs(int si, int sj)
{
    queue<pair<int, int>> q;
    q.push({si, sj});
    vis[si][sj] = true;
    dis[si][sj] = 0;
    while (!q.empty())
    {
        pair<int, int> par = q.front();
        int a = par.first;
        int b = par.second;
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int ci = a + d[i].first;
            int cj = b + d[i].second;
            if (valid(ci, cj) == true && vis[ci][cj] == false)
            {
                q.push({ci, cj});
                vis[ci][cj] = true;
                dis[ci][cj] = dis[a][b] + 1;
            }
        }
    }
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        int si, sj;
        cin >> si >> sj;
        int dis1, dis2;
        cin >> dis1 >> dis2;

        //   memset(dis, -1, sizeof(dis));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dis[i][j] = INT_MAX;
            }
        }
        memset(vis, false, sizeof(vis));

        bfs(si, sj);
        
        if (vis[dis1][dis2] == false)
        {
            cout << "-1" << endl;
        }
        else
        {
            cout << dis[dis1][dis2] << endl;
        }
    }

    return 0;
}