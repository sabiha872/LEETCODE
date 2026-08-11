class Solution {
public:
    int missingInteger(vector<int>& nums) {
       int sum = nums[0];
       for(int i = 1; i <nums.size(); i++) {
          if(nums[i] == nums[i-1]+1)
             sum+=nums[i];
           else {
              break;
        }
       }
        sort(nums.begin(), nums.end());
        int x = sum;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == x) {
                x++;
            }
        } 
        return x;
       }
};