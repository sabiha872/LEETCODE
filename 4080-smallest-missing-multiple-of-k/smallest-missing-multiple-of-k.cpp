class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int multiple = k;
        while(true) {
            bool found = false;

            for(int x : nums) {
                if(x == multiple) {
                    found = true;
                    break;
                }
            }
            if(found == false)
               return multiple;
            
           multiple = multiple + k;
        }
        
    }
};