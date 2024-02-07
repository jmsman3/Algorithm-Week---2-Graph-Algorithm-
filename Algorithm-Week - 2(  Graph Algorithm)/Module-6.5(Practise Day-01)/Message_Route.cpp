#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bool vis[N];
int parent[N];
vector<int> v[N];
int level[N];
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    level[src] = 0;
    while (!q.empty())
    {
        int par = q.front();
        q.pop();
        for (int child : v[par])
        {
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                level[child] = level[par] + 1;
                parent[child] = par;
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent, -1, sizeof(parent));
    bfs(1);

    if (vis[n] == true)
    {
        int cnt = 0;
        vector<int> path;
        int x = n;
        while (x != -1)
        {
            path.push_back(x);
            x = parent[x];
            cnt++;
        }
        reverse(path.begin(), path.end());
        cout << cnt << endl;

        for (int nodes : path)
        {
            cout << nodes << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}