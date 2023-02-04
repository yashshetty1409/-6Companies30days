class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for (int ind : w){
            if(s.empty())
                s.push_back(ind);
            else
                s.push_back(ind + s.back());
        }
    }
    
    int pickIndex() {
        int x = s.back();
        int index = rand() % x;
        auto it = upper_bound(s.begin(), s.end(),index);
        return it - s.begin();
    }
};