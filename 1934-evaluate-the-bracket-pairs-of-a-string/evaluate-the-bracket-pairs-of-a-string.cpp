class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;

        // Store knowledge in HashMap
        for (auto &pair : knowledge) {
            mp[pair[0]] = pair[1];
        }

        string ans = "";

        int i = 0;

        while (i < s.size()) {

            // Normal character
            if (s[i] != '(') {
                ans += s[i];
                i++;
            }

            // Bracket pair
            else {
                i++; // skip '('

                string key = "";

                while (s[i] != ')') {
                    key += s[i];
                    i++;
                }

                // Skip ')'
                i++;

                // Lookup key
                if (mp.count(key)) {
                    ans += mp[key];
                } else {
                    ans += '?';
                }
            }
        }

        return ans;
    }
};