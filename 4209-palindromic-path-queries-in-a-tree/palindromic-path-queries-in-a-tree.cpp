

class Solution {
    struct Node {
        int mask = 0;
        int lazy = 0;
    };

    int n;
    vector<vector<int>> adj;
    vector<int> depth, head, parent, heavy, pos;
    vector<Node> tree;
    int timer = 0;

    int dfs_size(int u, int p) {
        int size = 1;
        int max_sub = 0;
        heavy[u] = -1;
        for (int v : adj[u]) {
            if (v != p) {
                int sub = dfs_size(v, u);
                size += sub;
                if (sub > max_sub) {
                    max_sub = sub;
                    heavy[u] = v;
                }
            }
        }
        return size;
    }

    void dfs_hld(int u, int p, int d, int h) {
        depth[u] = d;
        parent[u] = p;
        head[u] = h;
        pos[u] = ++timer;
        if (heavy[u] != -1) {
            dfs_hld(heavy[u], u, d + 1, h);
        }
        for (int v : adj[u]) {
            if (v != p && v != heavy[u]) {
                dfs_hld(v, u, d + 1, v);
            }
        }
    }

    void push(int node) {
        if (tree[node].lazy != 0) {
            int m = tree[node].lazy;
            tree[2 * node].mask ^= m;
            tree[2 * node].lazy ^= m;
            tree[2 * node + 1].mask ^= m;
            tree[2 * node + 1].lazy ^= m;
            tree[node].lazy = 0;
        }
    }

    void update_point(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node].mask = val;
            return;
        }
        push(node);
        int mid = (start + end) / 2;
        if (idx <= mid) update_point(2 * node, start, mid, idx, val);
        else update_point(2 * node + 1, mid + 1, end, idx, val);
        tree[node].mask = tree[2 * node].mask ^ tree[2 * node + 1].mask;
    }

    int query_range(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return tree[node].mask;
        push(node);
        int mid = (start + end) / 2;
        return query_range(2 * node, start, mid, l, r) ^ query_range(2 * node + 1, mid + 1, end, l, r);
    }

public:
    vector<bool> palindromePath(int n_nodes, vector<vector<int>>& edges, string s, vector<string>& queries) {
        n = n_nodes;
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        depth.assign(n, 0);
        parent.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        timer = 0;

        dfs_size(0, -1);
        dfs_hld(0, -1, 0, 0);

        tree.assign(4 * n + 1, Node());
        
        vector<int> initial_masks(n + 1);
        for (int i = 0; i < n; ++i) {
            initial_masks[pos[i]] = (1 << (s[i] - 'a'));
        }

        auto build_arr = [&](auto& self, int node, int start, int end) -> void {
            if (start == end) {
                tree[node].mask = initial_masks[start];
                return;
            }
            int mid = (start + end) / 2;
            self(self, 2 * node, start, mid);
            self(self, 2 * node + 1, mid + 1, end);
            tree[node].mask = tree[2 * node].mask ^ tree[2 * node + 1].mask;
        };
        build_arr(build_arr, 1, 1, n);

        auto path_query = [&](int u, int v) {
            int res = 0;
            while (head[u] != head[v]) {
                if (depth[head[u]] > depth[head[v]]) swap(u, v);
                res ^= query_range(1, 1, n, pos[head[v]], pos[v]);
                v = parent[head[v]];
            }
            if (depth[u] > depth[v]) swap(u, v);
            res ^= query_range(1, 1, n, pos[u], pos[v]);
            return res;
        };

        vector<bool> answer;
        for (const auto& q : queries) {
            if (q[0] == 'u') {
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();
                int new_mask = (1 << (c - 'a'));
                s[u] = c;
                update_point(1, 1, n, pos[u], new_mask);
            } else {
                int space1 = q.find(' ', 6);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));
                int mask = path_query(u, v);
                if ((mask & (mask - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }

        return answer;
    }
};