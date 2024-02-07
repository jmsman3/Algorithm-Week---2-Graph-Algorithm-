#include <bits/stdc++.h>
using namespace std;
#define ll long long int
class Edge
{
public:
    ll u, v, c;
    Edge(ll u, ll v, ll c)
    {
        this->u = u;
        this->v = v;
        this->c = c;
    }
};
const ll N = 1005;
ll dis[N];
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<Edge> EdgeList;
    while (e--)
    {
        ll u, v, c;
        cin >> u >> v >> c;
        EdgeList.push_back(Edge(u, v, c));
    }

    ll src;
    cin >> src;
    for (int i = 1; i <=n; i++)
    {
        dis[i] = 1e18;
    }
    dis[src] = 0;

    for (int i = 1; i <= n; i++)
    {
        for (Edge ed : EdgeList)
        {
            int u = ed.u, v = ed.v, c = ed.c;
            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                dis[v] = dis[u] + c;
            }
        }
    }
    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        for (Edge ed : EdgeList)
        {
            ll u = ed.u, v = ed.v, c = ed.c;

            if (dis[u] < 1e18 && dis[u] + c < dis[v])
            {
                cycle = true;
                break;
            }
        }
    }
    if (cycle)
    {
        cout << "Negative Cycle Detected";
        return 0;
    }

    int t;
    cin >> t;
    while (t--)
    {
        ll distance;
        cin >> distance;

        if (dis[distance] < 1e18)
        {
            cout << dis[distance] << endl;
        }
        else
        {
            cout << "Not Possible" << endl;
        }
    }

    return 0;
}