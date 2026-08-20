class Solution {
public:
    string longestPalindrome(string s) {
        int start =0;
        int end = 0;

        for(int i=0; i<s.size(); i++){
            auto p1 = expand(s,i, i);
            auto p2 = expand (s, i, i+1);

            if(p1.second-p1.first > end - start){
                start = p1.first;
                end= p1.second;
            }
            if(p2.second - p2.first > end - start ){
                start = p2.first;
                end = p2.second;
            }
        }
        return s.substr(start, end -start +1);
    }

    pair<int , int > expand(string& s, int left, int right){
        while(left >= 0 && right < s.size() && s[left]== s[right]){
            left--; 
            right++;
        }
        return {left +1, right-1};
    }
};