//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool vis[100001];
    int ans = 0;
    int parentArray[100001];

    void dfs(int parent, vector<int> adj[])
    {
        vis[parent] = true;
        for (int child : adj[parent])
        {
            if (vis[child] == true && parentArray[parent] != child)
            {
                ans = 1;
            }
            if (vis[child] == false)
            {
                parentArray[child] = parent;
                dfs(child, adj);
            }
        }
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        // const int N= 1e5;

        memset(vis, false, sizeof(vis));
        memset(parentArray, -1, sizeof(parentArray));
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
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends