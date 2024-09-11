//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs1(int ind, vector<int> &vis,  stack<int> &st, vector<vector<int>> &adj) {
	    vis[ind] = 1;
	    for (auto it: adj[ind]) {
	        if (!vis[it]) dfs1(it, vis, st, adj);
	    }
	    st.push(ind);
	}
	void dfs2(int ind, vector<int> &vis, vector<vector<int>> &adj) {
	    vis[ind] = 1;
	    for (auto it: adj[ind]) {
	        if (!vis[it]) dfs2(it, vis, adj);
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> st;
        vector<int> vis(V+1, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs1(i, vis, st, adj);
        }
        fill(vis.begin(), vis.end(), 0);
        int ans = 0;
        vector<vector<int>> tempAdj(V);
        for (int i = 0; i < V; i++) {
            for (auto it: adj[i]) {
                tempAdj[it].push_back(i);
            }
        }
        while(!st.empty()) {
            int i = st.top();
            st.pop();
            if (!vis[i]) {
                ans++;
                dfs2(i, vis, tempAdj);
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
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends