class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> freq(51, 0);

        // Every subarray of size k
        for (int i = 0; i <= n - k; i++) {
            
            set<int> st;

            // Elements inside this subarray
            for (int j = i; j < i + k; j++) {
                st.insert(nums[j]);
            }

            // Count how many subarrays contain each number
            for (int x : st) {
                freq[x]++;
            }
        }

        int ans = -1;

        // Find largest number appearing in exactly one subarray
        for (int x = 0; x <= 50; x++) {
            if (freq[x] == 1) {
                ans = x;
            }
        }

        return ans;
    }
};