//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool pathVisit[100001];
    bool vis[100001];
    int ans = 0;
    void dfs(int parent, vector<int> adj[])
    {
        vis[parent] = true;
        pathVisit[parent] = true;
        for (int child : adj[parent])
        {
            if (pathVisit[child] == true)
            {
                ans = 1;
            }
            if (vis[child] == false)
            {
                dfs(child, adj);
            }
        }
        pathVisit[parent] = false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        memset(vis, false, sizeof(vis));
        memset(pathVisit, false, sizeof(pathVisit));
        ans = 0;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                dfs(i, adj);
            }
        }
        return ans;
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

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends



//4th problem of module 6.5= below:-with comment
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5;

// Global declaration of the adjacency matrix
vector<vector<int>> v;

// Function to perform Dijkstra's algorithm
int dijkstra(int start, int end)
{
    int n = v.size();

    // Initialize distances vector with infinity
    vector<int> distances(n, N);

    // Set the distance of the starting node to 0
    distances[start - 1] = 0;

    // Priority queue to store vertices with their distances
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Push the starting node into the priority queue
    pq.push({0, start});

    // Dijkstra's algorithm
    while (!pq.empty())
    {
        int current_distance = pq.top().first;
        int current_vertex = pq.top().second;
        pq.pop();

        // If the destination is reached, return the distance
        if (current_vertex == end)
        {
            return current_distance;
        }

        // Explore children of the current vertex
        for (int child = 0; child < n; ++child)
        {
            if (v[current_vertex - 1][child] != -1)
            {
                int weight = v[current_vertex - 1][child];
                int distance = current_distance + weight;

                // Relaxation step: Update distance if a shorter path is found
                if (distance < distances[child])
                {
                    distances[child] = distance;
                    pq.push({distance, child + 1});
                }
            }
        }
    }

    // If no path is found, return -1
    return -1;
}

int main()
{
    // Input the number of nodes, start node, and end node
    int n, s, f;
    cin >> n >> s >> f;

    // Input the adjacency matrix of the graph
    v.resize(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> v[i][j];
        }
    }

    // Find the shortest path using Dijkstra's algorithm
    int result = dijkstra(s, f);

    // Output the result
    cout << result << endl;

    return 0;
}
