#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
bool vis[N];
bool pathVisit[N];
bool ans;
void dfs(int parent)
{
    vis[parent] = true;
    pathVisit[parent] = true;
    for (int child : adj[parent])
    {
        if (pathVisit[child])
        {
            ans = true;
        }
        if (vis[child] == false)
        {
            dfs(child);
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
        adj[a].push_back(b);
        // as direct Graph
    }

    memset(vis, false, sizeof(vis));
    memset(pathVisit, false, sizeof(pathVisit));
    ans = false;

    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            dfs(i);
        }
    }

    if (ans)
    {
        cout << "Detect Cycle";
    }
    else
    {
        cout << "Cycle Detected Not";
    }

    return 0;
}