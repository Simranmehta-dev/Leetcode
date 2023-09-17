class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>temp(k);
        k=k%n;
        int j=0;
        for(int i=n-k;i<n;i++){
            temp[j]=nums[i];
            j++;
        }

        int m=n;
        for(int i=n-k-1;i>=0;i--){
            nums[m-1]=nums[i];
            m--;
        }

        for(int i=0;i<k;i++){
            nums[i]=temp[i];
        }
    }
};