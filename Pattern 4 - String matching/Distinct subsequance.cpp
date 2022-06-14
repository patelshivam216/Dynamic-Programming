class Solution {
public:
    
    int helper(int i,int j , string s, string t, vector<vector<int>> &dp){
        
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        
        if(s[i]==t[j])
            return dp[i][j] = helper(i-1,j-1,s,t,dp) + helper(i-1,j,s,t,dp);
        
        
        return dp[i][j]=helper(i-1,j,s,t,dp);
    }
    
    int numDistinct(string s, string t) {
        
        int n = s.size();
        int m = t.size();
        vector<vector<double>> dp(n+1,vector<double>(m+1,0));
        //base case 
        for(int i=0;i<n+1;i++){
            dp[i][0]=1;
        }
        // Here dp[0][0] is already filled with 1 so make sure this j's loop starting from 1
        for(int j=1;j<m+1;j++){
            dp[0][j]=0;
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }else
                    dp[i][j]=dp[i-1][j];
            }
        }
        
        return (int)dp[n][m];
        
        // recursion and memoization
    
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return helper(n-1,m-1,s,t,dp);
        
    }
};