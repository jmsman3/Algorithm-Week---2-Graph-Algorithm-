#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int N = 1e6;
vector<pair<ll, ll>> v[N];
int dis[N];

class cmp
{
public:
    bool operator()(pair<ll, ll> a, pair<ll, ll> b)
    {
        return a.second > b.second;
    }
};

void dijkstra(int src_2)
{
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
    pq.push({ src_2, 0});
    dis[ src_2] = 0;
    while (!pq.empty())
    {
        pair<ll, ll> parent = pq.top();
        pq.pop();
        ll node = parent.first;
        ll cost = parent.second;
        for (pair<ll, ll> child : v[node])
        {
            ll childNode = child.first;
            ll childCost = child.second;
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
    ll n, e;
    cin >> n >> e;
    while (e--)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back({a, c});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }

    ll src_2;
    cin >> src_2;
    dijkstra( src_2);

    int t;
    cin >> t;
    while (t--)
    {
        ll d, dw;
        cin >> d >> dw;
        for (int i = 1; i <= n; i++)
        {
            dis[i] = INT_MAX;
        }
        dijkstra(src_2);
        if (dis[d] <= dw)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}
