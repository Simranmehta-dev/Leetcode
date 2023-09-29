class Solution {
public:
    int getday(vector<int>& weights, int capacity){
        int d=1,load=0;
        for(int i=0;i<weights.size();i++){
            if(load+weights[i]>capacity){
                d=d+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
       int maxi=INT_MIN;
       int sum=0;
       for(int i=0;i<weights.size();i++){
           maxi=max(maxi,weights[i]);
           sum+=weights[i];
       } 
       int s=maxi;
       int e=sum;
       int ans=INT_MAX;

       while(s<=e){
           int mid=(s+e)/2;
           int x=getday(weights,mid);

           if(x<=days){
               ans=min(ans,mid);
               e=mid-1;
           }
           else{
               s=mid+1;
           }
       }
       return ans;
    }
};