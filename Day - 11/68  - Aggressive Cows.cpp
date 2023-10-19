/*CodeStudio solution*/

bool canPlace(int dist,int c,vector<int> positions,int n){
    int ninjasplaced=1;
    int recentplacedat=0;
    for(int i=1;i<n;i++){
        if(positions[i]-positions[recentplacedat] >= dist){
            ninjasplaced++;
            recentplacedat=i;
        }
    }
    if(ninjasplaced>=c){
        return true;
    }else{
        return false;
    }
}


int chessTournament(vector<int> positions , int n ,  int c){
    sort(positions.begin(),positions.end());
    int l=0;
    int h=positions[n-1]-positions[0];
    int ans=0;
    while(l<=h){
        int mid=(l+h)/2;
        if(canPlace(mid,c,positions,n)){
            ans=mid;
            l=mid+1;
        }else{
            h=mid-1;
        }
    }
    
    return ans;
}

/*SPOJ solution*/

#include <bits/stdc++.h>
using namespace std;

bool isPossible(int a[], int n, int cows, int minDist) {
	int cntCows = 1;
	int lastPlacedCow = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] - lastPlacedCow >= minDist) {
			cntCows++;
			lastPlacedCow = a[i];
		}
	}
	if (cntCows >= cows) 
		return true;
	return false;
	
}

int main() {
	// your code goes here
	int t, n, cows;
	cin >> t;
	while(t--){
		cin >> n >> cows;
		int a[n];
		for(int i=0; i<n; i++)
			cin >> a[i];
		sort(a, a + n);
		int low = 1, high = a[n - 1] - a[0];
		while (low <= high) {
			int mid = (low + high) >> 1;
			
			if (isPossible(a, n, cows, mid)) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		cout << high << endl;
	}
	return 0;
}
