class Solution {
  int maxi(vector<int> v,int n){
    int m=INT_MIN;
    for(int i=0;i<n;i++){
        m=max(m,v[i]);
    }
    return m;
}

public:
    int minEatingSpeed(vector<int>& v, int h) {
         int n=v.size();
    int s=1;
    int e=maxi(v,n);

    while(s<=e){
        int mid=(s+e)/2;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=ceil((double)(v[i])/(double)(mid));
        }
        
        if(sum<=h){
           e=mid-1;
        }

        else{
            s=mid+1;
        }
    }
    return s;
    }
};