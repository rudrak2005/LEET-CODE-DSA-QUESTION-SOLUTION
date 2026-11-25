
class Solution {
    static constexpr uint64_t BASE1 = 100003ULL;
    static constexpr uint64_t MOD1  = 1000000007ULL;
    static constexpr uint64_t BASE2 = 100019ULL;
    static constexpr uint64_t MOD2  = 1000000009ULL;

    vector<uint64_t> p1, p2;

    static uint64_t pack(uint64_t h1, uint64_t h2) {
        return (h1 << 32) | h2;
    }

    bool hasUniqueOfLen(const vector<int>& nums, int len) {
        int n = static_cast<int>(nums.size());
        if (len > n) return false;

        uint64_t h1 = 0, h2 = 0;
        for (int i = 0; i < len; ++i) {
            uint64_t val = static_cast<uint64_t>(nums[i]) + 1ULL;
            h1 = (h1 * BASE1 + val) % MOD1;
            h2 = (h2 * BASE2 + val) % MOD2;
        }

        unordered_map<uint64_t, int> freq;
        freq.reserve(n - len + 1);
        freq[pack(h1, h2)] = 1;

        uint64_t pow1 = p1[len - 1];
        uint64_t pow2 = p2[len - 1];

        for (int i = len; i < n; ++i) {
            uint64_t outVal = static_cast<uint64_t>(nums[i - len]) + 1ULL;
            uint64_t inVal  = static_cast<uint64_t>(nums[i]) + 1ULL;

            uint64_t rem1 = (outVal * pow1) % MOD1;
            h1 = (h1 + MOD1 - rem1) % MOD1;
            h1 = (h1 * BASE1 + inVal) % MOD1;

            uint64_t rem2 = (outVal * pow2) % MOD2;
            h2 = (h2 + MOD2 - rem2) % MOD2;
            h2 = (h2 * BASE2 + inVal) % MOD2;

            ++freq[pack(h1, h2)];
        }

        for (const auto& [_, cnt] : freq) {
            if (cnt == 1) return true;
        }
        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = static_cast<int>(nums.size());
        p1.assign(n + 1, 1);
        p2.assign(n + 1, 1);
        for (int i = 1; i <= n; ++i) {
            p1[i] = (p1[i - 1] * BASE1) % MOD1;
            p2[i] = (p2[i - 1] * BASE2) % MOD2;
        }

        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueOfLen(nums, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};