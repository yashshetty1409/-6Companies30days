class Solution {
public:
    int trailingZeroes(int n) {
        int ans=0;
       for (int i = 5; i <=n; i+=5)
     {
         int k=i;
        while(k%5==0){
            ans++;
            k/=5;
        }
     }
     return ans;
    }
};