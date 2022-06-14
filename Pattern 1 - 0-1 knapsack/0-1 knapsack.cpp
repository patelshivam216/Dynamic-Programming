// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int knapsack(int index, int wt[],int val[],int W,vector<vector<int>> &dp){
        if(W==0) return 0;
        if(index==0){
            if(wt[0]<=W) return val[0];
            else return 0;
        }
        if(dp[index][W]!= -1) return dp[index][W];
        int right = 0 + knapsack(index-1,wt,val,W,dp);
        int left=INT_MIN;
        if(wt[index]<=W){
            left=val[index]+knapsack(index-1,wt,val,W-wt[index],dp);
        }
    
        return dp[index][W]=max(left,right);
}
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp(n,vector<int>(W+1,0));
        //base case 
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<W+1;j++){
            if(wt[0]<=j){
                dp[0][j]=val[0];
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<W+1;j++){
                int right = 0 + dp[i-1][j];
                int left=INT_MIN;
                if(wt[i]<=j){
                    left=val[i]+dp[i-1][j-wt[i]];
                }
                
                dp[i][j]=max(left,right);
            }
        }
        
        return dp[n-1][W];
        
        
        // memoization and recurance 
        
        vector<vector<int>> dp1(n,vector<int>(W+1,-1));
       return knapsack(n-1,wt,val,W,dp1);
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends