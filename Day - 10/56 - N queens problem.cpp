/*CodeStudio solution*/

bool possible(vector<vector<int>>&ans,int x,int y)
{
    int n=ans.size();
    for(int i=0;i<x;i++)
    {
        if(ans[i][y]==1)
            return false;
    }
    for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
    {
        if(ans[i][j]==1)
            return false;
    }
    for(int i=x-1,j=y+1;i>=0 && j<n;i--,j++)
    {
        if(ans[i][j]==1)
            return false;
    }
    return true;    
}

bool helper(vector<vector<int>>&output,vector<vector<int>>&ans,int n,int i=0)
{
    if(i>=n)
    {
        vector<int>temp;
        for(auto i:ans)
            for(auto j:i)
                temp.push_back(j);
        output.push_back(temp);
        return false;
    }
        
    for(int j=0;j<n;j++)
    {
          if(possible(ans,i,j))
          {
              ans[i][j]=1;
              bool b=helper(output,ans,n,i+1);
              if(b==false)
                  ans[i][j]=0;
              else
                  return true;
          }
    }
    return false;
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>ans(n,vector<int>(n,0));
    vector<vector<int>>output;
    helper(output,ans,n);
    return output;
}

/*Leetcode solution*/

class Solution {
public:
    vector<vector<string>> ret;
    bool is_valid(vector<string> &board, int row, int col){
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    
    void dfs(vector<string> &board, int row){
        if(row == board.size()){
            ret.push_back(board);
            return;
        }
        for(int i=0;i<board.size();++i){
            if(is_valid(board,row,i)){
                board[row][i] = 'Q';
                dfs(board,row+1);
                board[row][i] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        if(n <= 0) return {{}};
        vector<string> board(n,string(n,'.'));
        dfs(board,0);
        return ret;
    }
};
