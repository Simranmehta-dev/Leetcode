class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int s=0;
        int e=nums.size()-1;
        int f=-1;
        int l=-1;
        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target){
                f=m;
                e=m-1;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }

        s=0;
        e=nums.size()-1;

        while(s<=e){
            int m=(s+e)/2;
            if(nums[m]==target){
                l=m;
                s=m+1;
            }
            else if(nums[m]<target){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }

        return {f,l};
    }
};