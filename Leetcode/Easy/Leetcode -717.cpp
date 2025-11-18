class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int i = 0;
        while (i < bits.size()) {
            if (bits[i] == 1) {
                i += 2;
                if (i == bits.size())
                    return false;
            } else {
                i++;
                if (i == bits.size())
                    return true;
            }
        }
        return false;
    }
};