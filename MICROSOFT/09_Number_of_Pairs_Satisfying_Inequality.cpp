class Solution {
    using ll = long long;
public:
    static ll numberOfPairs(const vector<int>& nums1, const vector<int>& nums2, const int diff) {
        const int n = size(nums1);
        vector<ll> arr(n);
        for (int i = 0; i < n; ++i)
            arr[i] = ll(nums1[i]) - nums2[i];
        ll ret = 0;

        function<void(int, int)> merge = [&] (int low, int hi) {
            if(low >= hi)
                return;
            int mid = ((hi - low) >> 1) + low;
            merge(low, mid);
            merge(mid + 1, hi);
            int i = low, j = mid + 1;
            while (i <= mid && j <= hi)
                if (arr[i] <= arr[j] + diff) 
                    ret += (hi - j + 1), ++i;
                else
                    ++j;
            inplace_merge(begin(arr) + low, begin(arr) + mid + 1, begin(arr) + hi + 1);
        };

        merge(0, n - 1);
        return ret;
    }
};