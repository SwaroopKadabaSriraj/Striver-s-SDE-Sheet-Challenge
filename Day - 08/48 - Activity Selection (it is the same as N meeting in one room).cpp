#include <bits/stdc++.h>

struct job{
    int start; 
    int end;
};
bool comp(struct job a, struct job b){
    return (a.end < b.end);
}

int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n=start.size();
    struct job v[n];
    
    for(int i=0; i<n; i++){
        v[i].start = start[i];
        v[i].end = finish[i];
    }
    
    sort(v, v+n, comp);
    int ans = 1;
    int end = v[0].end;
    for(int i=1; i<n; i++){
        if(v[i].start >= end){
            end = v[i].end;
            ans++;
        }
    }
    return ans;
}

/*GeeksforGeeks solution*/

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
