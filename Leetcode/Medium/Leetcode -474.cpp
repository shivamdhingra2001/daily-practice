class Solution {
public:
    int dp[601][101][101];
    int func(int idx, vector<string>& strs, int m, int n) {
        if(idx >= strs.size())
           return 0;

        if(dp[idx][m][n] != -1)
           return dp[idx][m][n];
        int count0 = count(strs[idx].begin(), strs[idx].end(), '0');
        int count1 = strs[idx].size() - count0;
        
        int take = 0;
        if(m - count0 >= 0  && n - count1 >= 0) {
            take = 1 + func(idx + 1, strs, m - count0, n - count1);
        }
        int notTake = func(idx + 1, strs, m, n);

        return dp[idx][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        memset(dp, -1, sizeof(dp));
        return func(0, strs, m, n);
    }
};