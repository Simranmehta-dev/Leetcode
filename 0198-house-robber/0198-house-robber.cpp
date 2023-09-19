class Solution {
public:
    // int solveUsingRec(vector<int>& nums,int i){
    //     if(i>=nums.size())return 0;

    //     int Rob1=nums[i]+solveUsingRec(nums,i+2);
    //     int Rob2=0+solveUsingRec(nums,i+1);

    //     return max(Rob1,Rob2);
    // }
    // int SolveMem(vector<int>& nums,int i,vector<int>&dp){
    //       if(i>=nums.size())return 0;
    //       if(dp[i]!=-1){
    //           return dp[i];
    //       }
    //        int Rob1=nums[i]+SolveMem(nums,i+2,dp);
    //        int Rob2=0+SolveMem(nums,i+1,dp);
    //        dp[i]=max(Rob1,Rob2);
    //        return dp[i];
    // }
    int solveTab(vector<int>& nums,int i){
        int n=nums.size();
        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1] = max(0, nums[0]);
        for(int ind=2;ind<=n;ind++){
            int Rob1=nums[ind-1]+dp[ind-2];
            int Rob2=0+dp[ind-1];

            dp[ind]=max(Rob1,Rob2);
        }
        return dp[n];
    }

    int spaceopti(vector<int>& nums){
        int curr=nums[0];
        int prev=0;

        for(int i=1;i<nums.size();i++){
            int take=nums[i];
            if (i > 1)
            take += prev;
            int not1=curr;

            int next=max(take,not1);
          
            prev=curr;
              curr=next;
        }
        return curr;
    }
    int rob(vector<int>& nums) {
      //  return solveUsingRec(nums,0);
      int n=nums.size();
    //   vector<int>dp(n+1,-1);
    //   return SolveMem(nums,0,dp);
       // return solveTab(nums,0);

       return spaceopti(nums);
    }
};