#include <bits/stdc++.h>

// 006 Lucky PIN
// https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_d

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

// 000 ~ 999を探索する

char itoc(int i)
{
    return i + '0';
}

signed main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(i, 10) rep(j, 10) rep(k, 10)
    {
        int iter = 0;
        char a = itoc(i);
        char b = itoc(j);
        char c = itoc(k);
        for (; iter < n; iter++)
            if (s[iter] == a)
                break;
        iter++;
        for (; iter < n; iter++)
            if (s[iter] == b)
                break;
        iter++;
        for (; iter < n; iter++)
            if (s[iter] == c)
                break;
        if (iter < n)
            ans++;
    }
    cout << ans << newl;
}