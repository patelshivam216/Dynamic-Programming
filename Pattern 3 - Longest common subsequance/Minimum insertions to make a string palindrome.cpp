#include<bits/stdc++.h>
int minInsertion(string &s)
{
    string t=s;
    reverse(s.begin(),s.end());
    int n = s.size();
    //dynamic allocation 
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    //base condition for palidromic (slightly diff from LCS)
    for(int i=0;i<n+1;i++){
        dp[i][0]=0;
        dp[0][i]=0;
    }
    
    //statement which is slightly diff
    int ans = 0;// ans to find max value
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(s[i-1]==t[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
            ans = max(ans,dp[i][j]);
        }
    }
    
    return n-ans;
}