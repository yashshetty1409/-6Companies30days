class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int ans=0, n=points.size();
        for(int i=0;i<n;i++) {
            unordered_map<int,int> mp;
            for(int j=0;j<n;j++) {
                if(i==j) {
                    continue;
                }
                int distance=((points[i][0]-points[j][0])*(points[i][0]-points[j][0]))+((points[i][1]-points[j][1])*(points[i][1]-points[j][1]));
                mp[distance]++;
            }
            for(auto k: mp) {
                ans+=(k.second*(k.second-1));
            }
        }
        return ans;
    }
};