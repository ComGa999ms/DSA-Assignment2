#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

int n, k;
int a[N], temp[N];
vector <pair<int, int>> ds;

void combie(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (i = left; i <= right; ++i) a[i] = temp[i];
}

void todo(int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        todo(left, mid);
        todo(mid + 1, right);
        combie(left, mid, right);
    }
}

void build_unique(void) {
    if (n == 0) return;
    int col = a[1];
    int cnt = 1;
    for (int i = 2; i <= n; ++i) {
        if (a[i] == col) {
            ++cnt;
        } else {
            ds.push_back(make_pair(col, cnt));
            col = a[i];
            cnt = 1;
        }
    }
    ds.push_back(make_pair(col, cnt));
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    todo(1, n);
    build_unique();

    for (auto &[ai, bi] : ds) {
        if (k > 0 && bi > 0) {
            cout << ai << ' ';
            --k; --bi;
        }
    }

    for (auto &[ai, bi] : ds) {
        while (k > 0 && bi > 0) {
            cout << ai << ' ';
            --k; --bi;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("VQ44_FLOWERS.inp", "r", stdin);
    freopen("VQ44_FLOWERS.out", "w", stdout);

    solve();
    return 0;
}
