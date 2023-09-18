class Solution {
public:
    void moveZeroes(vector<int>& nums) {
      int n=nums.size();
      if(n==1){
          return;
      }
      int k=-1;
      for(int i=0;i<n;i++){
          if(nums[i]==0){
              k=i;
              break;
          }
      }

      if(k==-1){
          return ;
      }

      for(int j=k+1;j<n;j++){
          if(nums[j]!=0){
              swap(nums[k],nums[j]);
              k++;
             
          }
         
      }
    }
};