class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();

        vector<vector<bool>> dp(n+1, vector<bool>(n+1, false));

        dp[0][0] = true;
        for(int i = 0; i < n; i++) {
            for(int open = 0; open <= n; open++) {
                if(dp[i][open] == false)
                  continue;

                if(s[i] == '(') {
                    dp[i+1][open + 1] = true;
                }
                else if(s[i] == ')') {
                    if(open > 0) {
                        dp[i + 1][open - 1] = true;
                    }
                }
                else {
                dp[i + 1][open + 1] = true;
                if(open > 0) {
                    dp[i + 1][open - 1] = true;
                }
                dp[i + 1][open] = true;
            }
        }
        
    }
    return dp[n][0];
  }
};