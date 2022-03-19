#include <bits/stdc++.h>

// 020 Snuke Festival
// https://atcoder.jp/contests/abc077/tasks/arc084_a

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
    int n; cin >> n;
    vi a(n), b(n), c(n);
    fore(x, a) cin >> x;
    fore(x, b) cin >> x;
    fore(x, c) cin >> x;
    sort(all(a));
    sort(all(b));
    sort(all(c));

    int ans = 0;
    vi infb(n), infc(n);
    rep(i, n) {
        infb[i] = upper_bound(all(b), a[i]) - begin(b);
        infc[i] = upper_bound(all(c), b[i]) - begin(c);
    }

    // b[i]が選べる最小のbである時のCの通り数
    vi sumb(n + 1, 0);
    rrep(i, n) sumb[i] = sumb[i + 1] + (n - infc[i]);

    // a[i]を一番小さい上部とした時の通り数
    vi suma(n + 1, 0);
    rrep(i, n) suma[i] = suma[i + 1] + sumb[infb[i]];

    ans = suma[0];

    cout << ans << newl;
}