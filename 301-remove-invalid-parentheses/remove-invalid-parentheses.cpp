class Solution {
public:

    unordered_set<string> ans;

    void solve(string& s, int index, int leftRemove,
               int rightRemove, int balance, string current) {

        // We reached the end
        if (index == s.length()) {

            if (leftRemove == 0 &&
                rightRemove == 0 &&
                balance == 0) {

                ans.insert(current);
            }

            return;
        }

        char ch = s[index];

        // Case 1: current character is '('
        if (ch == '(') {

            // Option 1: Remove it
            if (leftRemove > 0) {
                solve(s, index + 1,
                      leftRemove - 1,
                      rightRemove,
                      balance,
                      current);
            }

            // Option 2: Keep it
            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  balance + 1,
                  current + ch);
        }

        // Case 2: current character is ')'
        else if (ch == ')') {

            // Option 1: Remove it
            if (rightRemove > 0) {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove - 1,
                      balance,
                      current);
            }

            // Option 2: Keep it only if valid
            if (balance > 0) {
                solve(s, index + 1,
                      leftRemove,
                      rightRemove,
                      balance - 1,
                      current + ch);
            }
        }

        // Case 3: normal letter
        else {
            solve(s, index + 1,
                  leftRemove,
                  rightRemove,
                  balance,
                  current + ch);
        }
    }


    vector<string> removeInvalidParentheses(string s) {

        int leftRemove = 0;
        int rightRemove = 0;

        // Find minimum removals
        for (char ch : s) {

            if (ch == '(') {
                leftRemove++;
            }

            else if (ch == ')') {

                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        solve(s, 0, leftRemove, rightRemove, 0, "");

        return vector<string>(ans.begin(), ans.end());
    }
};