// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

	public:
	int helper(int index , int target , int coins[],vector<vector<int>> &dp){
	    if(index==0){
	        
	        if(target%coins[0]==0){
	            return target/coins[0];
	        }else 
	            return 1e9;
	        
	    }
	    if(dp[index][target] != -1 ) return dp[index][target];
	    
	    // not take that coin
	    int right = 0 + helper(index-1,target,coins,dp);
	    int left=INT_MAX;// take that coin
	    
	    if(coins[index]<=target){
	        left=1+helper(index,target-coins[index],coins,dp);
	    }
	    
	    return dp[index][target] = min(left,right);
	}
	int minCoins(int coins[], int n, int target) 
	{ 
	    vector<vector<int>> dp(n,vector<int>(target+1,-1));
	    int ans = helper(n-1,target,coins,dp);
	    if(ans >= 1e9){
	        return -1;
	    }else 
	        return ans ;
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