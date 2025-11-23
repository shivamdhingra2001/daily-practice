class Solution {
public: vector<vector<int>>dp;
    int func(int idx, int sum, int target, vector<int>& stones) {
          if(sum >= target) {
             return sum;
          }

          if(idx >= stones.size())
             return 1e9;
             
          if(dp[idx][sum] != -1) 
             return dp[idx][sum];

          int take = func(idx + 1, sum + stones[idx], target, stones);
          int notTake = func(idx + 1, sum, target, stones);

          return dp[idx][sum] = min(take, notTake);

    }
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int half = (sum + 1)/2;
        dp.resize(n, vector<int>(3001, -1));
        int val = func(0, 0, half, stones);
        return abs(2*val - sum);
    }
};
1