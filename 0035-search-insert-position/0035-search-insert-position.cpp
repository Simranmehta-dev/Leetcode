class Solution {
public:
    int searchInsert(vector<int>& arr, int x) {
        int s=0;
	int e=arr.size()-1;
	int ans=arr.size();
	while(s<=e){
		int m=(s+e)/2;
		if(arr[m]>=x){
           ans=m;
		   e=m-1;
		}
		else{
			s=m+1;
		}
	}
	return ans;
    }
};