class Solution {
vector<int> getRow(int n){
   vector<int>temp;
   int ans=1;
   temp.push_back(ans);
   for(int i=1;i<n;i++){
       ans=ans*(n-i);
       ans=ans/i;
       temp.push_back(ans);
   }
   return temp;
}
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        for(int r=1;r<=numRows;r++){
           ans.push_back(getRow(r));
        }
        return ans;
    }
};