class Solution {
public: 
int dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& vis, int m , int n, int& area ) {
        // if()
        if (grid[i][j] == 0 || vis[i][j] == 1) return 0;
        vis[i][j]=1;
        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, 1, -1};
        for (int k = 0; k < 4; k++) {
            int row = delrow[k] + i;
            int col = delcol[k] + j;
            if (row < 0 || col >= n || row >= m || col < 0 || vis[row][col] ||
                grid[row][col] == 0)
                continue;
                area=area+1;
            dfs(row, col, grid, vis, m, n , area);
        }

        return area;
        // dfs(i+1, j, grid , vis);
        // dfs(i, j+1, grid , vis);
        // dfs(i-1, j, grid , vis);
        // dfs(i-1, j-1, grid , vis);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxarea = 0;
        int m = grid.size(), n = grid[0].size(), area=0;
        vector<vector<int>>vis(m , vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == 1){
                int area=1;
                   maxarea=max(maxarea,dfs(i , j , grid , vis , m , n, area));
                }
            }
        }
        return maxarea;
    }
};
