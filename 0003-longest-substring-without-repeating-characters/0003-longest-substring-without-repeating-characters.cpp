class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0;
        int cnt[256]={0};
        int ans=0;

        while(j<s.length()){
            cnt[s[j]]++;

            while(cnt[s[j]]>1){
                cnt[s[i]]--;
                i++;
            }

            ans=max(ans,j-i+1);
            j++;
        }

        return ans;
    }
};