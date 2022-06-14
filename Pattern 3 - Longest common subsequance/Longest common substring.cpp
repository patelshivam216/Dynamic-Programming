//write it from dp code(tablulation code) of longest common subsequance

int lcs(string &str1, string &str2){
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
    int ans =0;
    for(int i=1;i<n+1;i++){
        for(int j=1;j<m+1;j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }else 
                dp[i][j]=0;// change at this statement 
            
            ans = max(ans , dp[i][j]);
        }
    }
    
    return ans;
    
}