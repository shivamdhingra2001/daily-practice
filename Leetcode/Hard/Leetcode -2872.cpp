class Solution {
public:
    int ans = 0;

    long long dfs(int node, unordered_map<int, vector<int>>& mp,
                  vector<int>& values, vector<int>& vis, vector<long long>& comp) {
        vis[node] = 1;

        long long val = values[node];

        for (auto neigh : mp[node]) {
            if (!vis[neigh])
                val += dfs(neigh, mp, values, vis, comp);
        }

        comp[node] = val;
        return val;
    }

    void dfs2(int node, unordered_map<int, vector<int>>& mp,
              vector<int>& vis, vector<long long>& comp, int k) {
        vis[node] = 1;
        for (auto neigh : mp[node]) {
            if (!vis[neigh]) {
                if (comp[neigh] % k == 0) ans++;
                dfs2(neigh, mp, vis, comp, k);
            }
        }
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {
        unordered_map<int, vector<int>> mp;
        for (auto &e : edges) {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        vector<long long> comp(n, 0);

        dfs(0, mp, values, vis, comp);

        fill(vis.begin(), vis.end(), 0);

        dfs2(0, mp, vis, comp, k);

        return ans + 1;
    }
};