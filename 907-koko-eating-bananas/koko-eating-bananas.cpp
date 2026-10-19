class Solution {
private:
        bool canFinish(vector<int>& piles, int h, int k){
            long long hours = 0;

            for(int pile : piles){
                hours += (pile + k - 1LL) / k;
                if(hours > h){
                    return false;
                }
            }
            return true;
        }
public:

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low < high){
            int mid = low + (high-low)/2;

            if(canFinish(piles, h, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
};