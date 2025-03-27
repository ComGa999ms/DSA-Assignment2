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

const int base = 337;
const int N = 1e6 + 5;
const int M = 2e3 + 5;
const int mod = 1e9 + 7;
const int inf = 1e18 + 7;
const bool ComGa999ms = false;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l, int r) {
    return l + rng() % (r - l + 1);
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

int HashT = 0;
int gt[N], HashS[N];
string s, t;

bool check(int l, int r) {
    if (r < sz(s)) {
        return ((HashS[r] - HashS[l - 1] * gt[r - l + 1] % mod + mod) % mod) == HashT;
    }
    return 0;
}

void solve(void) {
    cin >> s >> t;

    s = "+" + s;
    t = "+" + t;

    gt[0] = 1;
    rep(i, 1, N - 5) gt[i] = (gt[i - 1] * base) % mod;

    rep(i, 1, sz(t) - 1) {
        HashT = (HashT * base + (t[i] - 'a' + 1)) % mod;
    }

    rep(i, 1, sz(s) - 1) {
        HashS[i] = (HashS[i - 1] * base + (s[i] - 'a' + 1)) % mod;
    }

    vector <int> res;
    rep(i, 1, sz(s) - 1) {
        if (check(i, i + sz(t) - 2)) res.push_back(i);
    }

    if (res.size()) {
        cout << "YES" << endl;
        for (auto T : res) cout << T << ' ';
    } else cout << "NO";
}

signed main() {
    #define task "khangtd.DetectVirus"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    if (ComGa999ms) {
        int t; cin >> t;
        while (t--) solve();
    } else {
        solve();
    }

    return 0;
}
