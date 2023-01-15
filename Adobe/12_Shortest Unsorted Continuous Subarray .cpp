class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) 
    {
        int n=nums.size();
        int left=0, right=0;
        for(int i=0; i<n-1; i++)
        {
            if(nums[i+1]<nums[i]) 
            {
                left=i;
                break;
            }
        }
        for(int i=n-1; i>0; i--)
        {
            if(nums[i]<nums[i-1])
            {
                right=i;
                break;
            }
        }
        int mn=INT_MAX, mx=INT_MIN;
         if(left == right) return 0;
        int ans = right-left+1;
        
        for(int i=left; i<=right; i++)
        {
            mn = min(nums[i], mn);
            mx = max(nums[i], mx);
        }
        while(left-1 >= 0 && nums[left-1]>mn)
        {
            ans++;
            left--;
        }
        
        while(right+1 <= n-1 && nums[right+1]<mx)
        {
            ans++;
            right++;
        }
        return ans;
    }
    
};