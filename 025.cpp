#include <bits/stdc++.h>

// 029 島はいくつある?
// https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Prelim/1160?year=2009

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


int w, h;
vvi grid;
vvi used;

int cnt = 0;

void dfs(int x, int y) {
    // cout << w << " " << h << newl;
    assert(x >= 0 and x < w and y >= 0 and y < h);
    if (used[y][x] == 1) return;
    used[y][x] = 1;
    // 上
    if (y > 0) if (grid[y - 1][x] == 1) dfs(x, y - 1);
    // 右上
    if (x < w - 1 and y > 0) if (grid[y - 1][x + 1] == 1) dfs(x + 1, y - 1);
    // 右
    if (x < w - 1) if (grid[y][x + 1] == 1) dfs(x + 1, y);
    // 右下
    if (x < w - 1 and y < h - 1) if (grid[y + 1][x + 1] == 1) dfs(x + 1, y + 1);
    // 下
    if (y < h - 1) if (grid[y + 1][x] == 1) dfs(x, y + 1);
    // 左下
    if (x > 0 and y < h - 1) if (grid[y + 1][x - 1] == 1) dfs(x - 1, y + 1);
    // 左
    if (x > 0) if (grid[y][x - 1] == 1) dfs(x - 1, y);
    // 左上
    if (x > 0 and y > 0) if (grid[y - 1][x - 1] == 1) dfs(x - 1, y - 1);
}

signed main() {
    while(1) {
        cin >> w >> h;
        if (w == 0 and h == 0) return 0;
        used.resize(0);
        rep(y, h) {
            vi tmp;
            rep(x, w) tmp.push_back(0);
            used.push_back(tmp);
        }
        grid.resize(0);
        rep(y, h) {
            vi tmp;
            rep(x, w) {
                int val; cin >> val;
                tmp.push_back(val);
            }
            grid.push_back(tmp);
        }
        int ans = 0;
        rep(x, w) rep(y, h) if (used[y][x] == 0 and grid[y][x] == 1) {
            ans++;
            // cout << x << "a" << y << newl;
            dfs(x, y);
        }
        cout << ans << newl;
        // cout << newl;
    }
}