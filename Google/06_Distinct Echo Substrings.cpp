class Solution
{
public:
    int distinctEchoSubstrings(string text)
    {
        unordered_set<string_view> ddw;
        const char *cstr = text.c_str();
        int n = text.size() / 2;
        for (int i = 1; i <= n; i++)
        {
            int l = 0, r = i, c = 0;
            while (r < text.size())
            {
                if (cstr[l++] == cstr[r++])
                {
                    c++;
                }
                else
                {
                    c = 0;
                }
                if (c >= i && c < i * 2)
                {
                    ddw.insert(string_view(cstr + l, i));
                }
            }
        }
        return ddw.size();
    }
};