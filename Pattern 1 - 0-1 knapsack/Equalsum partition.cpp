// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    bool helper(int index , int target , int arr[], vector<vector<int>> &dp){
        if(target==0)
            return true;
        if(index==0){
            return (arr[0]==target);
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        //not take case
        int right = helper(index-1,target,arr,dp);
        //takemcase 
        int left=false;
        if(arr[index]<=target){
            left=helper(index-1,target-arr[index],arr,dp);
        }
        
        return dp[index][target] =  left || right ;
    }

    int equalPartition(int n, int arr[])
    {
        // let we check its sum is odd or even 
        long long int sum = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        if(sum%2) return 0;
        //recursion 
        // memoization 
        vector<vector<int>> dp(n,vector<int>((sum/2)+1,-1));
        return helper(n-1,sum/2,arr,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends