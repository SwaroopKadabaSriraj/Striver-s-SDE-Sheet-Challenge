/*CodeStudio solution*/

int findMinimumCoins(int amount) 
{
    // Write your code here
    int arr[] = {1,2,5,10,20,50,100,500,1000};
    int mincoins=0;
    for(int i=8;i>=0;i--){
       if(amount/arr[i]>=1){
           mincoins+=amount/arr[i];
           amount=amount%arr[i];
       }
        if(amount==0) break;
    }
    return mincoins;
}

/*GeeksforGeeks solution*/
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	const int inf = 1e9;
	int minCoins(int coins[], int M, int V) 
	{ 
	    vector<int> dp(V+1,inf);
	    dp[0] = 0;
        for(int i=1; i<=V; i++){
            for(int j=0; j<M; j++){
	            if(i>=coins[j]){
	                dp[i] = min(dp[i],1+dp[i-coins[j]]);
	            }
            }
        }
	    
	    return (dp[V]==inf?-1:dp[V]);
	} 
	  
};

// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends
