/****
* Solition Credit to Charlie Liu
* Commented by Peter Cao based on Charlie's explanation
***/

#include <bits/stdc++.h>

#define MAXN 300005

using namespace std;

typedef long long ll;

/**
 * Use a struct (similar to concept of object) 
 * to represent the Fenwick Tree, thus
 * making the code more compact
 **/
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

/**
 * Use a struct (similar to concept of object) 
 * to group together the rides and 
 * store input data making the code 
 * more compact
 **/
struct Ride {
    int h, s, e;

    /** 
     * define the comparison operation
     * here this operator definition will be
     * used later in sort() to give the sort function
     * an idea what's the criteria for sorting.
     * In this case, we are sorting based on the h(happiness) magnitude
    **/ 
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

    // the operator<(Ride o) function is used here for sorting
    sort(rides.begin(), rides.end());

    // array of vectors to store the opening and closing date
    vector<int> open[d + 1], close[d + 1];
    for (int i = 0; i < n; ++i) {
        // loop over the n festivals and put the date when it opens into open[date]
        // and the date when it closes into close[date]
        open[rides[i].s].push_back(i);
        close[rides[i].e].push_back(i);
    }

    // this answer is the initial dummy minimum happiness, which will be updated in next loop
    ll ans = 0ll;

    // use two fenwick trees
    // cont: finding out the number of festivals on day i
    // hsum: finding out the number of maximum happiness on day i
    Fenwick hsum, cont;
    for (int i = 1; i <= d; ++i) {
        /** 
         * notice that binary indexed tree has the property to propogate the update at 
         * one point to all of its parents. i.e. update on index 1 will propogate to 10,
         * 100, 1000 and so on. This is the key reason for using BIT here because once
         * the festival starts, we know as a fact that it will last until the day when
         * it ends. Therefore, we would want to propogate the change starting at the 
         * start day all the way until the ending day.
        */

        // loop over every day and try to update the maximum happiness (ans) in each loop
        for (int x: open[i]) {
            /**
             *  Notice that the update here will propogate the change 
             *  all the way from starting date to all of its parents (later days)
             * */

            // for all festivals starting today
                // cont will record that festival of happiness rank (x+1) happens (mark as +1)
            cont.update(x + 1, 1);
                // hsum will record that festival of happiness rank (x+1) will accumulate (+rides[x].h)
            hsum.update(x + 1, rides[x].h);
        }
        // this binary search finds the number of festivals we will be taking on day i
        // the active search region will between 1 and n, i.e. we will either take one festival
        // or we can take all n festivals
        int lo = 1, hi = n, mid;
        while (lo + 1 < hi) {
            mid = (lo + hi) >> 1;
            // if there are more than k festivals on this day
            // we will be update the upperbound search region to (lo+hi)/2
            if (cont.query(mid) > k) hi = mid;
            // otherwise we will be update the lowerbound search region to (lo+hi)/2
            else lo = mid;
        }
        // After the while loop we can be sure that lo it's safe to take lo number of festivals
        if (cont.query(lo) >= k) ans = max(ans, hsum.query(lo));

        // At the same time if there are less than k festivals simply take all events today
        else ans = max(ans, hsum.query(hi));
        for (int x: close[i]) {
            /**
             *  Notice that the update here will ends the propogation of start date
             *  since the festival at this point will be ending
             * */
            // for all festivals ending today
                // cont will record that festival of happiness rank (x+1) ends (mark as -1)
            cont.update(x + 1, -1);
                // hsum will record that festival of happiness rank (x+1) reverse accumulate (-rides[x].h)
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
