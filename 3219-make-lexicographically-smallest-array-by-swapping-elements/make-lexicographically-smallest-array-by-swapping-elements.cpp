class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        
        int n = nums.size();

        // Step 1: Make a sorted copy
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());

        // Step 2: Divide numbers into groups
        int groupNum = 0;

        unordered_map<int, int> numToGroup;
        unordered_map<int, vector<int>> groupToList;

        numToGroup[vec[0]] = groupNum;
        groupToList[groupNum].push_back(vec[0]);

        for(int i = 1; i < n; i++) {

            // If difference is greater than limit,
            // we cannot swap these numbers
            if(vec[i] - vec[i - 1] > limit) {
                groupNum++;
            }

            numToGroup[vec[i]] = groupNum;
            groupToList[groupNum].push_back(vec[i]);
        }

        // Step 3: Build the answer
        vector<int> result(n);

        // Keeps track of which element we have used
        unordered_map<int, int> index;

        for(int i = 0; i < n; i++) {

            int num = nums[i];

            // Find which group this number belongs to
            int group = numToGroup[num];

            // Take the smallest unused number
            result[i] = groupToList[group][index[group]];

            index[group]++;
        }

        return result;
    }
};