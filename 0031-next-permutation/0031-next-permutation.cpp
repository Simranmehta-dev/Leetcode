class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        //Step1: Find Dip
        int n=nums.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                ind=i;
                break;
            }
        }
        //Edge Case
        if(ind==-1){
            reverse(nums.begin(),nums.end());
        }
       

        else{
             //Step2: swap the largest smallest element
            for(int i=n-1;i>=ind;i--){
              if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
              }
            }

            //step3:reverse remain ele
            reverse(nums.begin()+ind+1,nums.end());
        }

    }
};