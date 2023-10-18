/*CodeStuudio solution*/

int numbersLessThan(vector<int> &row1, vector<int> &row2,int n)
{
    int ans=0;
    auto it1=upper_bound(row1.begin(),row1.end(),n);
    auto it2=upper_bound(row2.begin(),row2.end(),n);
    
    ans+=it1-row1.begin();
    ans+=it2-row2.begin();
    
    return ans;
}

int ninjaAndLadoos(vector<int> &row1, vector<int> &row2, int m, int n, int k) {
    int low=min(row1[0],row2[0]);
    int high=max(row1[m-1],row2[n-1]);
    
    while(low<=high)
    {
        int mid=(low+high)/2;
        
        if(numbersLessThan(row1,row2,mid)<k)
            low=mid+1;
        else
            high=mid-1;
    }
    return low;
}


/*GeeksforGeeks solution*/

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int i=0, j=0, element;
        while(i<n && j<m)
        {
            if(arr1[i] < arr2[j] )
            {
                element=arr1[i];
                k--, i++;
            }
            else
            {
                element=arr2[j];
                k--, j++;
            }
              
            if(k==0)
               return element;
        }
        if(i<n)
            return arr1[i+k-1];
        if(j<m)
            return arr2[j+k-1];
    }
};

//{ Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}
// } Driver Code Ends
