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

struct points {
    int x, y;
};

int n;
points a[N], temp[N];

bool compare(points a, points b) {
    if (a.x != b.x) {
        return a.x < b.x;
    }
    if (a.y != b.y) {
        return a.y > b.y;
    }
}

void merge(int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (compare(a[i], a[j])) temp[k++] = a[i++];
        else temp[k++] = a[j++];
    }


    while (i <= mid) temp[k++] = a[i++];
    while (j <= right) temp[k++] = a[j++];

    for (int p = left; p <= right; p++) a[p] = temp[p];
}

void mergeSort(int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(left, mid);
        mergeSort(mid + 1, right);
        merge(left, mid, right);
    }
}

void solve(void) {
    cin >> n;
    rep(i, 1, n) cin >> a[i].x >> a[i].y;

    mergeSort(1, n);
    rep(i, 1, n) cout << a[i].x << ' ' << a[i].y << endl;
}

signed main()
{
    #define task "Point2D"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(task".inp", "r", stdin);
    freopen(task".out", "w", stdout);

    if (ComGa999ms) {
        int t; cin >> t;
        while (t-- ) solve();
    } else solve();

    return 0;
}
