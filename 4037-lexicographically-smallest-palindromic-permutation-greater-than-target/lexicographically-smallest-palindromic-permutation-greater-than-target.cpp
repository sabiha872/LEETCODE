class Solution {
public:

    string buildPalindrome(const string& half, char middle) {

        string ans = half;

        if (middle != '#')
            ans += middle;

        string rev = half;
        reverse(rev.begin(), rev.end());

        ans += rev;

        return ans;
    }

    string lexPalindromicPermutation(string s, string target) {

        int n = s.size();
        int halfLen = n / 2;

        // ----------------------------------
        // 1. Count characters
        // ----------------------------------
        vector<int> cnt(26, 0);

        for (char c : s) {
            cnt[c - 'a']++;
        }

        // ----------------------------------
        // 2. Check palindrome possibility
        // ----------------------------------
        int odd = 0;
        char middle = '#';

        for (int i = 0; i < 26; i++) {

            if (cnt[i] % 2) {
                odd++;
                middle = char('a' + i);
            }
        }

        if (odd > 1)
            return "";

        // ----------------------------------
        // 3. Create counts for first half
        // ----------------------------------
        vector<int> halfCnt(26, 0);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // ----------------------------------
        // 4. Try to make half == target prefix
        // ----------------------------------
        string half;

        for (int i = 0; i < halfLen; i++) {

            int x = target[i] - 'a';

            if (halfCnt[x] > 0) {

                half.push_back(target[i]);
                halfCnt[x]--;

            } else {

                // target character unavailable.
                // Find the smallest character greater than target[i].
                int bigger = -1;

                for (int c = x + 1; c < 26; c++) {

                    if (halfCnt[c] > 0) {
                        bigger = c;
                        break;
                    }
                }

                if (bigger != -1) {

                    half.push_back(char('a' + bigger));
                    halfCnt[bigger]--;

                    // Fill remaining positions with smallest chars
                    for (int c = 0; c < 26; c++) {

                        while (halfCnt[c] > 0) {
                            half.push_back(char('a' + c));
                            halfCnt[c]--;
                        }
                    }

                    return buildPalindrome(half, middle);
                }

                // Cannot continue.
                break;
            }
        }

        // ----------------------------------
        // 5. If complete half == target prefix
        // ----------------------------------
        if ((int)half.size() == halfLen) {

            string candidate = buildPalindrome(half, middle);

            if (candidate > target)
                return candidate;
        }

        // ----------------------------------
        // 6. Backtrack to find the rightmost
        //    position that can be increased
        // ----------------------------------

        // Rebuild counts
        fill(halfCnt.begin(), halfCnt.end(), 0);

        for (int i = 0; i < 26; i++) {
            halfCnt[i] = cnt[i] / 2;
        }

        // Store the equal prefix again
        half.clear();

        for (int i = 0; i < halfLen; i++) {

            int x = target[i] - 'a';

            if (halfCnt[x] == 0)
                break;

            half.push_back(target[i]);
            halfCnt[x]--;
        }

        // ----------------------------------
        // Backtrack
        // ----------------------------------
        for (int pos = (int)half.size() - 1; pos >= 0; pos--) {

            int current = half[pos] - 'a';

            // Put the previous character back
            halfCnt[current]++;

            // Find smallest character > target[pos]
            for (int c = current + 1; c < 26; c++) {

                if (halfCnt[c] == 0)
                    continue;

                // Choose this bigger character
                half[pos] = char('a' + c);
                halfCnt[c]--;

                // Fill remaining positions minimally
                string resultHalf = half.substr(0, pos + 1);

                for (int x = 0; x < 26; x++) {

                    while (halfCnt[x] > 0) {
                        resultHalf.push_back(char('a' + x));
                        halfCnt[x]--;
                    }
                }

                return buildPalindrome(resultHalf, middle);
            }
        }

        return "";
    }
};