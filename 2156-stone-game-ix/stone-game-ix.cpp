class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {

        int cnt[3] = {0};

        // Count remainders
        for (int x : stones) {
            cnt[x % 3]++;
        }

        // No 1 or 2 stones
        if (cnt[1] == 0 && cnt[2] == 0) {
            return false;
        }

        // Even number of 0-remainder stones
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }

        // Odd number of 0-remainder stones
        return abs(cnt[1] - cnt[2]) > 2;
    }
};