#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i < n; ++i) {
        int minIndex = i;
        for (int j = i + 1; j <= n; ++j) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }
        swap(a[i], a[minIndex]);

        if (i != minIndex)
            for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
    }
}

int main() {
    #define task "SelectionSort"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    solve();
    return 0;
}
