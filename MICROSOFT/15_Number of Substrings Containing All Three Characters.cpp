class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0; 
        int j=0; 
        int ans=0;
        vector<int>v(3,0); 
        for(j=0;j<s.length();j++){
            v[s[j]-'a']++; 
            while(v[0]>0 && v[1]>0 && v[2]>0 && i<=j){ 
                v[s[i]-'a']--; 
                ans+=(s.length()-j); 
                i++;
            }
        }
        return ans;
    }
};