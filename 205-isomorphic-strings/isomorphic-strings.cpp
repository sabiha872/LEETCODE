class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int hash1[256] = {0};
        int hash2[256] = {0};

        for(int i = 0; i < s.length(); i++) {
            if (hash1[s[i]] != hash2[t[i]]) {
                return false;
            }
            hash1[s[i]] = i + 1;
            hash2[t[i]] = i + 1;
        }
        return true;
    }
};