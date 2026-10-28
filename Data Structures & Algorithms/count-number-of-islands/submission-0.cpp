class Solution {
   public:
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& vis, int m , int n) {
        // if()
        if (grid[i][j] == '0' || vis[i][j] == 1) return;
        vis[i][j]=1;
        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int row = delrow[k] + i;
            int col = delcol[k] + j;
            if (row < 0 || col >= n || row >= m || col < 0 || vis[row][col] ||
                grid[row][col] == '0')
                continue;
            dfs(row, col, grid, vis, m, n);
        }
        // dfs(i+1, j, grid , vis);
        // dfs(i, j+1, grid , vis);
        // dfs(i-1, j, grid , vis);
        // dfs(i-1, j-1, grid , vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>>vis(m , vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1'){
                    cnt++;
                    dfs(i , j , grid , vis , m , n);
                }
            }
        }
        return cnt;
    }
};
