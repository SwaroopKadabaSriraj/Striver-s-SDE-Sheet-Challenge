/*CodeStudio solution*/

bool dfs(vector<vector<int>> &maze,int i,int j,vector<vector<int>> &ans,int n,vector<vector<int>> &res){
   if(i<0 || j<0 || i>=n || j>=n || maze[i][j]==0 || ans[i][j]==1)
       return 0;
   if(i==n-1 && j==n-1 && maze[i][j]==1){
       vector<int> path;
       ans[i][j]=1;
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               path.push_back(ans[i][j]);
           }
       }
       res.push_back(path);
   }
   
   ans[i][j]=1;
   dfs(maze,i+1,j,ans,n,res);
   dfs(maze,i-1,j,ans,n,res);
   dfs(maze,i,j+1,ans,n,res);
   dfs(maze,i,j-1,ans,n,res);
   ans[i][j]=0;
}
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
    vector<vector<int>> ans(n,vector<int>(n,0));
    vector<vector<int>> res;

    dfs(maze,0,0,ans,n,res);
    return res;
}


/*GeeksforGeeks solution*/

// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    vector<vector<int>>vis;
    string s ="";
    map<int,char>mp = {{1,'L'},{2,'R'},{3,'U'},{4,'D'}};
    bool fun(vector<vector<int>> &m, int n,string s,int x = 0,int y=0,int k = -1){
        if(x<0 || y<0 || x>=n || y>=n || vis[x][y] || m[x][y]==0) return 0;
        if(k!=-1) s+=mp[k];
        if(x==n-1 && y==n-1) 
            ans.push_back(s);
        vis[x][y]=1;
          fun(m,n,s,x-1,y,3);
          fun(m,n,s,x+1,y,4);
          fun(m,n,s,x,y-1,1);
          fun(m,n,s,x,y+1,2);
        vis[x][y]=0;
       return 1;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
       for(auto x:vis) x.clear();
       vis.resize(n,vector<int>(n,0));
       fun(m,n,s);
       return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
