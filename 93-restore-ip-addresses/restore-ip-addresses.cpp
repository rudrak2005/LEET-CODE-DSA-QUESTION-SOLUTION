class Solution {
public:
        vector<string> ans; vector<string> path;
        void backtrack(string& s, int index){
            if(path.size() ==4){
                if(index ==s.size()){
                    string ip = path[0] + "." + path[1] + "." + path[2] + "." + path[3];
                    ans.push_back(ip);
                }
                return ;
            }
            for(int len = 1; len <= 3; len++){
                if(index + len > s.size())
                    break;
                    string part = s.substr(index, len);
                if(part.size()> 1 && part[0] == '0')
                    continue;

                int num = stoi(part);
                if(num > 255)
                    continue;
                path.push_back(part);

                backtrack(s, index + len);
                path.pop_back();
            }
        }
    vector<string> restoreIpAddresses(string s) {
        backtrack(s, 0);
        return ans;
    }
};