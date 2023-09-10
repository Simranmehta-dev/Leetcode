class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt=0;
        sort(nums.begin(),nums.end());
       int n=nums.size();
       for(int i=n-1;i>=2;i--){
           int l=0,h=i-1;
           while(l<h){
               if(nums[l]+nums[h]>nums[i]){
                   cnt+=h-l;
                   h--;
               }
               else{
                   l++;
               }
           }
       }
       return cnt;
    }
};