class Solution
{
public:
    int peopleAwareOfSecret(int n, int d, int f)
    {
        vector<long long> ans(n + 1, 0);
        const int mod = 1e9 + 7;
        ans[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            if (ans[i])
            {
                for (int j = i + d; j <= n && j <= (i + f - 1); j++)
                {
                    ans[j] = ((ans[j]) % mod + (ans[i]) % mod) % mod;
                }
            }
        }
        long long temp = 0;
        for (int i = n; i >= (n - f + 1) && i >= 1; i--)
            temp = ((temp) % mod + (ans[i]) % mod) % mod;
        return temp % mod;
    }
};