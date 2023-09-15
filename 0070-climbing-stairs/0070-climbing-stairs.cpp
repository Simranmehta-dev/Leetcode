class Solution {
public:
    int solve(int n){
        if(n==0 || n==1)return 1;
        int ans=solve(n-1)+solve(n-2);
        return ans;
    }
    int mem(int n, vector<int> &dp){
          if(n==0 || n==1)return 1;
          if(dp[n]!=-1)return dp[n];
        int ans=mem(n-1,dp)+mem(n-2,dp);
        dp[n]=ans;
        return dp[n];
    }
    int climbStairs(int n) {
       // return solve(n);
       vector<int>dp(n+1,-1);
       return mem(n,dp);
    }
};