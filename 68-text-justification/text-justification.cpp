class Solution {
public:

    string buildLine(vector<string>& words,
                     int start,
                     int end,
                     int maxWidth,
                     bool lastLine) {

        int wordLength = 0;

        for(int i = start; i <= end; i++) {
            wordLength += words[i].size();
        }

        int gaps = end - start;

        // Last line or single-word line
        if(lastLine || gaps == 0) {

            string line = "";

            for(int i = start; i <= end; i++) {

                if(i > start)
                    line += ' ';

                line += words[i];
            }

            line += string(maxWidth - line.size(), ' ');

            return line;
        }

        // Fully justified line
        int totalSpaces = maxWidth - wordLength;

        int spaceEach = totalSpaces / gaps;
        int extra = totalSpaces % gaps;

        string line = "";

        for(int i = start; i <= end; i++) {

            line += words[i];

            if(i < end) {

                int spaces = spaceEach;

                if(i - start < extra)
                    spaces++;

                line += string(spaces, ' ');
            }
        }

        return line;
    }


    vector<string> fullJustify(vector<string>& words,
                               int maxWidth) {

        vector<string> ans;

        int n = words.size();

        int start = 0;

        while(start < n) {

            int end = start;

            int currentLength = words[start].size();

            while(end + 1 < n &&
                  currentLength + 1 + words[end + 1].size()
                  <= maxWidth) {

                end++;

                currentLength += 1 + words[end].size();
            }

            bool lastLine = (end == n - 1);

            ans.push_back(
                buildLine(words, start, end, maxWidth, lastLine)
            );

            start = end + 1;
        }

        return ans;
    }
};