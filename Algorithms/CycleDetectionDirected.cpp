#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    bool cycleDFS(int node,vector<int> adj[], vector<int> &vis, vector<int> &dfsvis)
    {
        vis[node]=1;
        dfsvis[node]=1;
        
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
            if(cycleDFS(it,adj,vis,dfsvis))return true;
            }
            else if(dfsvis[it])
            return true;
        }
        dfsvis[node]=0;
        return false;
    }
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   vector<int>vis(V,0);
	   vector<int>dfsvis(V,0);
	   for(int i=0;i<V;i++)
	   {
	       if(!vis[i])
	       {
	           if(cycleDFS(i,adj,vis,dfsvis))
	           return true;
	       }
	   }
	   return false;
	}
	
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
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
