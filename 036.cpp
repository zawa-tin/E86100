#include <bits/stdc++.h>

// 036 ナップザック問題
// https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/1/DPL_1_C

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

signed main() {
    int n, w; cin >> n >> w;
    vi val(n), wei(n);
    rep(i, n) cin >> val[i] >> wei[i];
    // 価値の最大
    vvi dp(n + 1, vi(w + 1, -1));
    dp[0][0] = 0;
    rep(y, 1, n + 1) rep(x, w + 1) {
        dp[y][x] = dp[y - 1][x];
        if (x >= wei[y - 1]) chmax(dp[y][x], dp[y][x - wei[y - 1]] + val[y - 1]);
    }
    int ans = -1;
    rep(i, w + 1) chmax(ans, dp[n][i]);
    cout << ans << newl;
}