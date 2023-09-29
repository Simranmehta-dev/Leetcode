class Solution {
public:
    int func(vector<int>& nums,int m){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil(nums[i]/(float)m);
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int th) {
        int s=1;
        int maxi=INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
        }
        int e=maxi;
        int ans=INT_MAX;
        while(s<=e){
            int mid=(s+e)/2;
            int sum=func(nums,mid);
            
            if(sum>th){
                s=mid+1;
            }
            else{
                ans=min(ans,mid);
                e=mid-1;
            }
        }
        return ans;
    }
};