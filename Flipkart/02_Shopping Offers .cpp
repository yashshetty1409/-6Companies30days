class Solution {
public:
    bool isValid(vector<int>& needs, vector<vector<int>>& special, int i){
        for(int j=0;j<needs.size();j++) if(special[i][j]>needs[j]) return false;
        return true;
    }
    bool isEmpty(vector<int>& needs){
        for(int item:needs) if(item!=0) return false;
        return true;
    }
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int> needs, map<vector<int>,int>& dp){
        if(dp.count(needs)) return dp[needs];
        if(isEmpty(needs)){
            return dp[needs]=0;
        }
        int min_price = INT_MAX;
        for(int i=0;i<special.size();i++){
            if(isValid(needs, special, i)){
                for(int j=0;j<needs.size();j++) needs[j] -= special[i][j];
                int lprice = special[i][needs.size()]+solve(price,special,needs,dp);
                min_price = min(min_price, lprice);
                for(int j=0;j<needs.size();j++) needs[j] += special[i][j];
            }
        }
        int lprice = 0;
        for(int i=0;i<needs.size();i++) lprice += needs[i]*price[i];
        min_price = min(min_price, lprice);
        return dp[needs]=min_price;
    }

    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
         map<vector<int>, int> dp;
         return solve(price, special, needs, dp);
    }
};