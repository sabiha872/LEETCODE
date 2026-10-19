class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        for(int i = 0; i < n ; i++) {
            if(target == nums[i]) {
                ans.push_back(i);
            }
            
        }
        return ans;
        
    }
};