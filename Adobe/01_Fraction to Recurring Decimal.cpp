class Solution {
public:
    string fractionToDecimal(int n, int d) {
        int cnt = 0;
        if(n == 0) return "0";
        if(n < 0) cnt++;
        if(d < 0) cnt++;
        n = abs(n);
        d = abs(d);        
        long long rem = n%d;
        long long q = n/d;
        string ans = "";
        ans += to_string(q);
        if(rem == 0) {
            if(cnt == 1) return "-"+ans;
            else return ans;
        }
        unordered_map<int,int>mp;
        ans += ".";
        while(rem != 0){
            if(mp.find(rem) != mp.end()){
                int len = mp[rem];
                string s1 = ans.substr(0,len);
                string s2 = ans.substr(len);
                ans = s1+"("+s2+")";
                break;
            }
            else{
                mp[rem] = ans.size();
                rem *= 10;
                q = rem/d;
                rem = rem%d;
                ans += to_string(q);
            }
        }
        if(cnt == 1) return "-"+ans;
        return ans;
    }
};