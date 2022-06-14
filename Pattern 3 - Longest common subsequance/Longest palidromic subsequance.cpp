// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
  public:
    int helper(int i,int j , string &s1 , string &s2 , vector<vector<int>> &dp){
        if(i==0 or j==0) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s1[i-1]==s2[j-1]){
            return dp[i][j]= 1+helper(i-1,j-1,s1,s2,dp);
        }else
            return dp[i][j] = max( helper(i-1,j,s1,s2,dp) , helper(i,j-1,s1,s2,dp));
    }
    int longestPalinSubseq(string A) {
        
        string str1=A;
        reverse(A.begin(),A.end());
        string str2=A;
        // dynamic programing 
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        //base case 
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<m+1;j++){
            dp[0][j]=0;
        }
        
        //statement 
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }else 
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        
        return dp[n][m];
        
        //recursion and memoization
        // string s = A;
        // reverse(A.begin(),A.end());
        // vector<vector<int>> dp(s.size()+1,vector<int>(s.size()+1,-1));
        // return helper(A.size(),s.size(),A,s,dp);
    }
};

// { Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends