/*CodeStudio solution*/

bool isPossible(int n, int m, vector<int> time,long long int mid){
   int dayCount = 1;
   long long int timeSum = 0;
   for(int i=0;i<m;i++){
       if(timeSum+time[i]<=mid){
           timeSum+=time[i];
       }else{
           dayCount++;
           if(dayCount>n || time[i]>mid){
               return false;
           }
           timeSum=time[i];
       }
   }
   return true;
}

long long ayushGivesNinjatest(int n, int m, vector<int> time) {  
   // Write your code here.
   long long int s=0;
   long long int sum=0;
   long long int ans=-1;
   for (int i=0;i<m;i++){
       sum+=time[i];
   }
   long long int e = sum;
   long long int mid = s + (e-s)/2;
   while(s<=e){
       if(isPossible(n,m,time,mid)){
           e=mid-1;
           ans=mid;
       }else{
           s=mid+1;
       }
       mid = s + (e-s)/2;
   }
   return ans;
}


/*InterviewBit solution*/

bool good(vector<int> A, int m, int mid){
    if(A[0]>mid){
        return false;
    }
    int n = A.size();
    int cnt = 1, s = A[0];
    for(int i = 1;i<n;i++){
        if(A[i]>mid){
            return false;
        }
        if((A[i]+s)<=mid){
            s+=A[i];
        }
        else{
            s = A[i];
            cnt++;
        }
    }
    if(cnt>m){
        return false;
    }
    return true;
}

int Solution::books(vector<int> &A, int B) {
    if(A.size()<B){
        return -1;
    }
    int sum = 0, ans = -1;
    for(int i = 0;i<A.size();i++){
        sum+=A[i];
    }
    int low = 0, high = sum;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(good(A, B, mid)){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
