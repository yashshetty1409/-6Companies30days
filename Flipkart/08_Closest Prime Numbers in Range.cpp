class Solution
{
public:
    vector<bool> primes;
    void setPrimes(ll n)
    {
        primes.assign(n + 1, 1);
        primes[0] = primes[1] = 0;
        for (long long i = 2; i * i <= n; i++)
        {
            if (primes[i])
            {
                for (ll j = i; j * i <= n; ++j)
                {
                    primes[j * i] = 0;
                }
            }
        }
    }
    vector<int> closestPrimes(int l, int r)
    {
        setPrimes(r);
        long long pre = -1; 
        vector<int> ans = {-1, -1};
        for (long long i = l; i <= r; ++i)
        {
            if (!primes[i])
            {
                continue;
            }
            if (pre > -1 && (ans[0] == -1 || i - pre < ans[1] - ans[0]))
            {
                ans = {int(pre), int(i)};
            }
            pre = i;
        }
        return ans;
    }
};