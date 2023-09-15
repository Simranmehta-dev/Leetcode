class Solution {
public:
    void rotate(vector<int>& nums, int k) {
         int n=nums.size();
         k=k%n;
        // while(k--){
        //   int el=nums[n-1];
        //   for(int i=n-2;i>=0;i--){
        //       nums[i+1]=nums[i];
        //   }
        //   nums[0]=el;
        // }

        vector<int>temp(k);
        int t=k;
        for(int i=n-1;i>=n-k;i--){
            temp[t-1]=nums[i];
            t--;
        }

        for(int i=n-k-1;i>=0;i--){
            nums[i+k]=nums[i];
           
        }

        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};