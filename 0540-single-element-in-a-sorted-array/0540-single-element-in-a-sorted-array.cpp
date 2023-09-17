class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1){
            return arr[0];
        }
        int l=1;
        int h=n-2;
        if(arr[0]!=arr[1]){
            return arr[0];
        }
        if(arr[n-1]!=arr[n-2]){
            return arr[n-1];
        }

        while(l<=h){
            int m=(l+h)/2;

            if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]){
                return arr[m];
            }
            else if(m%2==0) {
                if(arr[m]==arr[m+1]){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
                
            }
            else{
              if(arr[m]==arr[m+1]){
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
        }
        return -1;
    }
};