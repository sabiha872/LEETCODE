class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& grid) {
        // Grid ke bahar chale gaye
        if (r < 0 || r >= m || c < 0 || c >= n)
            return;

        // Water hai, toh aage nahi jaana
        if (grid[r][c] == 1)
            return;

        // Is land ko visited mark kar do
        grid[r][c] = 1;

        // 4 directions mein explore karo
        dfs(r - 1, c, grid); // Up
        dfs(r + 1, c, grid); // Down
        dfs(r, c - 1, grid); // Left
        dfs(r, c + 1, grid); // Right
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Step 1: Boundary wale open islands hatao
        for (int i = 0; i < m; i++) {
            if (grid[i][0] == 0)
                dfs(i, 0, grid);

            if (grid[i][n - 1] == 0)
                dfs(i, n - 1, grid);
        }

        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0)
                dfs(0, j, grid);

            if (grid[m - 1][j] == 0)
                dfs(m - 1, j, grid);
        }

        // Step 2: Bache hue islands count karo
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(i, j, grid);
                }
            }
        }

        return count;
    }
};