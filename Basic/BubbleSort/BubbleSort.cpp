#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
int n, a[N];

void solve(void) {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    for (int i = 1; i < n; ++i) {
        bool swaped = 0;
        for (int j = 1; j <= n - i; ++j) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                for (int k = 1; k <= n; ++k) cout << a[k] << ' '; cout << '\n';
                swaped = 1;
            }
        }
        if (!swaped) break;
    }
}

int main() {
    #define task "BubbleSort"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    solve();
    return 0;
}
