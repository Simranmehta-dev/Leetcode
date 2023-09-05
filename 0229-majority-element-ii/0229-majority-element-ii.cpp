class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int e1=INT_MAX, e2=INT_MAX;

        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(cnt1==0 && nums[i]!=e2){
                e1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0 && nums[i]!=e1){
                e2=nums[i];
                cnt2=1;
            }
            else if(e1==nums[i]){
                cnt1++;
            }
            else if(e2==nums[i]){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        int c1=0,c2=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==e1)c1++;
            if(nums[i]==e2)c2++;
        }
        int mm=(int)(nums.size()/3)+1;
        if(c1>=mm){
            ans.push_back(e1);
        }
        if(c2>=mm){
            ans.push_back(e2);
        }
        return ans;
    }
};