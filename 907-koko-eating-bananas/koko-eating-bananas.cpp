class Solution {
public:
    int minEatingSpeed(vector<int>& nums, int h) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        while (low <= high) {
            int mid = low + (high - low) / 2;
            long long ans = 0;
            for(int num : nums) {
                ans += (num + mid - 1LL) / mid;

            }
            if (ans <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        } return low;
    }
};