class Solution {
public:
    int n, m;
    const int mod = 1000000007;
    vector<vector<vector<int>>> dp;
    int func(int i, int j, vector<vector<int>>& grid, int k, int sum) {
        if(i == n - 1 && j == m - 1) {
            int val = (sum + grid[i][j]) % k;
            return val == 0;
        }
        if(dp[i][j][sum] != -1)
           return dp[i][j][sum];

        int right = 0;
        int down = 0;
        int newSum = (sum + grid[i][j]) % k;
        if(j + 1 < m) {
            right = func(i, j + 1, grid, k, newSum) % mod;
        }
        if(i + 1 < n) {
            down = func(i + 1, j, grid, k, newSum) % mod;
        }
        return dp[i][j][sum] = (right + down) % mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
       n = grid.size();
       m = grid[0].size();
       dp.resize(n, vector<vector<int>>(m, vector<int>(51 , -1)));
       return func(0, 0, grid, k, 0);
    }
};