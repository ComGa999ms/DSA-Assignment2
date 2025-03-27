#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;

int n, d;
int a[N], cnt[N];

int get(int x) {
    int total = 0;
    for (int i = 0; i <= 200; ++i) {
        total += cnt[i];
        if (total >= x) return i;
    }
    return -1;
}

void solve(void) {
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];

    int res = 0;

    for (int i = 1; i <= d; ++i) cnt[a[i]]++;
    for (int i = d + 1; i <= n; ++i) {
        if (d & 1) {
            int median = get(d / 2 + 1);
            if (a[i] >= 2 * median) res++;
        } else {
            int m1 = get(d / 2);
            int m2 = get(d / 2 + 1);
            if (a[i] >= (m1 + m2)) res++;
        }

        cnt[a[i - d]]--;
        cnt[a[i]]++;
    }
    cout << res;
}

int main()
{
    freopen("PICKLEBALL.inp", "r", stdin);
    freopen("PICKLEBALL.out", "w", stdout);

    solve();
    return 0;
}
