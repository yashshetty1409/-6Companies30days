class Solution
{
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
    {
        int v = edges.size();
        vector<vector<int>> matrix(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            matrix[i][i] = 0;
        }
        for (int i = 0; i < v; i++)
        {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (matrix[i][k] == INT_MAX || matrix[k][j] == INT_MAX)
                        continue;
                    matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
                }
            }
        }

        int mn = INT_MAX;
        int ans;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] <= distanceThreshold)
                    count++;
            }
            if (count == mn)
            {
                ans = i;
            }
            else if (mn > count)
            {
                mn = count;
                ans = i;
            }
        }
        return ans;
    }
};