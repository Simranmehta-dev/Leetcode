class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0,j=0;
        vector<int>ans(m+n,-1);
          int ind=0;
        while(i<m && j<n){
            if(nums1[i]<nums2[j]){
                ans[ind]=nums1[i];
                i++;
                ind++;
            }
            else{
                 ans[ind]=nums2[j];
                 j++;
                 ind++;
            }
        }
        while(i<m){
              ans[ind]=nums1[i];
                i++;
                ind++;
        }
        while(j<n){
               ans[ind]=nums2[j];
                 j++;
                 ind++;
        }
        int n1=m+n;
        for(int k=0;k<n1;k++ ){
            nums1[k]=ans[k];
        }
    }
};