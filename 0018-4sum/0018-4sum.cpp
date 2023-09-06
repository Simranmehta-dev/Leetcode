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
        // set<vector<int>>st;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         set<long long>hash;
        //         for(int k=j+1;k<n;k++){
        //             long long sum=nums[i]+nums[j];
        //              sum+=nums[k];
        //              long long f=target-sum;
        //              if(hash.find(f)!=hash.end()){
        //                  vector<int>temp={nums[i],nums[j],nums[k],int (f)};
        //                  sort(temp.begin(),temp.end());
        //                  st.insert(temp);
        //              }
        //              hash.insert(nums[k]);
        //         }
        //     }
        // }
        //  vector<vector<int>>ans(st.begin(),st.end());
        //  return ans;

        //OPTIMAL TWO POINTER APPROACH
          sort(nums.begin(),nums.end());
          int n=nums.size();
          vector<vector<int>>ans;

          for(int i=0;i<n;i++){
              if(i>0 && nums[i]==nums[i-1])continue;
              for(int j=i+1;j<n;j++){
                  if(j>i+1 && nums[j]==nums[j-1])continue;
                  int k=j+1,l=n-1;

                  while(k<l){
                      long long sum=nums[i]+nums[j];
                      sum+=nums[k];
                      sum+=nums[l];

                      if(sum==target){
                          vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                          ans.push_back(temp);
                          k++;
                          l--;
                          while(k<l && nums[k]==nums[k-1])k++;
                          while(k<l && nums[l]==nums[l+1])l--;
                      }
                      else if(sum<target){
                          k++;
                      }
                      else{
                          l--;
                      }
                  }
              }
          }
          return ans;
          

    }
};