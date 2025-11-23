class Solution {
public: vector<vector<long long>>dp;
    int func(int idx, vector<int>& nums, int sum) {
        if(idx >= nums.size()) {
           if(sum % 3 == 0)return 0;
           else return INT_MIN;
        }

        if(dp[idx][sum]!= -1)
           return dp[idx][sum];

        int take = nums[idx] + func(idx + 1, nums, (sum + nums[idx]) % 3);
        int notTake = func(idx + 1, nums, sum);

        return dp[idx][sum] = max(take, notTake);
    }
    
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
   
        dp.resize(n + 1, vector<long long>(3, -1));
        return func(0, nums, 0);
    }
};