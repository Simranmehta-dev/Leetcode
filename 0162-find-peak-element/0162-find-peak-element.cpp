class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int n=nums.size();
        if(nums.size()==1){
            return 0;
        }
         
         if (nums[0] > nums[1]) return 0;
    if (nums[n - 1] > nums[n - 2]) return n - 1;


        while(s<e){
            int m=(s+e)/2;

            if(nums[m]>nums[m-1] && nums[m]>nums[m+1]){
                return m;
            }
            else if( nums[m]<nums[m-1]){
               e=m;
            }
            else{
                s=m+1;
            }
        }
        return -1;
    }
};