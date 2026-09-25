class Solution {
public:

    set<string> concatenate(const set<string>& a,
                            const set<string>& b) {

        set<string> result;

        for (const string& x : a) {
            for (const string& y : b) {
                result.insert(x + y);
            }
        }

        return result;
    }

    set<string> parse(string& s, int& i) {

        set<string> result;
        set<string> current = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == '{') {

                i++; // skip '{'

                set<string> inside = parse(s, i);

                i++; // skip '}'

                current = concatenate(current, inside);
            }

            else if (s[i] == ',') {

                i++; // skip ','

                result.insert(current.begin(), current.end());

                current = {""};
            }

            else {

                // lowercase letter
                string ch(1, s[i]);
                i++;

                current = concatenate(current, {ch});
            }
        }

        result.insert(current.begin(), current.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {

        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};