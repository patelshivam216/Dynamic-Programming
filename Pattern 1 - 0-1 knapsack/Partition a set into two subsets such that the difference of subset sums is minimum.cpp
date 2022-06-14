bool helper(int index, int target , vector<int> &arr){
    if(target==0)
        return 1;
    if(index==0){
        return (arr[0]==target);
    }
    
    int right = helper(index-1,target,arr);
    int left=false;
    if(arr[index]<=target){
        left=helper(index-1,target-arr[index],arr);
    }
    
    return right || left;
}


int minSubsetSumDifference(vector<int>& arr, int n)
{   
    int sum=0;
    for(auto value: arr){
        sum+=value;
    }
    vector<vector<bool>> dp(n,vector<bool>(sum+1));
    for(int i=0;i<n;i++){
        dp[i][0]=true;
    }
    if(arr[0]<=sum) dp[0][arr[0]]=true;
    for(int index=1;index<n;index++){
        for(int target=1;target<sum+1;target++){
            bool right = dp[index-1][target];
            bool left=false;
            if(arr[index]<=target){
                left=dp[index-1][target-arr[index]];
            }
            dp[index][target]= left || right;
        }
    }
    
    int min_diff = 1e3;
    for(int target=0;target<sum+1;target++){
        if(dp[n-1][target]){
            int s1=target;
            int s2=sum-s1;
            min_diff=min(min_diff,abs(s1-s2));
        }
    }
    
    return min_diff;
    
    // recursion of subset sum of k 
//     return helper(arr.size()-1,sum,arr);
    
}
