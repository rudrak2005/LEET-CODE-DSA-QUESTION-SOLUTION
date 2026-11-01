class Solution {
public:
    int minMoves(vector<int>& nums) {
        int min_val = nums[0];
        int sum = 0;
        for (int num : nums) {
            min_val = min(min_val, num);
            sum += num;
        }
        return sum - min_val * nums.size();
    }
};