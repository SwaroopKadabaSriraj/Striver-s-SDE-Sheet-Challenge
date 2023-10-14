/*CodeStudio solution*/

void Sum(vector<int> &arr,int n,int i,int k, vector<int> &v,vector<vector<int>>&ans) {
    if(k==0) {
        ans.push_back(v);
    }
    if(i>=n) return ;
    for(;i<n;i++) {
        v.push_back(arr[i]);
        Sum(arr,n,i+1,k-arr[i],v,ans);
        v.pop_back();
    }
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{  
    vector<vector<int>> ans;
    vector<int> v;
    Sum(arr,n,0,k,v,ans);
    return ans;
}

/*Leetcode solution*/

class Solution {
public:
    void Sum(vector<int>& candidates, int target, vector<vector<int> >& res, vector<int>& r, int i)
    {
        if(target == 0)
        {
            res.push_back(r);
            return;
        }
        
        while(i <  candidates.size() && target - candidates[i] >= 0)
        {
            r.push_back(candidates[i]);
            Sum(candidates,target - candidates[i],res,r,i);
            ++i;
            
            r.pop_back();
        }
}
    
     
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        candidates.erase(unique(candidates.begin(),candidates.end()),candidates.end());
        
        vector<int> r;
        vector<vector<int> > res;
        
        Sum(candidates,target,res,r,0);
        
        return res;
    }
};
