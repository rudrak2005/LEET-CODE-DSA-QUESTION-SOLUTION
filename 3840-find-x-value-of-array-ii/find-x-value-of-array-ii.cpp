class Solution {
public:
    struct Node {
        int prod = 1;
        int cnt[5] = {};
    };

    int k;
    vector<Node> tree;

    Node mergeNode(const Node& left, const Node& right) {
        Node res;

        // Product of the complete segment
        res.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] = left.cnt[r];
        }

        // Prefixes that use the whole left segment
        // and a prefix of the right segment
        for (int r = 0; r < k; r++) {
            int newRem = (left.prod * r) % k;
            res.cnt[newRem] += right.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            int rem = nums[l] % k;

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int l, int r, int idx, int value) {

        if (l == r) {
            int rem = value % k;

            tree[node] = Node();

            tree[node].prod = rem;
            tree[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, value);
        } else {
            update(node * 2 + 1, mid + 1, r, idx, value);
        }

        tree[node] = mergeNode(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {

        // Completely outside
        if (qr < l || r < ql) {
            return Node();
        }

        // Completely inside
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        Node left = query(node * 2, l, mid, ql, qr);

        Node right = query(node * 2 + 1, mid + 1, r, ql, qr);

        return mergeNode(left, right);
    }

    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {

        this->k = k;

        int n = nums.size();

        tree.resize(4 * n);

        for (int& num : nums) {
            num %= k;
        }

        build(1, 0, n - 1, nums);

        vector<int> ans;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(1, 0, n - 1, index, value);

            // Query [start ... n-1]
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};