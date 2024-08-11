class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    bool inBound(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }

    void dfs(int row, int col, int n, int m, vector<vector<int>>& grid) {
        grid[row][col] = -1;  
        for (auto d : dirs) {
            int newRow = row + d.first;
            int newCol = col + d.second;
            if (inBound(newRow, newCol, n, m) && grid[newRow][newCol] == 1) {
                dfs(newRow, newCol, n, m, grid);
            }
        }
    }

    int countIslands(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int count = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    count++;
                    dfs(i, j, n, m, grid);
                }
            }
        }

        return count;
    }

    int minDays(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> originalGrid = grid;
        if (countIslands(originalGrid) != 1) return 0;
        originalGrid=grid;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0; 
                    int a=countIslands(grid);
                    if (a != 1) return 1;  
                    grid[i][j] = 1;  
                    grid=originalGrid;
                }
            }
        }

        return 2;
    }
};
/*
[[1,1,0,1,1]
,[1,1,1,1,1]
,[1,1,0,1,1]
,[1,1,0,1,1]]
*/
