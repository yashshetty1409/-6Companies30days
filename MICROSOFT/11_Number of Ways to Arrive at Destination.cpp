class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<vector<int>>>adjL(n);
        vector<long>dist(n,LONG_MAX);
        for(int i=0;i<roads.size();i++)
        {
            adjL[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adjL[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        int MOD = 1000000007;
        vector<long>ways(n,0);
        ways[0] = 1;
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<>>pQ;
        pQ.push({0,0});
        dist[0] = 0;
        long cost;
        int node;        
        while(!pQ.empty())
        {
            cost = pQ.top().first;
            node = pQ.top().second;
            pQ.pop();
            if(dist[node]<cost)continue;
            for(auto &adj: adjL[node])
            {
                if(dist[node]+adj[1] < dist[adj[0]])
                {
                    dist[adj[0]] = dist[node]+adj[1];
                    ways[adj[0]] = ways[node];
                    pQ.push({dist[adj[0]],adj[0]});
                }
                else if(dist[node]+adj[1] == dist[adj[0]])
                {
                    ways[adj[0]] = (ways[adj[0]] + ways[node])%MOD;
                }
            }
        }
        return ways[n-1];
    }
};