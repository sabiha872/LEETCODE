class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        vector<vector<int>> dist(2, vector<int>(n, -1));
        queue<pair<int, int>> q;

        // orientation 0 = original orientation
        // orientation 1 = reversed orientation
        q.push({0, 0});
        dist[0][0] = 0;

        while (!q.empty()) {
            auto [orientation, k] = q.front();
            q.pop();

            bool sorted = true;

            for (int i = 0; i < n; i++) {
                int idx;

                if (orientation == 0) {
                    idx = (i + k) % n;
                } else {
                    idx = (n - 1 - i + k + n) % n;
                }

                if (nums[idx] != i) {
                    sorted = false;
                    break;
                }
            }

            if (sorted) {
                return dist[orientation][k];
            }

            // Operation 1: Rotate left by one
            int nextK = (orientation == 0)
                            ? (k + 1) % n
                            : (k - 1 + n) % n;

            if (dist[orientation][nextK] == -1) {
                dist[orientation][nextK] =
                    dist[orientation][k] + 1;
                q.push({orientation, nextK});
            }

            // Operation 2: Reverse entire array
            int nextOrientation = 1 - orientation;

            if (dist[nextOrientation][k] == -1) {
                dist[nextOrientation][k] =
                    dist[orientation][k] + 1;
                q.push({nextOrientation, k});
            }
        }

        return -1;
    }
};