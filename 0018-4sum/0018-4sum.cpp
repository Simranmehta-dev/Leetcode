class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
    //    BRUTE
    //     set<vector<int>>st;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++){
    //         for(int j=i+1;j<n;j++){
    //             for(int k=j+1;k<n;k++){
    //                 for(int l=k+1;l<n;l++){
    //                     long long int sum=nums[i]+nums[j];
    //                     sum+=nums[k]; 
    //                     sum+=nums[l];
    //                     if(sum==target){
    //                         vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
    //                         sort(temp.begin(),temp.end());
    //                         st.insert(temp);
    //                     }
    //                 }
    //             }
    //         }
    //     }
    //      vector<vector<int>>ans(st.begin(),st.end());
    //      return ans;

        //BETTER
        set<vector<int>>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                set<long long>hash;
                for(int k=j+1;k<n;k++){
                    long long sum=nums[i]+nums[j];
                     sum+=nums[k];
                     long long f=target-sum;
                     if(hash.find(f)!=hash.end()){
                         vector<int>temp={nums[i],nums[j],nums[k],int (f)};
                         sort(temp.begin(),temp.end());
                         st.insert(temp);
                     }
                     hash.insert(nums[k]);
                }
            }
        }
         vector<vector<int>>ans(st.begin(),st.end());
         return ans;

    }
};