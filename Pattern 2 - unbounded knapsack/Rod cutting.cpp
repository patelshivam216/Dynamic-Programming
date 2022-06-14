// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int val[], int n) {
        int wt[n];
        for(int i=0;i<n;i++){
            wt[i]=i+1;
        }
        
        int W=n;
        
         vector<vector<int>> dp(n,vector<int>(W+1));
        //base case 
        for(int i=0;i<n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<W+1;j++){
            dp[0][j]=(j/wt[0])*val[0];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<W+1;j++){
                int right = dp[i-1][j];
                int left=0;
                if(wt[i]<=j){
                    left+=val[i]+dp[i][j-wt[i]];
                }

                dp[i][j]=max(left,right);
            }
        }

        return dp[n-1][W];
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}  // } Driver Code Ends