class Solution {
public:
    int reverseDegree(string s) {
         int ans = 0;
         for(int i = 0; i< s.length(); i++){
            int reverseValu = 26 - (s[i]-'a');
            int pos = i+1;
            ans += reverseValu*pos;
         }
            return ans;
         }
        
    
};