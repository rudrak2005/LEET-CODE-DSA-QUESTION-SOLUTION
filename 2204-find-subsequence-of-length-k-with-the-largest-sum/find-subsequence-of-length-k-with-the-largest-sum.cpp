class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> arr;

        for (int i = 0; i < nums.size(); i++) {
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.first > b.first;
             });

        vector<pair<int, int>> selected;
        for (int i = 0; i < k; i++) {
            selected.push_back(arr[i]);
        }

        sort(selected.begin(), selected.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });

        vector<int> ans;
        for (auto& p : selected) {
            ans.push_back(p.first);
        }

        return ans;
    }
};