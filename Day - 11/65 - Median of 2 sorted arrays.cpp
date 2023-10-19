/*CodeStudio solution*/

#include<bits/stdc++.h>
double median(vector<int> a, vector<int> b)
{
    // Write your code here.
    if(b.size() < a.size()) return median(b,a);
   int n1= a.size();
   int n2 = b.size();
   
   int low = 0;
   int high = n1;
   while(low<=high){
       int count1 = (low+ high)/2;
       int count2 = ((n1+n2 +1)/2) - count1;
       
       int l1 = count1==0 ? INT_MIN : a[count1-1];
       int l2 = count2 ==0 ? INT_MIN : b[count2-1];
       
       int r1 = count1 == n1 ? INT_MAX : a[count1];
       int r2 = count2 == n2 ? INT_MAX : b[count2];
       
       
       if(l1 <= r2 && l2 <= r1){
           if((n1+n2) %2 == 0){
               return double(((double)max(l1,l2) + (double)(double)min(r1,r2))/2);
               
           }
           else {
               return max(l1,l2);
           }
       }
       else if(l1 > r2){
           high = count1-1;
       }
       else{
           low = count1+1;
       }
   }
   
   return 0.0;
}

/*Leetcode solution*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        
        if(m<n)
            return findMedianSortedArrays(nums2, nums1);
        
        int s = 0;
        int e = n;
        int total = n+m;
        
        while(s<=e) {
            int mid1 = (s+e)/2;
            int mid2 = (total+1)/2 - mid1;
            
            int l1 = (mid1 == 0 ? INT_MIN : nums1[mid1-1]);
            int l2 = (mid2 == 0 ? INT_MIN : nums2[mid2-1]);
            
            int r1 = (mid1 == n ? INT_MAX : nums1[mid1]);
            int r2 = (mid2 == m ? INT_MAX : nums2[mid2]);
            
            if(l1<=r2 && l2<=r1) {
                if(total % 2 == 0)
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                else
                    return max(l1, l2);
            }
            else if(l1 > r2)
                e = mid1-1;
            else
                s = mid1+1;
        }
        return 0.0;
    }
};
