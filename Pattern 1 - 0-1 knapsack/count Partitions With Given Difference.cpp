int mod = (int)(1e9 + 7);

 int helper(int index,int target , vector<int> &arr , vector<vector<int>> &dp){
        if(index==0){
            if(target==0 and arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int right = helper(index-1,target,arr,dp);//nottake case 
        int left=0;
        if(arr[index]<=target){
            left=helper(index-1,target-arr[index],arr,dp);
        }
        
        return dp[index][target] =  (left+right)%mod;
    }

int countPartitions(int n, int d, vector<int> &arr) {
    int sum=0;
    for(auto num : arr){
        sum+=num;
    }
    if(sum-d<0 or (sum-d)%2) return false;
    
    // Now my target is boiled down to..
    int target = (sum-d)/2;
    //dynamic allocation 
    vector<vector<int>> dp(n,vector<int>(target+1,0));
    //base case 
    if(arr[0]==0)
        dp[0][0]=2;
    else 
        dp[0][0]=1;
    if( arr[0]!=0 and arr[0]<=target) dp[0][arr[0]]=1;
    
    
    //statement 
    for(int i=1;i<n;i++){
        for(int j=0;j<target+1;j++){
            int right = dp[i-1][j];
            int left=0;
            if(arr[i]<=j){
                left=dp[i-1][j-arr[i]];
            }
            
            dp[i][j]=(left+right)%mod;
        }
    }
    
    return dp[n-1][target];
    
    
    //recursion and memoization 
    
//     vector<vector<int>> dp(n,vector<int>(target+1,-1));
//     return helper(n-1,target,arr,dp);
}


