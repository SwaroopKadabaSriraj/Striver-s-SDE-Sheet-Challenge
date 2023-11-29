/*CodeStudio solution*/

#include <bits/stdc++.h>
void solve(int i,vector<vector<int>>&adj,vector<int>&vis,vector<int>&ans){
    vis[i]=1;
    
    for(auto it:adj[i]){
        if(!vis[it]){
            solve(it,adj,vis,ans);
        }
    }
    ans.push_back(i);
    return ;
    
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>>adj(v+1,vector<int>());
    
    for(int i=0;i<e;i++){
        adj[edges[i][0]].push_back(edges[i][1]);
    }
    vector<int>vis(v+1,0);
    vector<int>ans;
    for(int i=0;i<v;i++){
        if(!vis[i]){
            solve(i,adj,vis,ans);
        }
    }
    reverse(ans.begin(),ans.end());
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
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector <int> indegree(V, 0);
	    vector <int> topo;
	    for(int i=0; i<V; i++){
	        for(auto j:adj[i])
	            indegree[j]++;
	    }
	    queue <int> q;
	    for(int i=0; i<V; i++){
	        if(indegree[i] == 0)
	            q.push(i);
	    }
	    while(!q.empty()){
	        int t = q.front();
	        q.pop();
	        topo.push_back(t);
	        for(auto i:adj[t]){
	            indegree[i]--;
	            if(indegree[i] == 0)
	                q.push(i);
	        }
	    }
	    return topo;
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
