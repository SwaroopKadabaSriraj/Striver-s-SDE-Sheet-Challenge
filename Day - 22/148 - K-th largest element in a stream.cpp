/*CodeStudio solution*/

#include<bits/stdc++.h>
class Kthlargest {
public:
   priority_queue<int,vector<int>,greater<int>>q;
    int size;
    Kthlargest(int k, vector<int> &arr)     
    {
        size=k;
        for(int i=0;i<arr.size();i++)
        {
            q.push(arr[i]);
            if(q.size()>k)
            {
                q.pop();
            }
        }
    }

    void add(int num) {
        q.push(num);
        if(q.size()>size)
        {
            q.pop();
        }
    }

    int getKthLargest() {
      int a= q.top();
     
        return a;
    }

};

/*Leetcode solution*/

class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int> nums) {
        size=k;
        for(int i=0;i<nums.size();i++) {
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size) pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
