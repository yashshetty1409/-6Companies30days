class Solution {
public:
int diff(string a,string b){
        if(a.length()!=b.length()){
            return 0;
        }
        int diff_char=0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                diff_char++;
            }
        }
        return diff_char;
    }
    int minMutation(string start, string end, vector<string>& bank) {
        queue<string> q;
        vector<int> vis(bank.size(),0);
        q.push(start);
        int ans=0;
        while(!q.empty()){
            queue<string> nq;
            while(!q.empty()){
                    string cur=q.front();
                    q.pop();
                    if(cur==end){
                        return ans;
                    } 
                    for(int i=0;i<bank.size();i++){
                        if(!vis[i]){
                           if(diff(cur,bank[i])==1){
                               nq.push(bank[i]);
                               vis[i]=1;
                           }
                        }
                    }
            }
            q=nq;
            ans++;
        }
        return -1;
		}
};