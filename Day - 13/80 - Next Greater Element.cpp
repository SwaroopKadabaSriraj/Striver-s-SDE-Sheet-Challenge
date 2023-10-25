/*CodeStudio solution*/

#include<bits/stdc++.h>
using namespace std;
 vector < int > nextGreater(vector < int > & nums,int n) {
      vector < int > nge(n, -1);
      stack < int > st;
      for (int i = n - 1; i >= 0; i--) {
          while (!st.empty() && st.top() <= nums[i ]) {
              st.pop();
          }
          if (i < n) {
              if (!st.empty()) 
                  nge[i] = st.top();
          }
          st.push(nums[i]);
      }
      return nge;
    
};

/*Leetcode solution*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> s;
        unordered_map<int, int> m;
        for (int n : nums) {
            while (s.size() && s.top() < n) {
                m[s.top()] = n;
                s.pop();
            }
            s.push(n);
        }
        vector<int> ans;
        for (int n : findNums) 
            ans.push_back(m.count(n) ? m[n] : -1);
        return ans;
    }
};
