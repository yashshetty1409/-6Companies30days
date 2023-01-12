class Solution
{
public:
    bool isPossible(vector<int> &nums)
    {
        map<int, int> mp1, mp2;
        for (int i : nums)
        {
            mp1[i]++;
        }
        for (int i : nums)
        {
            if (mp1[i] == 0)
                continue;
            if (mp2[i] > 0)
            {
                mp2[i]--;
                mp2[i + 1]++;
                mp1[i]--;
            }
            else if (mp1[i] > 0 && mp1[i + 1] > 0 && mp1[i + 2] > 0)
            {
                mp1[i]--;
                mp1[i + 1]--;
                mp1[i + 2]--;
                mp2[i + 3]++;
            }
            else
                return false;
        }
        return true;
    }
};