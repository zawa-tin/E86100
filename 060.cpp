#include <bits/stdc++.h>

// 060 All Pairs Shortest Path
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C

// clang-format off

using namespace std;
#define all(a) a.begin(), a.end()
#define int long long
#define over_load_(_1, _2, _3, _4, NAME, ...) NAME
#define rep(...) over_load_(__VA_ARGS__, rep4, rep3, rep2)(__VA_ARGS__)
#define rep2(i, r) for (int i = 0; i < static_cast<int>(r); (i) += 1)
#define rep3(i, l, r) for (int i = static_cast<int>(l); i < static_cast<int>(r); (i) += 1)
#define rep4(i, l, r, stride) for (int i = static_cast<int>(l); i < static_cast<int>(r); (i) += (stride))
#define rrep(...) over_load_(__VA_ARGS__, rrep4, rrep3, rrep2)(__VA_ARGS__)
#define rrep2(i, r) for (int i = static_cast<int>(r) - 1; i >= 0; (i) -= 1)
#define rrep3(i, l, r) for (int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= 1)
#define rrep4(i, l, r, stride) for (int i = static_cast<int>(r) - 1; i >= static_cast<int>(l); (i) -= (stride))
#define fore(i, a) for (auto &i : a)
template <typename T1, typename T2>
inline bool chmax(T1 &a, T2 b)
{
    return a < b && (a = b, true);
}
template <typename T1, typename T2>
inline bool chmin(T1 &a, T2 b)
{
    return a > b and (a = b, true);
}
constexpr char newl = '\n';

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vp = vector<pair<int, int>>;
using vs = vector<string>;

const ll sup = LONG_LONG_MAX / 2;

vvi G;

void wf(int n) {
    rep(k, n) rep(i, n) rep(j, n) G[i][j] = min(G[i][j], G[i][k] + G[k][j]);
}

signed main() {
    int n, e; cin >> n >> e;
    G = vvi(n, vi(n, sup));
    rep(_, e) {
        int s, t, d; cin >> s >> t >> d;
        G[s][t] = d;
    }
    rep(i, n) G[i][i] = 0;

    wf(n);

    rep(i, n) if (G[i][i] < 0) {
        cout << "NEGATIVE CYCLE\n";
        return 0;
    }

    fore(y, G) {
        rep(i, n) {
            if (y[i] > sup / 2) cout << "INF";
            else cout << y[i];

            if (i != n - 1) cout << " ";
        }
        cout << newl;
    }

}