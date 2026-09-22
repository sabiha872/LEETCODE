class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, K;
    vector<Node> seg;

    Node mergeNode(const Node& L, const Node& R) {

        Node res;

        // Whole segment ka product
        res.prod = (L.prod * R.prod) % K;

        // Prefix completely left segment mein
        for (int r = 0; r < K; r++) {
            res.cnt[r] += L.cnt[r];
        }

        // Prefix = complete left + right ka prefix
        for (int r = 0; r < K; r++) {

            int nr = (L.prod * r) % K;

            res.cnt[nr] += R.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r,
               vector<int>& nums) {

        if (l == r) {

            int rem = nums[l] % K;

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] =
            mergeNode(seg[node * 2],
                      seg[node * 2 + 1]);
    }

    void update(int node, int l, int r,
                int idx, int val) {

        if (l == r) {

            int rem = val % K;

            seg[node].prod = rem;

            for (int i = 0; i < K; i++)
                seg[node].cnt[i] = 0;

            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(node * 2, l, mid, idx, val);
        }
        else {
            update(node * 2 + 1, mid + 1, r, idx, val);
        }

        seg[node] =
            mergeNode(seg[node * 2],
                      seg[node * 2 + 1]);
    }

    Node query(int node, int l, int r,
               int ql, int qr) {

        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        if (qr <= mid) {
            return query(node * 2,
                         l, mid,
                         ql, qr);
        }

        if (ql > mid) {
            return query(node * 2 + 1,
                         mid + 1, r,
                         ql, qr);
        }

        Node L = query(node * 2,
                       l, mid,
                       ql, qr);

        Node R = query(node * 2 + 1,
                       mid + 1, r,
                       ql, qr);

        return mergeNode(L, R);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int k,
        vector<vector<int>>& queries) {

        n = nums.size();
        K = k;

        seg.resize(4 * n + 5);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Update
            update(1, 0, n - 1,
                   index, value);

            // Query [start, n-1]
            Node res =
                query(1, 0, n - 1,
                      start, n - 1);

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};