class Solution {
public:
    void recursion(vector<int>& nums,vector<vector<int>> &ans, vector<int> &temp, vector<int> &f){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!f[i]){
                f[i]=1;
                temp.push_back(nums[i]);
                recursion(nums,ans,temp,f);
                temp.pop_back();
                f[i]=0;
            }

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        vector<int>f(nums.size(),0);
        recursion(nums,ans,temp,f);
        return ans;
    }
};