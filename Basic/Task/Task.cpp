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

int myabs(int x) {
    return (x > 0 ? x : -x);
}

int n, k, p, q;

void solve(void) {
    cin >> n >> k >> p >> q;

    int posAlice = 2 * (p - 1) + q;

    vector <pii> candidates;

    if (posAlice + k <= n) {
        int pos = posAlice + k;
        int u = (pos + 1) / 2;
        int v = (pos % 2 == 0) ? 2 : 1;
        candidates.push_back(pii(u, v));
    }

    if (posAlice - k >= 1) {
        int pos = posAlice - k;
        int u = (pos + 1) / 2;
        int v = (pos % 2 == 0) ? 2 : 1;
        candidates.push_back(pii(u, v));
    }

    if (candidates.empty()) {
        cout << -1 ;
        return;
    }

    pair<int, int> res = candidates[0];
    int min_dist = myabs(res.fi - p);

    for (auto [u, v] : candidates) {
        int dist = myabs(u - p);
        if (minimize(min_dist, dist) || (dist == min_dist && u < res.fi)) res = pii(u, v);
    }

    cout << res.fi << " " << res.se;
}

signed main()
{
    #define task "Task"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    if (ComGa999ms) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
