class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector <int > positive;
        vector<int> negative;
        for(int x : nums){
            if(x>0)
             positive.push_back(x);
            else
            negative.push_back(x);
        }
        for(int  i = 0; i<positive.size(); i++){
            nums[2 * i]= positive[i];
                nums[2*i+1]= negative[i];
        }
        return nums;
    }
};