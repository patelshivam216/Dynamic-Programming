#include<bits/stdc++.h>
long f(int index , int target , int *arr , vector<vector<int>> &dp){
    if(target==0) return 1;
    if(index==0){
        return (target%arr[0]==0);
    }
    if(dp[index][target] != -1) return dp[index][target];
    long right = f(index-1,target,arr,dp);
    long left=0;
    if(arr[index]<=target){
        left=f(index,target-arr[index],arr,dp);
    }
    
    return dp[index][target] = right + left;
}
long countWaysToMakeChange(int *arr, int n, int value)
{
     vector<vector<int>> dp(n,vector<int>(value+1,-1));   
    return f(n-1,value,arr,dp);
}