class Solution {
public:
    string largestOddNumber(string s) {
        int i = s.size() - 1;

        while(i >= 0) {
            if((s[i] - '0') % 2 == 1) {
                int start = s.find_first_not_of('0');

                if(start == string::npos)
                    return "";

                return s.substr(start, i - start + 1);
            }

            i--;
        }

        return "";
    }
};