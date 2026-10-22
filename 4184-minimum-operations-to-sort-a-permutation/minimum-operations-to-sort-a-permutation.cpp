class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        auto get_rotation_shift = [&](const std::vector<int>& target) {
            std::vector<int> doubled = target;
            doubled.insert(doubled.end(), target.begin(), target.end());
            for (int i = 0; i < n; ++i) {
                bool match = true;
                for (int j = 0; j < n; ++j) {
                    if (doubled[i + j] != nums[j]) {
                        match = false;
                        break;
                    }
                }
                if (match) return i; 
            }
            return -1;
        };
        
        std::vector<int> inc(n);
        std::iota(inc.begin(), inc.end(), 0);
        std::vector<int> dec = inc;
        std::reverse(dec.begin(), dec.end());

        int shift_inc = get_rotation_shift(inc);
        int shift_dec = get_rotation_shift(dec);

        if (shift_inc == -1 && shift_dec == -1) {
            return -1;
        }

        int ans = 1e9;

        if (shift_inc != -1) {
            ans = std::min(ans, (n - shift_inc) % n);               
            ans = std::min(ans, 1 + shift_inc + 1);                 
        }

        
        if (shift_dec != -1) {
            ans = std::min(ans, 1 + (n - shift_dec) % n);           
            ans = std::min(ans, shift_dec + 1);                   
        }

        return ans;
    }
};