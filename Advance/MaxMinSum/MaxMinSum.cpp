#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define int long long
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define repd(i, r, l) for (int i = r; i >= l; --i)
#define _unique(x) (x).resize(unique((x).begin(), (x).end()) - (x).begin());
#define sz(v) (int)(v).size()
#define fi first
#define se second
#define pii pair<int,int>
#define p2i pair<int,pii>
#define endl '\n'

using namespace std;

const int N = 1e6 + 5;
const int M = 2e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18 + 7;
const bool ComGa999ms = false;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return l+rng()%(r-l+1);
}

int maximize(int &a, int b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

int minimize(int &a, int b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}

int n, k;
int a[N], gt[N], inv[N];

int power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int get_inv(int x) {
    return power(x, mod - 2);
}

void prepare(int n) {
    gt[0] = 1;
    rep(i, 1, n) gt[i] = (gt[i - 1] * i) % mod;

    inv[n] = get_inv(gt[n]);
    repd(i, n - 1, 0) inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return (gt[n] * inv[k] % mod * inv[n - k]) % mod;
}

void solve(void) {
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];

    sort(a + 1, a + 1 + n);

    int res = 0;
    rep(i, 1, n) {
        int l = i - 1, r = n - i;

        if (l >= k - 1) {
            res = (res + a[i] * C(l, k - 1)) % mod;
        }

        if (r >= k - 1) {
            res = (res - a[i] * C(r, k - 1)) % mod;
        }
    }

    cout << res;
}

signed main()
{
    #define task "MaxMinSum"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    prepare(N - 5);
    if (ComGa999ms) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
