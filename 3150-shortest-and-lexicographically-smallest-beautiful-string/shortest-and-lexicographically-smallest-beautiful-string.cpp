class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        
        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i < s.length(); i++) {
            
            int ones = 0;

            for (int j = i; j < s.length(); j++) {
                
                if (s[j] == '1')
                    ones++;

                // Exactly k ones mil gaye
                if (ones == k) {
                    
                    int len = j - i + 1;
                    string curr = s.substr(i, len);

                    // Shorter substring
                    if (len < minLen) {
                        minLen = len;
                        ans = curr;
                    }
                    
                    // Same length but lexicographically smaller
                    else if (len == minLen && curr < ans) {
                        ans = curr;
                    }

                    // Further j badhane ki zarurat nahi
                    break;
                }
            }
        }

        return ans;
    }
};