class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find index of minimum and maximum
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex]) {
                minIndex = i;
            }

            if (nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        // left = smaller index
        // right = larger index
        int left = min(minIndex, maxIndex);
        int right = max(minIndex, maxIndex);

        // Three possible ways
        int bothFront = right + 1;

        int bothBack = n - left;

        int oneFrontOneBack = (left + 1) + (n - right);

        return min({bothFront, bothBack, oneFrontOneBack});
    }
};