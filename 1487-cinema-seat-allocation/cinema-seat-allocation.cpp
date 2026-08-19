class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        map<int, vector<int>> mp;

        // Store reserved seats row-wise
        for (auto seat : reservedSeats) {
            mp[seat[0]].push_back(seat[1]);
        }

        // All rows are initially empty
        int ans = (n - mp.size()) * 2;

        // Check only rows having reservations
        for (auto &p : mp) {

            int row = p.first;
            vector<int> seats = p.second;

            bool left = true;
            bool middle = true;
            bool right = true;

            for (int seat : seats) {

                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};