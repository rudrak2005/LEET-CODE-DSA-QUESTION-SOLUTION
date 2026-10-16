class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int windowSum = 0;
        int ans=0;
        int target = k * threshold;

        for(int i =0; i<k; i++){
            windowSum += arr[i];
        }
        if(windowSum>= target){
            ans++;
        }
        for(int right = k; right<n; right++){
            windowSum += arr[right];
            windowSum -= arr[right - k];

            if(windowSum >= target){
                ans++;
            }
        }
        return ans;
    }
};