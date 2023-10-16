/*CodeStudio solution*/

#include <bits/stdc++.h>
bool isPalindrome(string &s,int start,int end){
    while(start<=end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void func(int index , string &s,vector<vector<string>>&ans,vector<string>&path)
{
    if(index==s.size()){
        ans.push_back(path);
        return;
    }
    for(int i=index;i<s.size();i++){
        if(isPalindrome(s,index,i)){
            path.push_back(s.substr(index,i-index+1));
            func(i+1,s,ans,path);
            path.pop_back();
        }
    }
    
}

vector<vector<string>> partition(string &s) 
{
    vector<vector<string>>ans;
    vector<string>path;
    func(0,s,ans,path);
    return ans;
}

/*Leetcode solution*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string> > ret;
        if(s.empty()) return ret;
        
        vector<string> path;
        dfs(0, s, path, ret);
        
        return ret;
    }
    
    void dfs(int index, string& s, vector<string>& path, vector<vector<string> >& ret) {
        if(index == s.size()) {
            ret.push_back(path);
            return;
        }
        for(int i = index; i < s.size(); ++i) {
            if(isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1));
                dfs(i+1, s, path, ret);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(const string& s, int start, int end) {
        while(start <= end) {
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
};
