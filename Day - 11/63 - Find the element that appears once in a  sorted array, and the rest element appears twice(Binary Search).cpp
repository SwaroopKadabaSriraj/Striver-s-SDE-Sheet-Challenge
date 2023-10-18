/*CodeStudio solution*/

int uniqueElement(vector<int> arr, int n)
{
	// Write your code here
    int xr{};
    for(auto num: arr)
        xr = xr^num;
    return xr;
}

/*Leetcode solution*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int xr{};
        for(auto num: nums)
            xr = xr^num;
        return xr;
    }
};
