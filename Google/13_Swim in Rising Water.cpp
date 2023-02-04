class Node
{
public:
    int time;
    int x;
    int y;
};

bool operator<(const Node &a, const Node &b)
{
    return a.time > b.time;
}

struct pair_hash
{
    inline std::size_t operator()(const std::pair<int, int> &v) const
    {
        return v.first * 31 + v.second;
    }
};

class Solution
{
public:
    int swimInWater(vector<vector<int>> &grid)
    {
        unordered_set<pair<int, int>, pair_hash> seen;
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<Node> q;
        auto isValidCell = [&](int a, int b)
        {
            return a >= 0 && a < n && b >= 0 && b < m;
        };
        q.push({grid[0][0], 0, 0});
        seen.insert({0, 0});
        int res = 0;
        while (q.size() > 0)
        {
            Node node = q.top();
            q.pop();
            res = max(res, node.time);
            if (node.x == n - 1 && node.y == m - 1)
                return res;
            int dir[] = {-1, 0, 1, 0, -1};
            for (int k = 0; k < 4; ++k)
            {
                int u = node.x + dir[k];
                int v = node.y + dir[k + 1];
                if (isValidCell(u, v) && seen.count({u, v}) <= 0)
                {
                    q.push({grid[u][v], u, v});
                    seen.insert({u, v});
                }
            }
        }
        return -1;
    }
};