class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long sum = 0, maxi = LLONG_MIN;
        unordered_map<int, long long> mp; 

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = (i + 1) % k;

            if (rem == 0) {
                maxi = max(maxi, sum);
            }
            
            if (mp.count(rem)) {
                maxi = max(maxi, sum - mp[rem]);
            }

            if (!mp.count(rem)) mp[rem] = sum;
            else mp[rem] = min(mp[rem], sum);
        }
        return maxi;
    }
};