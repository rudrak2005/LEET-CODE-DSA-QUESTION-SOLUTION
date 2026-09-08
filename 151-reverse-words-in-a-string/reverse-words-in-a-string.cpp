class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        string t;
        for(int i =0; i<n; i++){
            if(s[i] != ' '){
                t += s[i];
            }
            else if ( !t.empty() && t.back() != ' '){
                t +=' ';
            }
        }
        if(!t.empty() && t.back() == ' ')
            t.pop_back();

        reverse(t.begin(), t.end());
        int start = 0;

        for(int i =0; i<=t.size(); i++){
            if(i==t.size() || t[i] == ' '){
                reverse(t.begin() + start, t.begin() + i);
                start = i +1;
            }
        }
        return t;
    }
};