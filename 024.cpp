#include <bits/stdc++.h>

// 024 深さ優先探索
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/11/ALDS1_11_B

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

struct time {
    int d;
    int f;
};

vvi G;
vector<struct time> stamp;

int now = 0;

void dfs(int v) {
    if (stamp[v].d == 0) {
        stamp[v].d = ++now;
        fore(x, G[v]) dfs(x);
        stamp[v].f = ++now;
    }
    return;
}

signed main() {
    // 入力
    int n; cin >> n;
    G.resize(n);
    stamp.resize(n);
    rep(i, n) {
        int v, k; cin >> v >> k;
        rep(j, k) {
            int to; cin >> to;
            G[v - 1].push_back(to - 1);
        }
    }

    fore(x, stamp) x.d = x.f = 0;

    rep(i, n) dfs(i);

    rep(i, n) cout << i + 1 << " " << stamp[i].d << " " << stamp[i].f << newl;
    
}
