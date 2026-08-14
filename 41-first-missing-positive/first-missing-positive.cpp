class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int>st;
        for(int x : nums){
            st.insert(x);
        }
        for(int x = 1; x<=nums.size()+1; x++){
            if(st.find(x)==st.end())
                return x;
        }
        return -1;
    }
};