class Solution {
public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        vector<int>ans;
        int answer1=0;
        for(int i=0; i<(1<<12); i++)
        {
            int cnt=i;
            int tot=0,answer=0;
            vector<int>v(12,0);
            for(int j=0; j<12; j++)
            {
                if(cnt&(1<<j))
                {
                    tot+=aliceArrows[j]+1;
                    answer+=j;
                    v[j]=aliceArrows[j]+1;
                }
            }
            if(tot<=numArrows)
            {
                if(answer>answer1)
                {
                    answer1=answer;
                    int val=numArrows-tot;
                    v[11]+=val;
                    ans=v;
                }
            }
        }
        
        return ans;
    }
};