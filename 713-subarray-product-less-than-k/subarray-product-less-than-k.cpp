class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int l = 0;
        long long p = 1; 
        int c = 0;

        for(int right = 0; right < nums.size(); right++){
            p *= nums[right];

            while(p >= k){
                p /= nums[l]; 
                l++;
            }
            c += right - l + 1;
        }
        return c;
    }
};