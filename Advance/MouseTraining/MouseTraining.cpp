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

const int N = 2e6 + 5;
const int M = 2e3 + 5;
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

int T, MOD;
int gt[N];

vector<int> getRepresentation(int N) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % MOD);
        N /= MOD;
    }
    return res;
}


int power(int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1) res = (res * a) % MOD;
        a = (a * a) % MOD;
        n >>= 1;
    }
    return res;
}

int C(int n, int k) {
    if (k > n || k < 0) return 0;
    return (((gt[n] * power(gt[n - k], MOD - 2)) % MOD) * power(gt[k], MOD - 2)) % MOD;
}

void solve(void) {
    cin >> T >> MOD;

    gt[0] = 1;
    rep(i, 1, N - 5) gt[i] = (gt[i - 1] * i) % MOD;

    while (T-- ) {
        int x; cin >> x;
        // C(2n - 1, n)

        int res = 1;
        vector <int> ni = getRepresentation(2 * x - 1);
        vector <int> ki = getRepresentation(x);

        rep(i, 0, sz(ki) - 1) res = (res * C(ni[i], ki[i])) % MOD;
        cout << res << endl;
    }
}

signed main()
{
    #define task "MouseTraining"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    if (ComGa999ms) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
