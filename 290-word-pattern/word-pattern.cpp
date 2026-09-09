class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> CtW;
        unordered_map<string, char> WtC;

        vector<string> words;
        string word;

        stringstream ss(s);

        while(ss >> word){
            words.push_back(word);
        }
        if(pattern.size() != words.size()){
            return false;
        }

        for(int i = 0; i<pattern.size(); i++){
            char ch= pattern[i];
            string w = words[i];

            if(CtW.count(ch) && CtW[ch] != w){
                return false;

            }
            if(WtC.count(w) && WtC[w] != ch){
                return false;
            }
            CtW[ch]= w;
            WtC[w] = ch;
        }
        return true;

    }
};