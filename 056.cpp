#include <bits/stdc++.h>

// 056 単一始点最短経路
// https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A

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

struct Edge {
    int to;
    int weight;
};

vector<vector<Edge>> G;
vp ans;

void dijkstra(int r) {
    ans[r].first = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
    que.push(ans[r]);

    while(!que.empty()) {
        pair<int, int> u = que.top();
        que.pop();

        fore(v, G[u.second]) {
            if (chmin(ans[v.to].first, ans[u.second].first + v.weight)) que.push(ans[v.to]);
        }
    }
}

signed main() {
    // グラフの入力
    int v, e, r; cin >> v >> e >> r;
    G = vector<vector<Edge>>(v);
    rep(_, e) {
        int s, t, d; cin >> s >> t >> d;
        Edge add = {t, d};
        G[s].push_back(add);
    }

    // 初期化
    ans = vp(v);
    rep(i, v) ans[i] = make_pair(INT_MAX, i);

    dijkstra(r);

    fore(x, ans) {
        if (x.first == INT_MAX) cout << "INF\n";
        else cout << x.first << newl;
    }
    
}