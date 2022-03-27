#include <bits/stdc++.h>

// 026 Ki
// https://atcoder.jp/contests/abc138/tasks/abc138_d

// after-contestはまだ通って無いです

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

vvi G;
vi score;

vi ans;

void dfs(int v, int sum) {
    sum += score[v];
    ans[v] = sum;
    fore(x, G[v]) dfs(x, sum);
}

signed main() {
    int n, q; cin >> n >> q;
    G = vvi(n);
    score = vi(n, 0);
    rep(_, n - 1) {
        int a, b; cin >> a >> b;
        G[a - 1].push_back(b - 1);
    }
    
    rep(_, q) {
        int p, x; cin >> p >> x;
        score[p - 1] += x;
    }

    ans = vi(n, 0);

    dfs(0, 0);

    fore(x, ans) cout << x << " ";
    cout << newl;
}