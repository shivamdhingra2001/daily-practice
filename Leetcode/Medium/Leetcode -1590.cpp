class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        unordered_map<long long, long long>mp;
        long long sum = 0;
        mp[0] = -1;
        for(int i = 0; i<nums.size(); i++)sum = (sum + nums[i]) % p;


        long long target = sum % p;
        long long curr = 0;
        long long ans = n;

        if(target == 0) return 0;

        for(int i = 0; i<nums.size(); i++) {
            curr += nums[i];
            curr %= p;
            
            long long match = (curr - target + p) % p;

            if(mp.find(match) != mp.end()) 
                ans = min(ans, i - mp[match]);
            
            mp[curr % p] = i;
        }
        if(ans == n)return -1;
        else return ans;
    }
};
// // 10
// // 3 -> 0;
// // 4 -> 1;
// // 8 -> 2;

// (curr - target + 6 )% 4
// curr - match = target

// (2 - 4 + 6) % 6