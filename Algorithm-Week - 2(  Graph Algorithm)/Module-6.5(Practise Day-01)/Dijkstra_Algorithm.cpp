#include <bits/stdc++.h>
using namespace std;
const int N = 100;
vector<pair<int, int>>graph[N];
int dis[N];
class cmp
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
};
void dijkstra(int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    pq.push({src, 0});
    dis[src] = 0;
    while (!pq.empty())
    {
        pair<int, int> parent = pq.top();
        pq.pop();
        int node = parent.first;
        int cost = parent.second;
        for (pair<int, int> child : graph[node])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (cost + childCost < dis[childNode])
            {
                dis[childNode] = cost + childCost;
                pq.push({childNode, dis[childNode]});
            }
        }
    }
}
int main()
{
    int n, s, f;
    cin >> n >> s >> f;
    int mat[n + 1][n + 1];

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] > 0)
            {
                graph[i].push_back({j, mat[i][j]});
            }
        }
    }

    for (int i = 0; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    dijkstra(s);

    if (dis[f] == INT_MAX)
    {
        cout << -1 << " ";
    }
    else
    {
        cout << dis[f] << " ";
    }

    return 0;
}