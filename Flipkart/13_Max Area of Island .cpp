class Solution
{
public:
    void dfs(int sr, int sc, int &area, vector<vector<int>> &grid)
    {
        if (!(sr >= 0 && sr < grid.size() && sc >= 0 && sc < grid[0].size() && grid[sr][sc] == 1))return;
        area++;
        grid[sr][sc] = 0;
        dfs(sr - 1, sc, area, grid);
        dfs(sr, sc + 1, area, grid);
        dfs(sr + 1, sc, area, grid);
        dfs(sr, sc - 1, area, grid);
    }
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int max_area = 0;
        int area = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == 1)
                {
                    dfs(i, j, area, grid);
                    max_area = max(max_area, area);
                    area = 0;
                }
            }
        }
        return max_area;
    }
};