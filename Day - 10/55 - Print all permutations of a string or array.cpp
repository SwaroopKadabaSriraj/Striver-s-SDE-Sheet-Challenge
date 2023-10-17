/*CodeStudio solution*/

void findpermutations(int index, string&s, vector<string>&ans)
{
    if(index==s.size())
    {
        ans.push_back(s);
        return;
    }
    for(int i=index;i<s.size();i++)
    {
        swap(s[index],s[i]);
        findpermutations(index+1,s,ans);
        swap(s[index],s[i]);
    }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    int index=0;
    findpermutations(index,s,ans);
    return ans;
}

/*Leetcode solution*/

class Solution {
public:
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
    
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
};class Solution {
public:
	void permuteRecursive(vector<int> &num, int begin, vector<vector<int> > &result)	{
		if (begin >= num.size()) {
		    result.push_back(num);
		    return;
		}
		
		for (int i = begin; i < num.size(); i++) {
		    swap(num[begin], num[i]);
		    permuteRecursive(num, begin + 1, result);
		    swap(num[begin], num[i]);
		}
    }
    
    vector<vector<int>> permute(vector<int>& num) {
        vector<vector<int>> result;
	    permuteRecursive(num, 0, result);
	    return result;
    }
};
