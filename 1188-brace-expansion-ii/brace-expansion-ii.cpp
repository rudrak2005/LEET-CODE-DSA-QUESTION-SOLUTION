class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        set<string> res = helper(expression);
        return vector<string>(res.begin(), res.end());
    }

private:
    set<string> helper(string expr) {
        set<string> result;
        int braceDepth = 0;

        for (int i = 0; i < expr.size(); ++i) {
            if (expr[i] == '{')
                braceDepth++;
            else if (expr[i] == '}')
                braceDepth--;
            else if (expr[i] == ',' && braceDepth == 0) {

                set<string> left = helper(expr.substr(0, i));
                set<string> right = helper(expr.substr(i + 1));
                result.insert(left.begin(), left.end());
                result.insert(right.begin(), right.end());
                return result;
            }
        }

        int i = 0;
        while (i < expr.size() && expr[i] != '{') {
            i++;
        }

        if (i == expr.size()) {
            result.insert(expr);
            return result;
        }

        int j = i, depth = 0;
        while (j < expr.size()) {
            if (expr[j] == '{')
                depth++;
            else if (expr[j] == '}')
                depth--;
            if (depth == 0)
                break;
            j++;
        }

        string prefix = expr.substr(0, i);
        string middle = expr.substr(i + 1, j - i - 1);
        string suffix = expr.substr(j + 1);

        set<string> prefixSets =
            prefix.empty() ? set<string>{""} : helper(prefix);
        set<string> middleSets = helper(middle);
        set<string> suffixSets = helper(suffix);

        for (const string& p : prefixSets) {
            for (const string& m : middleSets) {
                for (const string& s : suffixSets) {
                    result.insert(p + m + s);
                }
            }
        }

        return result;
    }
};