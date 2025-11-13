class Solution {
public:
    int maxOperations(string s) {
        int count = 0;
        int ans = 0;
        int flag = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '0' && flag) {
                ans += count;
                flag = 0;
            }
            if(s[i] == '1') {
                flag = 1;
                count++;
            }
        }
        return ans;
    }
};