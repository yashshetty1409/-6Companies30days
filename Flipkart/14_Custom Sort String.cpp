class Solution
{
public:
    string customSortString(string order, string s)
    {
        unordered_map<char, int> mp;
        for (auto i : s)
            mp[i]++;
        string ans;
        for (auto j : order)
        {
            int n = mp[j];
            for (int i = 0; i < n; i++)
            {
                ans += j;
                mp[j]--;
            }
        }
        for (auto k : mp)
        {
            if (k.second != 0)
            {
                for (int i = 0; i < k.second; i++)
                {
                    ans += k.first;
                    mp[k.first]--;
                }
            }
        }
        return ans;
    }
};