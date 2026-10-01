class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) {
            return "";
        }
        vector<int> need(128, 0);
        vector<int> window(128, 0);
        for (char c : t) {
            need[c]++;
        }
        int left = 0;
        int have = 0;
        int required = t.size();

        int bestLen = INT_MAX;
        int bestStart = 0;

        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;

            if (need[c] > 0 && window[c] <= need[c]) {
                have++;
            }
            while (have == required) {
                int len = right - left + 1;

                if (len < bestLen) {
                    bestLen = len;
                    bestStart = left;
                }
                char leftChar =s[left];
                window[leftChar]--;

                if(need[leftChar]>0 && window[leftChar]<need[leftChar]){
                    have--;
                }
                left++;
            }
        }
        if(bestLen==INT_MAX){
            return "";
        }
        return s.substr(bestStart, bestLen);
    }
};