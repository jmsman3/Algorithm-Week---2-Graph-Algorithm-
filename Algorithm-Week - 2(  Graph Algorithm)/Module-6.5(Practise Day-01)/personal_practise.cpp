class Solution
{
public:
    bool pathVisit[10001];
    bool vis[10001];
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
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here

        int ans = 0;

        for (int i = 0; i < V; i++)
        {
            if (vis[i] == false)
            {
                dfs(child, adj);
            }
        }
        return ans;
    }
};