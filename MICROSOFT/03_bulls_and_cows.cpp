class Solution {
public:
    string getHint(string a, string b){
    int n=a.length(),x=0,y=0;
    for (int i = 0; i < a.length(); i++)
    {
        if(a[i]==b[i]){
            x++;
            a.erase(i,1);
            b.erase(i,1);
        --i;
        }
    }
    
    unordered_map<char,int> mpa,mpb;
    for (int i = 0; i < n-x; i++)
    {
        mpa[a[i]]++;
        mpb[b[i]]++;
    }
    for(auto x:mpa){
        y+=min(x.second,mpb[x.first]);
    }
    string ans="";
    ans+=to_string(x)+'A'+to_string(y)+'B';
    return ans;
    
    
}
};