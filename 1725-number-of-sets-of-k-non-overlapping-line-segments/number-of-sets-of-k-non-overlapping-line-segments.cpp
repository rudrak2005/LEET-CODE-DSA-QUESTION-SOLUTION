class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        vector<long long> prev(n + 1, 1);
        vector<long long> cur(n+1, 0);

        for(int seg =1; seg <= k; seg++){
            fill (cur.begin(), cur.end(), 0);

            long long prefix = 0;

            for(int i = 1; i<= n; i++){
                if(i >= 2){
                    prefix = (prefix + prev[i-1]) % MOD;
                }
                cur[i] = (cur[i-1] + prefix) % MOD;
            }
            swap(prev, cur);
        }
        return prev[n];
    }
};