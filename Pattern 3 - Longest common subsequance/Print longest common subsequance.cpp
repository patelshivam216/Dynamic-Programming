#include<bits/stdc++.h>

int helper(int i,int j , string &s1 , string &s2 , vector<vector<int>> &dp){
    //base condition 
    if(i<0 or j<0)
        return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]= 1+helper(i-1,j-1,s1,s2,dp);
    }
        return dp[i][j]= 0 + max(helper(i-1,j,s1,s2,dp),helper(i,j-1,s1,s2,dp));
}

int getLengthOfLCS(string & str1, string & str2) {
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
    
    int k=dp[n][m];
    string res(k,'.');
    int i=n,j=m;
    while(i>0 and j>0){
        if(str1[i-1]==str2[j-1]){
            res[--k]=str1[i-1];
            i=i-1;
            j=j-1;
        }else if(dp[i-1][j]>dp[i][j]){
            i=i-1;
        }else{
            j=j-1;
        }
    }
    
    cout<<res<<endl;
    
    return res;
    
    // memoization
//     vector<vector<int>> dp(n,vector<int>(m,-1));
//     return helper(n-1,m-1,str1,str2,dp);
}