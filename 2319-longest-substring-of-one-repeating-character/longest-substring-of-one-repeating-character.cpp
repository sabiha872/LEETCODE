class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        // start -> {end, character}
        map<int, pair<int, char>> runs;

        // Stores lengths of all runs
        multiset<int> lengths;

        // Add a run
        auto addRun = [&](int l, int r, char c) {
            if (l > r) return;

            runs[l] = {r, c};
            lengths.insert(r - l + 1);
        };

        // Remove a run
        auto removeRun = [&](int l) {
            auto it = runs.find(l);

            int r = it->second.first;
            int len = r - l + 1;

            auto lenIt = lengths.find(len);
            lengths.erase(lenIt);

            runs.erase(it);
        };

        // Build initial runs
        int start = 0;

        for (int i = 1; i <= n; i++) {

            if (i == n || s[i] != s[i - 1]) {
                addRun(start, i - 1, s[start]);
                start = i;
            }
        }

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {

            int pos = queryIndices[q];
            char newChar = queryCharacters[q];

            // Find the run containing pos
            auto it = runs.upper_bound(pos);
            --it;

            int l = it->first;
            int r = it->second.first;
            char oldChar = it->second.second;

            // If character doesn't change
            if (oldChar == newChar) {
                ans.push_back(*lengths.rbegin());
                continue;
            }

            // Remove old run
            removeRun(l);

            // Left part
            if (l <= pos - 1) {
                addRun(l, pos - 1, oldChar);
            }

            // Right part
            if (pos + 1 <= r) {
                addRun(pos + 1, r, oldChar);
            }

            // New character at pos
            addRun(pos, pos, newChar);

            /*
                Now merge with left and right if they
                have the same character.
            */

            auto cur = runs.find(pos);

            // Check left neighbor
            if (cur != runs.begin()) {

                auto left = prev(cur);

                if (left->second.first + 1 == pos &&
                    left->second.second == newChar) {

                    int leftStart = left->first;

                    removeRun(leftStart);
                    removeRun(pos);

                    addRun(leftStart, r = pos, newChar);

                    cur = runs.find(leftStart);
                }
            }

            // Check right neighbor
            auto right = next(cur);

            if (right != runs.end() &&
                cur->second.first + 1 == right->first &&
                right->second.second == newChar) {

                int newStart = cur->first;
                int newEnd = right->second.first;

                removeRun(newStart);
                removeRun(right->first);

                addRun(newStart, newEnd, newChar);
            }

            // Largest run
            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};