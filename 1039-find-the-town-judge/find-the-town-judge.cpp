class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        //1 value pair denotes ho many he trust 
        // 2 value denote how many  trust him
        vector<pair<int,int>> arr(N+1,{0,0});
        for(int i =0; i<trust.size();++i) {
            arr[trust[i][0]].first += 1;
            arr[trust[i][1]].second +=1;
        }
        // now find who is trusted by N-1 other and he dont trust other
        for(int i = 1; i <= N; ++i)
           if(arr[i].first==0 &&arr[i].second==N-1)
              return i;
        return -1;
        
    }
};