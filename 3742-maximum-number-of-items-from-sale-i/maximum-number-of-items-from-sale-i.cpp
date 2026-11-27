class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        const int MAX_F = 1500;
        
        vector<int> freq(MAX_F + 1, 0);
        int min_price = INT_MAX;
        for (const auto& item : items) {
            freq[item[0]]++;
            min_price = min(min_price, item[1]);
        }
        
        vector<int> div_count(MAX_F + 1, 0);
        for (int f = 1; f <= MAX_F; ++f) {
            if (freq[f] == 0) continue;
            div_count[f] += freq[f] - 1;
            for (int mult = 2 * f; mult <= MAX_F; mult += f) {
                div_count[f] += freq[mult];
            }
        }
        
        vector<int> dp(budget + 1, 0);
        for (const auto& item : items) {
            int f = item[0];
            int p = item[1];
            int gain = 1 + div_count[f];
            
            for (int b = budget; b >= p; --b) {
                dp[b] = max(dp[b], dp[b - p] + gain);
            }
        }
        
        int max_items = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra = (budget - b) / min_price;
            max_items = max(max_items, dp[b] + extra);
        }
        
        return max_items;
    }
};