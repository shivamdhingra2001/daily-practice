class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op = 0;
        int len = 100;
        int n = nums.size();
        int count1 = count(nums.begin(), nums.end(), 1);
        if(count1 != 0) {
            return n - count1;
        }
        for(int i = 0; i<n; i++) {
            int __gcd = 0;
            for(int j = i; j<n; j++) {
                 if(gcd(nums[j], __gcd) == 1) {len = min(len, j - i + 1); break;}
                 __gcd = gcd(nums[j], __gcd);
            }
        }
        if(len == 100)
           return -1;
           cout<<len<<endl;
       return  len + n - 2;
    }
};