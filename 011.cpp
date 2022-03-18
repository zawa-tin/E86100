#include <bits/stdc++.h>

// 011 Swithces
// https://atcoder.jp/contests/abc128/tasks/abc128_c

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

signed main()
{
    int n, m;
    cin >> n >> m;
    vvi s(m);
    rep(i, m)
    {
        int k;
        cin >> k;
        rep(j, k)
        {
            int tmp;
            cin >> tmp;
            s[i].push_back(tmp);
        }
    }

    vi p(m);
    fore(x, p) cin >> x;

    int ans = 0;

    for (int bit = 0; bit < (1 << n); bit++)
    {
        // スイッチのオンオフ
        vi on(n, 0);
        rep(i, n) if (bit & (1 << i)) on[i] = 1;
        // それぞれの個数
        vi numon(m, 0);
        rep(i, m) fore(x, s[i]) if (on[x - 1]) numon[i]++;
        // 電気がつくか
        vi light(m, 0);
        rep(i, m) if (numon[i] % 2 == p[i]) light[i] = 1;
        // 数える
        int count = 0;
        fore(x, light) if (x) count++;

        if (count == m)
            ans++;
    }
    cout << ans << newl;
}