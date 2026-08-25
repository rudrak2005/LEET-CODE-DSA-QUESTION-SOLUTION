class Solution {
public:
    string countAndSay(int n) {
        string current = "1";
        for(int term = 2; term <= n; term++){
            string next = "";
            for(int i =0; i< current.size();){
                int count =1;
                while(i+count<current.size() && current[i+count]==current[i]){
                    count++;
                }
                next += to_string(count);
                next += current[i];

                i += count;
            }
            current = next;
        }
        return current;
    }
};