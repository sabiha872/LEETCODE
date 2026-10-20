class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;

        for (int k = 1; k <= n; k++) {

            // k must divide n
            if (n % k != 0) {
                continue;
            }

            bool valid = true;
            int prevMax = -1;

            // Check every block of length k
            for (int start = 0; start < n; start += k) {

                int mn = nums[start];
                int mx = nums[start];
                int descents = 0;

                // Find minimum, maximum and descents
                for (int i = start; i < start + k; i++) {
                    mn = min(mn, nums[i]);
                    mx = max(mx, nums[i]);

                    int next = (i + 1 == start + k)
                               ? start : i + 1;

                    if (nums[i] > nums[next]) {
                        descents++;
                    }
                }

                // Block cannot be sorted by rotation
                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Blocks must remain in sorted order
                if (start > 0 && prevMax > mn) {
                    valid = false;
                    break;
                }

                prevMax = mx;
            }

            if (valid) {
                sum += k;
            }
        }

        return (int)sum;
    }
};