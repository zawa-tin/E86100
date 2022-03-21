#include <bits/stdc++.h>

// 029 幅優先探索
// https://atcoder.jp/contests/abc007/tasks/abc007_3

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

vector<string> grid;
int r, c;

void search(int y, int x, int oy, int ox, queue<pair<int, int>>& que, vvi& dist) {
    if (dist[oy][ox] != 0) return;
    dist[oy][ox] = dist[y][x] + 1;
    que.push(make_pair(oy, ox));
}

int bfs(int sy, int sx, int gy, int gx) {
    vvi dist(r, vi(c));
    fore(y, dist) fore(x, y) x = 0;
    queue<pair<int, int>> que;
    que.push(make_pair(sy, sx));
    while(!que.empty()) {
        int y = que.front().first;
        int x = que.front().second;
        que.pop();
        if (y > 0 and grid[y - 1][x] == '.') search(y, x, y - 1, x, que, dist);
        if (x > 0 and grid[y][x - 1] == '.') search(y, x, y, x - 1, que, dist);
        if (y < r - 1 and grid[y + 1][x] == '.') search(y, x, y + 1, x, que, dist);
        if (x < c - 1 and grid[y][x + 1] == '.') search(y, x, y, x + 1, que, dist);
    }
    return dist[gy][gx];
}

signed main() {
    cin >> r >> c;
    int sy, sx; cin >> sy >> sx;
    int gy, gx; cin >> gy >> gx;
    grid.resize(r);
    fore(y, grid) cin >> y;
    cout << bfs(sy - 1, sx - 1, gy - 1, gx - 1) << newl;
}