class Solution
{
public:
    int numberOfCombinations(string num)
    {
        int dp[3501] = {}, dpp[3501] = {}, n = num.size(), mod = 1000000007;
        for (int l = 1; l <= n; ++l)
        {
            dpp[0] = 1;
            for (int i = 0; i < n; ++i)
            {
                dp[i + 1] = dpp[i + 1];
                if (l <= i + 1 && num[i + 1 - l] != '0')
                {
                    if (i + 1 - 2 * l >= 0 && num.compare(i + 1 - 2 * l, l, num, i + 1 - l, l) <= 0)
                        dp[i + 1] = (dp[i + 1] + dp[i + 1 - l]) % mod;
                    else
                        dp[i + 1] = (dp[i + 1] + dpp[i + 1 - l]) % mod;
                }
            }
            swap(dp, dpp);
        }
        return dpp[n];
    }
};