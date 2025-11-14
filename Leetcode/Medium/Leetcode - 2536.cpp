class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {

        vector<vector<int>>ans(n, vector<int>(n, 0));

        for(auto &i : queries) {
            int r = i[0], c = i[1], R = i[2], C = i[3];

            for(int i = r; i<=R; i++) {
               ans[i][c]++;
               if(C + 1 < n)ans[i][C + 1]--;
            }

        }
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(j == 0)continue;
                ans[i][j] += ans[i][j - 1];
            }
        }
        return ans;
    }
};