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
        
        return dp[index][target] =  (left+right);
    }

int targetSum(int n, int target, vector<int>& arr) {
    int sum=0;
    for(auto value : arr){
        sum+=value;
    }
    if(sum-target<0 || (sum-target)%2) return false;
    target=(sum-target)/2;
    vector<vector<int>> dp(arr.size() ,vector<int>(target+1,-1));
    return helper(n-1,target,arr,dp);
}
