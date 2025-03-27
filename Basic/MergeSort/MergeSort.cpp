#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N], temp[N];

void merge(int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;

    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }
    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (i = left; i <= right; ++i) a[i] = temp[i];

    for (int p = 1; p <= n; ++p) {
        if (p > 1) cout << " ";
        if (p == left) cout << "[ ";
        cout << a[p];
        if (p == right) cout << " ]";
    }
    cout << '\n';
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = (left + right) >> 1;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    mergeSort(1, n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen("MergeSort.inp", "r", stdin);
    freopen("MergeSort.out", "w", stdout);

    solve();
    return 0;
}
