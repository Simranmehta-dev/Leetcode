class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int n=arr.size();
        vector<int>hash(n+1,0);
	for(int i=0;i<n;i++){
		hash[arr[i]]++;
	}
	int m=-1,r=-1;
	for(int i=1;i<n+1;i++){
        if(hash[i]==0){
			m=i;
		}
		if(hash[i]==2){
			r=i;
		}
		if(m!=-1 && r!=-1){
			break;
		}
	}
	return {r,m};
    }
};