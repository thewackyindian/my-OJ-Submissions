/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
#define pp pair<int, int>

template <class T> using min_heap = priority_queue<T, vector<T>, greater<T>>;

const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> g(n + 1);
  vector<int> deg(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
    deg[u]++, deg[v]++;
  }

  for (int i = 1; i <= m; i++) {
    int x = i, l = m - i;
    if (l % x != 0)
      continue;
    int y = l / x;

    bool inner = false;
    for (int u = 1; u <= n; u++) {
      if (deg[u] != x)
        continue;
      inner = true;
      bool outer = true;
      for (auto &v : g[u]) {
        if (deg[v] != y + 1)
          outer = false;
      }

      if (outer && inner) {
        cout << x << " " << y << endl;
        return;
      }
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(false);
#ifndef LOCAL
  cin.tie(nullptr);
#endif
  int cases = 1;
  cin >> cases;
  for (int tc = 1; tc <= cases; tc++) {
    solve();
  }

  return 0;
}