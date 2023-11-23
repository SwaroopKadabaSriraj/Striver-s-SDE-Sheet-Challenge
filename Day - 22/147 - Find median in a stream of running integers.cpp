/*CodeStudio solution*/

#include<bits/stdc++.h>

vector<int> findMedian(vector<int> &arr, int n){
    priority_queue<int> maxheap;
    priority_queue<int, vector<int> , greater<int>> minheap;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
 
        if(i%2==0)
        {
            minheap.push(arr[i]);
            maxheap.push(minheap.top());
            minheap.pop();
            vec.push_back(maxheap.top());
        }
        else
        {
            maxheap.push(arr[i]);
            minheap.push(maxheap.top());
            maxheap.pop();
            int num = (maxheap.top() + minheap.top())/2;
            vec.push_back(num);
        }
    }
    return vec;
}


/*Leetcode solution*/

class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        nums.insert(num);
        is_even = !is_even;
        if (it == nums.end() || (is_even && (*it) <= num)) it++;
        if (!is_even && (*it) > num) it--;
    }
    
    double findMedian() {
        return (!is_even)? *it : (*it + *prev(it)) / 2.0;
    }
    
private:
    multiset<int> nums;
    multiset<int>::iterator it = nums.begin();
    bool is_even = true;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
