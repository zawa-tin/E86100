#include <bits/stdc++.h>

// 017 8クイーン問題
// https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/13/ALDS1_13_A

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

int k;
vi alx, aly;
vvi grid(8, vi(8, 0));

bool atack(int x, int y) {
    return grid[y][x] == 2;
}

bool check(int x, int y) {
    grid[y][x] = 0;
    // 縦
    rep(i, 8) {
        if (atack(x, i)) return false;
        else grid[i][x] = 1;
    }

    // 横
    rep(i, 8) {
        if (atack(i, y)) return false;
        else grid[y][i] = 1;
    }

    // 左上
    for (int i = 0 ; x - i >= 0 and y - i >= 0 ; i++) {
        if (atack(x - i, y - i)) return false;
        else grid[y - i][x - i] = 1;
    }

    // 右下
    for (int i = 0 ; x + i < 8 and y + i < 8 ; i++) {
        if (atack(x + i, y + i)) return false;
        else grid[y + i][x + i] = 1;
    }

    // 右上
    for (int i = 0 ; x + i < 8 and y - i >= 0 ; i++) {
        if (atack(x + i, y - i)) return false;
        else grid[y - i][x + i] = 1;
    }

    // 左下
    for (int i = 0 ; x - i >= 0 and y + i < 8 ; i++) {
        if (atack(x - i, y + i)) return false;
        else grid[y + i][x - i] = 1;
    }
    
    grid[y][x] = 2;
    return true;
}

void debug() {
    rep(y, 8) {
        fore(x, grid[y]) cout << (x == 2 ? "Q" : ".");
        cout << newl;
    }
}

signed main() {
    int k; cin >> k;
    aly = alx = vi(k);
    rep(i, k) cin >> aly[i] >> alx[i];
    vvi start_grid(8, vi(8));
    rep(i, k) check(alx[i], aly[i]);
    start_grid = grid;
    vi index(8);
    rep(i, 8) index[i] = i;
    
    // 順列全探索
    do {
        // 既に指定された所か
        rep(i, k) if (index[aly[i]] != alx[i]) continue;
        // checkを行う
        bool ok = true;
        rep(i, 8) if (!check(index[i], i)) {
            ok = false;
            grid = start_grid;
            break;
        }
        if (ok) break;
    } while(next_permutation(all(index)));
    debug();
}