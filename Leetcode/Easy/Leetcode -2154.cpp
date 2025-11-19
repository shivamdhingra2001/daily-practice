class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int>st(nums.begin(), nums.end());
        int val = original;
        while(st.find(val) != st.end())val *=2;
        return val;
    }
};