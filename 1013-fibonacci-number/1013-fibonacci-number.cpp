class Solution {
public:
    int Recursion(int n){
        if(n<=1){
            return n;
        }

        return Recursion(n-1)+Recursion(n-2);
    }
    int Tabulation(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=Tabulation(n-1,dp)+Tabulation(n-2,dp);

        return dp[n];
    }
    int fib(int n) {
        //return Recursion(n);

        vector<int>dp(n+1,-1);
        return Tabulation(n,dp);
    }
};