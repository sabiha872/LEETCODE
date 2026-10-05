class Solution {
public:
int solve(string &s, int &i) {
    int score = 0;

    while(i < s.length() && s[i] == '(') {
        i++;

        if(s[i] == ')') {
            score +=1;
            i++;
        }
        else {
            int inside = solve(s, i);
            score += 2* inside;
            i++;
        }
    }
    return score;
}
    int scoreOfParentheses(string s) {
        int  i = 0;
        return solve(s, i);
    }
};