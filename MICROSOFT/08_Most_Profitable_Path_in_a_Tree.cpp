class Solution {
typedef long long ll;
#define vi(x) vector<x>
public:
vi(vi(ll)) g; 
ll n;
vi(ll)tsb; 
bool bdfs(ll nd, ll ts, ll par){ 
    tsb[nd]=ts;
    if(nd==0){
        return 1;
    }
    for(ll child:g[nd]){
        if(child!=par && bdfs(child, ts+1, nd)){
            return 1;
        }
    }
    tsb[nd]=-1;
    return 0;
}
ll adfs(ll par, ll nd, ll ts, const vi(int)&cost){ 
    ll ans=LLONG_MIN;
    for(ll child:g[nd]){
        if(child!=par){
            ans=max(ans, adfs(nd, child, ts+1, cost));
        }
    }
    if(ans==LLONG_MIN){
        ans=0;
    }
    if(tsb[nd]==-1 || tsb[nd]>ts){
        ans+=cost[nd];
    } 
    else if(tsb[nd]==ts){
        ans+=cost[nd]/2; 
    }
    return ans;
}
    int mostProfitablePath(vector<vector<int>>&e, int bob, vector<int>&v) {
        n=v.size(), g.resize(n), tsb.assign(n, -1);
        for(const auto&edge:e){
            g[edge[0]].pb(edge[1]), g[edge[1]].pb(edge[0]);
        }
        bdfs(bob, 0, -1);
        return adfs(-1, 0, 0, v);
    }
};