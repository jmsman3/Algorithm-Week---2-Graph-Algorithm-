#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int> V[N];
bool vis[N];
int parent_array[N];
bool ans;
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src] = true;
    while (!q.empty())
    {
        int parent = q.front();
        q.pop();
        for (int child : V[parent])
        {
            if (vis[child] == true && parent_array[parent] != child)
            {
                ans = true;
            }
            if (vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                parent_array[child] = parent;
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
        V[a].push_back(b);
        V[b].push_back(a);
    }
    memset(vis, false, sizeof(vis));
    memset(parent_array, -1, sizeof(parent_array));

    ans = false;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == false)
        {
            bfs(i);
        }
    }
    if (ans)
    {
        cout << "Cycle Found";
    }
    else
    {
        cout << "cycle Not Found";
    }
    return 0;
}