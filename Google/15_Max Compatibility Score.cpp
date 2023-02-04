class Solution
{
public:
    int ans = 0;
    void backtrack(vector<vector<int>> &students, vector<vector<int>> &mentors, int idx, int curr_res, vector<int> &vis)
    {
        if (idx >= mentors.size())
        {
            ans = max(ans, curr_res);
            return;
        }
        for (int i = 0; i < students.size(); i++)
        {
            if (vis[i] != 0)
                continue;
            int temp = 0;
            vis[i] = 1;
            for (int j = 0; j < students[i].size(); j++)
            {
                if (students[i][j] == mentors[idx][j])
                {
                    temp++;
                }
            }
            backtrack(students, mentors, idx + 1, curr_res + temp, vis);
            vis[i] = 0;
        }
    }
    int maxCompatibilitySum(vector<vector<int>> &students, vector<vector<int>> &mentors)
    {
        vector<int> vis(students.size(), 0);
        backtrack(students, mentors, 0, 0, vis);
        return ans;
    }
};
