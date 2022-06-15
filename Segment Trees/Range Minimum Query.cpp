https://www.spoj.com/problems/RMQSQ/
#include <bits/stdc++.h>
using namespace std;

#define um unordered_map
#define endl '\n'

inline void cp() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int arr[100001], st[400004];

void build(int i, int l, int r) {
    if (l == r) {
        st[i] = arr[l];
        return;
    }

    int mid = (l + r) / 2;
    build(2 * i, l, mid);
    build(2 * i + 1, mid + 1, r);
    st[i] = min(st[2 * i], st[2 * i + 1]);  // Change
}

int query(int i, int l, int r, int ql, int qr) {
    if (l > qr or r < ql)
        return INT_MAX;  // Change

    if (ql <= l and r <= qr)
        return st[i];

    int mid = (l + r) / 2;

    // change
    return min(query(2 * i, l, mid, ql, qr), query(2 * i + 1, mid + 1, r, ql, qr));
}

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];

    build(1, 1, n);
    int q;
    cin >> q;
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << query(1, 1, n, l + 1, r + 1) << endl;
    }
}

signed main() {
    cp();
    solve();
    return 0;
}
