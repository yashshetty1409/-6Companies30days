class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        
        sort(begin(nums), end(nums));
        
        int n = nums.size();
        
        if(n<2) return nums;
        
        vector<int> dp(n, 1);
        vector<int> hash(n, -1);
        
        int sz=0; int id = -1;
        
        for(int i=1; i<n; i++){
            
            for(int prev=0; prev<i; prev++){
                
                if(nums[i]%nums[prev] == 0 and dp[prev]+1 > dp[i]){
                    dp[i] = 1+dp[prev];
                    hash[i] = prev;
                }
                
            }
            if(dp[i] > sz){
               sz = dp[i];
               id = i;
            }
        }
        
        vector<int> ans;
        
        while(id != -1){
            ans.push_back(nums[id]);
            id = hash[id];
        }
        
        return ans;
    }
};