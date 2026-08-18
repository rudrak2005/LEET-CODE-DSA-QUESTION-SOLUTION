class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size() != t.size())
         return false;

        vector<int> mapST(256, -1);
        vector<int> mapTS(256, -1);

        for(int i =0; i<s.size(); i++){
            char a= s[i];
            char b = t[i];

            if(mapST[a] != -1 && mapST[a] != b)
                return false;

            if(mapTS[b] != -1 && mapTS[b] != a)
                return false;

            mapST[a]=b;
            mapTS[b]=a;
        }
        return true;
    }
};