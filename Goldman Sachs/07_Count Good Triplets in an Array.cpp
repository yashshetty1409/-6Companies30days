#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key
class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        pbds s;
        int n = nums1.size();
        vector<int> pos(n);
        for(int i=0;i<n;i++){
            pos[nums2[i]] = i;
        }
        vector<int> pref(n), suff(n);
        for(int i=0;i<n;i++){
            pref[i] = s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
        s.clear();
        for(int i=n-1;i>=0;i--){
            suff[i] = s.size() - s.order_of_key(pos[nums1[i]]);
            s.insert(pos[nums1[i]]);
        }
        long long ans = 0;
        for(int i=0;i<n;i++){
            ans += pref[i] * 1LL * suff[i];
        }
        return ans;
    }
};