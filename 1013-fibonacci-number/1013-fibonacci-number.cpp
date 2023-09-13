class Solution {
public:
    int Recursion(int n){
        if(n<=1){
            return n;
        }

        return Recursion(n-1)+Recursion(n-2);
    }
    int Memoization(int n,vector<int> &dp){
        if(n<=1){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }

        dp[n]=Memoization(n-1,dp)+Memoization(n-2,dp);

        return dp[n];
    }
    
    int Tabulation(int n){
        vector<int>dp(n+1,0);
        dp[0]=0;
        dp[1]=1;
        int s=0;
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int SpaceOpt(int n){
        int pre1=0;
        int pre2=1;
        int s=0;
        for(int i=2;i<=n;i++){
            s=pre1+pre2;
            pre1=pre2;
            pre2=s;
        }
        return pre2;
    }
    int fib(int n) {
        //return Recursion(n);

        // vector<int>dp(n+1,-1);
        // return Memoization(n,dp);
        
        // if(n==0||n==1)return n;
        // return Tabulation(n);
        
        if(n==0||n==1)return n;
        return SpaceOpt(n);
    }
};