class Solution {
public:
    void merge(vector<int> &arr, int low, int mid, int high) {
    vector<int> temp; // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1;   // starting index of right half of arr

    //storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp.push_back(arr[left]);
            left++;
        }
        else {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid) {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high) {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
}
void count(vector<int> &arr, int low, int mid, int high, long long &c){
    int r=mid+1;
    for(int i=low;i<=mid;i++){
       while(r<=high && static_cast<long long>(arr[i]) > 2LL * arr[r]){
          r++;
       }
       c+=r-(mid+1);
    }
}
void mergeSort(vector<int> &arr, int low, int high, long long &c) {
    if (low >= high) return;
    int mid = (low + high) / 2 ;
    mergeSort(arr, low, mid,c);  // left half
    mergeSort(arr, mid + 1, high,c); // right half
    count(arr, low, mid, high,c);
    merge(arr, low, mid, high);  // merging sorted halves
}

    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        long long c=0;
        mergeSort(nums,0,n-1,c);
        return (int)c;
    }
};