/*CodeStudio solution*/

#include <bits/stdc++.h>
void solve(vector<vector<int>>&adj,vector<int>&indeg,vector<int>&ans,queue<int>&q){
   while(!q.empty()){
       int t=q.front();
       q.pop();
       ans.push_back(t);       
       for(auto it:adj[t]){
           indeg[it]--;
           if(indeg[it]==0){
               q.push(it);
           }
       }
   }
   return ;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v+1,vector<int>());
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    
    vector<int>indeg(v+1,0);
    queue<int>q;
    vector<int>ans;

    for(int i=0;i<v;i++){
        for(int j=0;j<adj[i].size();j++){
            indeg[adj[i][j]]++;
        }
    }
    for(int i=0;i<v;i++){
        if(indeg[i]==0){
            q.push(i);
        }
    }
    if(!q.empty()) 
        solve(adj,indeg,ans,q);
    return ans;
}

/*GeeksforGeeks solution*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	stack<int> S;
    void dfs(int i,vector<int> adj[],vector<int> &vis)
    {
        if(vis[i]==1)
            return;
        for(int x:adj[i])
        {
            dfs(x,adj,vis);
        }
        vis[i]=1;
        S.push(i);
    }
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
            {
                dfs(i,adj,vis);
            }
        }
        
        vector<int> res;
        while(!S.empty())
        {
            res.push_back(S.top());
            S.pop();
        }
        return res;
    	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends
