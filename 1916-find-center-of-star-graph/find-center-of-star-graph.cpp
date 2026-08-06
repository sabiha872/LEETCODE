class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, int> degree;
        for(auto &vec : edges) {
            int u = vec[0];
            int v = vec[1];

            degree[u]++;
            degree[v]++;
        }
        for(auto &it: degree) {
            if(it.second == edges.size()) {
                return it.first;     
            }
        }
            return -1;    
    }
};