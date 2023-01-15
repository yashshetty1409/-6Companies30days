class Solution {
public:
    bool increasingTriplet(vector<int>& n)
    {
        int     i, t;
        int     left = INT_MAX;
        int     right = INT_MAX;

        i = -1;
        while (++i < n.size())
        {
            t = n[i];
            if (t <= left)
                left = t;
            else if (t <= right)
                right = t;
            else
                return (true);
        }
        return (false);
    }
};