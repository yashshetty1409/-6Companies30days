class Solution {
public:
    int rev(int n)   
    {
        int ans=0;
        while(n!=0)
        {
            ans=ans*10+n%10;
            n/=10;
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> um; 
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            int tmp=nums[i]-rev(nums[i]);       
            um[tmp]++;
            ans=(ans+um[tmp]-1)%1000000007;   
        }
        return ans%1000000007;
    }
};