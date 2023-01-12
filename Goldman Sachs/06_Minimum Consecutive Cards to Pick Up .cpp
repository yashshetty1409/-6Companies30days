class Solution {
public:
    int minimumCardPickup(vector<int>& v) {
    map<int,int> mp;
    int n=v.size(),ans=INT_MAX;
    for(auto x:v){
        mp[x]++;
    }
    if(mp.size()==v.size()){
        return -1;
        }
    int arr[1000002];
    for (int i = 0; i < 1000002; i++)
    {
        arr[i]=-1;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(arr[v[i]]==-1){
            arr[v[i]]=i;
            continue;
        }
        else{
            ans=min(ans,i-arr[v[i]]+1);
            arr[v[i]]=i;

        }
    }
    return ans;
        
    }
};