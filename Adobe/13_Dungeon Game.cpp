class Solution {
public:
    	int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n=dungeon.size(),m=dungeon[0].size();
        for(int i=n-1;i>=0;--i){
            for(int j=m-1;j>=0;--j){
                if(i==n-1 && j==m-1) dungeon[i][j]=dungeon[i][j];
                else if(i==n-1) dungeon[i][j]+=dungeon[i][j+1];
                else if(j==m-1) dungeon[i][j]+=dungeon[i+1][j];
                else dungeon[i][j]+=max(dungeon[i][j+1],dungeon[i+1][j]);
                
                if(dungeon[i][j]>0) dungeon[i][j]=0;
            }
        }
        return abs(dungeon[0][0])+1;
    }
};