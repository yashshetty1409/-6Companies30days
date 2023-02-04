class Solution
{
public:
    int n, m;

    int bound(int i, int j, const vector<vector<int>> &dp)
    {
        if (i < 0 || j < 0)
            return 0;
        if (i >= n)
            i = n - 1;
        if (j >= m)
            j = m - 1;
        return dp[i + 1][j + 1];
    }
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &matrix, int k)
    {
        n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp;
        dp.resize(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                dp[i + 1][j + 1] = dp[i + 1][j] + matrix[i][j] + dp[i][j + 1] - dp[i][j];
            }
        }
        int i = 1;
        cout << bound(1, 1, dp);
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                ans[i][j] = bound(i + k, j + k, dp) - bound(i - k - 1, j + k, dp) - bound(i + k, j - k - 1, dp) + bound(i - k - 1, j - k - 1, dp);
            }
        }
        return ans;
    }
};