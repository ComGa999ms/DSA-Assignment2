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

int n;
int a[N], b[N], TruePos[N];

void solve(void) {
    cin >> n;

    vector <int> v;
    rep(i, 1, n) cin >> a[i], v.push_back(a[i]);

    sort(all(v)); _unique(v);
    rep(i, 1, n) a[i] = lower_bound(all(v), a[i]) - v.begin() + 1, b[i] = a[i];

    int res = 0;

    sort(b + 1, b + 1 + n);
    rep(i, 1, n) TruePos[b[i]] = i;
    rep(i, 1, n) b[i] = a[i];

    rep(i, 1, n) {
        while (TruePos[b[i]] != i) {
            ++res;
            swap(b[i], b[TruePos[b[i]]]);
        }
    }

    int ans = 0;
    sort(b + 1, b + 1 + n, greater <int>());
    rep(i, 1, n) TruePos[b[i]] = i;
    rep(i, 1, n) b[i] = a[i];

    rep(i, 1, n) {
        while (TruePos[b[i]] != i) {
            ++ans;
            swap(b[i], b[TruePos[b[i]]]);
        }
    }

    cout << min(res, ans);
}

signed main()
{
    #define task "4Madmen"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    if (ComGa999ms) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
