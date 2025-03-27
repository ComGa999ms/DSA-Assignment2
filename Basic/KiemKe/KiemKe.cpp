#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 5;
int n;
string a[N], temp[N];

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

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    todo(1, n);

    int cnt = 1;
    for (int i = 1; i < n; ++i) {
        if (a[i] != a[i + 1]) ++cnt;
    }
    cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("KiemKe.inp", "r", stdin);
    freopen("KiemKe.out", "w", stdout);

    solve();
    return 0;
}
