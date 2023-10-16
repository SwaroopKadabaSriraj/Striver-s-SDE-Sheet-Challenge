/*CodeStudio solution*/

#include <bits/stdc++.h>

void func(int index,int target,vector<int>&arr,int n,vector<int>&temp,vector<vector<int>>&ans){
    if(target==0){
        ans.push_back(temp);
        return ;
    }
    for(int i=index;i<n;i++){
        if(i>index && arr[i]==arr[i-1]){
            continue;
        }
        if(arr[i]>target){
            break;
        }
        temp.push_back(arr[i]);
        func(i+1,target-arr[i],arr,n,temp,ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>temp;
    func(0,target,arr,n,temp,ans);
    return ans;
}

/*Leetcode solution*/

class Solution {
public:
    void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
    {
        if(target==0)
        {
            res.push_back(local);
            return;
        }
        for(int i = order;i<num.size();i++)
        {
            if(num[i]>target) return;
            if(i&&num[i]==num[i-1]&&i>order) continue;
            local.push_back(num[i]),
            findCombination(res,i+1,target-num[i],local,num);
            local.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        sort(candidates.begin(),candidates.end());
        vector<int> local;
        findCombination(res, 0, target, local, candidates);
        return res;
    }
};
