class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {

            int maxLeft = nums[0];

            for (int j = 0; j <= i; j++) {
                maxLeft = max(maxLeft, nums[j]);
            }

            int minRight = nums[i];

            for (int j = i; j < n; j++) {
                minRight = min(minRight, nums[j]);
            }

            int instability = maxLeft - minRight;

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};