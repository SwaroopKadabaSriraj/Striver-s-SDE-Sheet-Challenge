/*CodeStudio solution*/

#include<bits/stdc++.h>
struct meeting{
    int startTime;
    int endTime;
    int pos;
};
bool comparator(struct meeting m1,meeting m2){
    if(m1.endTime < m2.endTime) 
        return true;
    else if(m1.endTime > m2.endTime) 
        return false;
    else if(m1.pos < m2.pos) 
        return true;
    else 
        return false;
}
vector<int> maximumMeetings(vector<int> &start, vector<int> &end) {
    // Write your code here.
    int n=start.size();
    struct meeting meet[n];
    for(int i=0;i<n;i++){
        meet[i].startTime = start[i];
        meet[i].endTime = end[i];
        meet[i].pos = i+1;
    }
    sort(meet, meet+n, comparator);
    vector<int> ans;
    int ending = meet[0].endTime;
    ans.push_back(meet[0].pos);
    for(int i=1; i<n; i++){
        if(meet[i].startTime > ending){
            ending = meet[i].endTime;
            ans.push_back(meet[i].pos);
        }
    }
    return ans;
}

/*GeeksForGeeks solution*/

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({end[i],start[i]});
        }
        sort(temp.begin(),temp.end());
        int ans = 1;
        int flag = temp[0].first; 
        for(int i=1;i<n;i++){
            if(temp[i].second > flag){
                ans++;
                flag = temp[i].first;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends
