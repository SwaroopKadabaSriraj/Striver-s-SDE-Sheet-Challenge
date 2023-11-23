/*CodeStudio solution*/

#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int K)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    return arr[size-K];
}

/*Leetcode solution*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()-k];
    }
};
