class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int n = nums.size();
        int ans = 1;
        long long sum = 0;

        for(int right =0; right<n;
        right++){
            sum+= nums[right];

            while(1LL * nums[right] * (right-left+1)-sum>k){
                sum -= nums[left];
                left++;

            }
            ans= max(ans, right-left+1);
        }
        return ans;
    }
};