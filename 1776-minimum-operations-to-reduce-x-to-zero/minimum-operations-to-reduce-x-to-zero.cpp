class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // Need to remove all elements
        if (target == 0) {
            return n;
        }

        // Even the whole array is smaller than x
        if (target < 0) {
            return -1;
        }

        int left = 0;
        int sum = 0;
        int longest = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Shrink while sum is too large
            while (left <= right && sum > target) {
                sum -= nums[left];
                left++;
            }

            // Found a valid subarray
            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        if (longest == -1) {
            return -1;
        }

        return n - longest;
    }
};