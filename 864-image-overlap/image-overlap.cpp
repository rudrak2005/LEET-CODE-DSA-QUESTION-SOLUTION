class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> A,B;
        for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(img1[i][j]== 1){
                    A.push_back({i,j});
                }
            }
        }
         for(int i =0; i<n; i++){
            for(int j =0; j<n; j++){
                if(img2[i][j]== 1){
                    B.push_back({i,j});
                }
            }
        }
        map<pair<int,int> , int> freq;

        int ans= 0;

        for(auto &a : A){
            for(auto &b : B){
                int dr = b.first - a.first;
                int dc = b.second - a.second;

                freq[{dr, dc}]++;
                ans = max(ans, freq[{dr, dc}]);
            }
        }
        return ans;
    }
};