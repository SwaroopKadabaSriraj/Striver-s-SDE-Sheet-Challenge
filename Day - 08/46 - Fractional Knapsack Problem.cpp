/*CodeStudio solution*/

#include <bits/stdc++.h>

bool comparator(pair<int,int>a,pair<int,int>b){
    double r1=(double)a.second/(double)a.first;
    double r2=(double)b.second/(double)b.first;
    return r1>r2;
}
double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comparator);
    
    int currWeight=0;
    double finalValue=0.0;
    
    for(int i=0;i<n;i++){
        if(currWeight+items[i].first<=w){
            currWeight+=items[i].first;
            finalValue+=items[i].second;
        }
        else{
            int remain=w-currWeight;
            finalValue+=((double)items[i].second/(double)items[i].first)*(double)remain;
            break;
        }
    }
    return finalValue;
}
/*GeeksforGeeks solution*/

#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


 // } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/

class Solution
{
    public:
    bool static comparison(Item a,Item b){
        double r1=(double)a.value/(double)a.weight;
        double r2=(double)b.value/(double)b.weight;
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr,arr+n,comparison);
        double profit=0;
        for(int i=0;i<n;i++){
            if(W-arr[i].weight>=0){
                W= W-arr[i].weight;
                profit += arr[i].value;
            }
            else{
                profit += W*((double)arr[i].value/(double)arr[i].weight);
                W=0;
                break;
            }
        }
        
        return profit;
    }
        
};


// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  // } Driver Code Ends
