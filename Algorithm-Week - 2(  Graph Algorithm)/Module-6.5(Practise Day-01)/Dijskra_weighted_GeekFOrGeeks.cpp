//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    int dis[1001];

public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex S.
    class cmp
    {
    public:
        bool operator()(pair<int, int> a, pair<int, int> b)
        {
            return a.second > b.second;
        }
    };
    void dijskra(int src, vector<vector<int>> adj[])
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

            for (int i = 0; i < adj[node].size(); i++)
            {
                int childNode = adj[node][i][0];
                int childCost = adj[node][i][1];

                if (cost + childCost < dis[childNode])
                {
                    dis[childNode] = cost + childCost;
                    pq.push({childNode, dis[childNode]});
                }
            }
        }
    }
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        vector<int> ppp;
        // memset( dis,INT_MAX,sizeof(dis));
        for (int i = 0; i < V; i++)
        {
            dis[i] = INT_MAX;
        }
        dijskra(S, adj);
        for (int i = 0; i < V; i++)
        {
            ppp.push_back(dis[i]);
        }
        return ppp;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin >> S;

        Solution obj;
        vector<int> res = obj.dijkstra(V, adj, S);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends