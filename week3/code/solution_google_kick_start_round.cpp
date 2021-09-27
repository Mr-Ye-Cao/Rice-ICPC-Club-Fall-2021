/****
* Solition Credit to Charlie Liu
* I have yet to comment this code, I will do it tomorrow Sept 27
***/

#include <bits/stdc++.h>

#define MAXN 300005

using namespace std;

typedef long long ll;

struct Fenwick {
    ll a[MAXN + 1] = {0};

    ll query(int x) {
        ll sum = 0;
        for (; x; x -= x & -x) sum += a[x];
        return sum;
    }

    void update(int x, ll v) {
        for (; x <= MAXN; x += x & -x) a[x] += v;
    }
};

struct Ride {
    int h, s, e;

    bool operator<(Ride o) const {
        return h > o.h;
    }
};

void testcase() {
    int d, n, k, h, s, e;
    cin >> d >> n >> k;

    vector<Ride> rides;
    for (int i = 0; i < n; ++i) {
        cin >> h >> s >> e;
        rides.push_back({h, s, e});
    }
    sort(rides.begin(), rides.end());

    vector<int> open[d + 1], close[d + 1];
    for (int i = 0; i < n; ++i) {
        open[rides[i].s].push_back(i);
        close[rides[i].e].push_back(i);
    }

    ll ans = 0ll;
    Fenwick hsum, cont;
    for (int i = 1; i <= d; ++i) {
        for (int x: open[i]) {
            cont.update(x + 1, 1);
            hsum.update(x + 1, rides[x].h);
        }
        int lo = 1, hi = n, mid;
        while (lo + 1 < hi) {
            mid = (lo + hi) >> 1;
            if (cont.query(mid) > k) hi = mid;
            else lo = mid;
        }
        if (cont.query(lo) >= k) ans = max(ans, hsum.query(lo));
        else ans = max(ans, hsum.query(hi));
        for (int x: close[i]) {
            cont.update(x + 1, -1);
            hsum.update(x + 1, -rides[x].h);
        }
    }
    printf("%lld\n", ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d: ", i);
        testcase();
    }
    return 0;
}
