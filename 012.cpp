#include <bits/stdc++.h>

// 012 派閥
// https://atcoder.jp/contests/abc002/tasks/abc002_4

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
    vector<set<int>> tomodati(n);
    rep(_, m)
    {
        int x, y;
        cin >> x >> y;
        tomodati[x - 1].insert(y - 1);
        tomodati[y - 1].insert(x - 1);
    }

    int ans = 0;
    rep(bit, (1 << n))
    {
        vi group;
        rep(i, n) if (bit & (1 << i)) group.push_back(i);

        bool ok = true;

        rep(i, group.size()) rep(j, i + 1, group.size())
        {
            if (!tomodati[group[i]].count(group[j]))
            {
                ok = false;
                break;
            }
        }

        if (ok)
            chmax(ans, group.size());
    }

    cout << ans << newl;
}
