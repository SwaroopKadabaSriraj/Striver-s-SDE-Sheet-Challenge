/*CodeStudio solution*/

#include <bits/stdc++.h>

void adder(vector<int>& t,int v,int e,int x,unordered_map<int,vector<int>> con,vector<int>& c){
    c[x] = 1;
    t.push_back(x);

    for(int i=0;i<con[x].size();i++){
        if(!c[con[x][i]]){
            adder(t,v,e,con[x][i],con,c);
        }
    }
    return;
}

vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges)
{
    vector<vector<int>> ans;
    vector<int> c(v,0);

    unordered_map<int,vector<int>> con;
    
    for(int i=0;i<e;i++){
        int a,b;
        a = edges[i][0];b = edges[i][1];
        con[a].push_back(b);
        con[b].push_back(a);
    }

    for(int i=0;i<v;i++){
        if(!c[i]){
            vector<int> t;
            adder(t,v,e,i,con,c);
            sort(t.begin(),t.end());
            ans.push_back(t);
        }
    }
    return ans;
}

/*GeeksforGeeks solution*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void DFS(vector<int>adj[],int s,bool visited[],vector<int> &ans)
    {
        visited[s]=true;
        ans.push_back(s);
       
        for(auto x: adj[s])
        {
            if(visited[x]==false)
            DFS(adj,x,visited,ans);
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int>ans;
        bool visited[V];
      
        for(int i=0;i<V;i++)
            visited[i]=false;
       
        DFS(adj,0,visited,ans);
        return ans;

    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
