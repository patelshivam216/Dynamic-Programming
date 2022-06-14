//link of code - https://www.codingninjas.com/codestudio/problems/number-of-subsets_3952532?leftPanelTab=0


 int helper(int index,int target , vector<int> &arr , vector<vector<int>> &dp){
        if(index==0){
	        if(arr[0]==0 and target==0) return 2;
	        if(target==0 || arr[0]==target) return 1;
	        return 0;
	    }
        
        if(dp[index][target] != -1) return dp[index][target];
        
        int right = helper(index-1,target,arr,dp);//nottake case 
        int left=0;
        if(arr[index]<=target){
            left=helper(index-1,target-arr[index],arr,dp);
        }
        
        return dp[index][target] =  left+right;
    }

int findWays(vector<int> &arr, int target)
{
    
        vector<vector<int>> dp(arr.size() ,vector<int>(target+1,-1));
        return helper(arr.size()-1,target,arr,dp);
}