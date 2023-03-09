/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n), b(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
  }
  multiset<int> bb(b.begin(), b.end());

  auto pair_sort = [&](vector<int> &x, vector<int> &y) {
    vector<pair<int, int>> xy;
    for (int i = 0; i < x.size(); i++)
      xy.push_back({x[i], y[i]});

    sort(xy.begin(), xy.end());

    for (int i = 0; i < x.size(); i++) {
      x[i] = xy[i].first, y[i] = xy[i].second;
    }
  };

  pair_sort(a, b);

  int ans = INT_MAX, running_max = -1e9;


  for (int i = n - 1; i >= 0; i--) {
    int d = abs(a[i] - running_max);
    bb.erase(bb.find(b[i]));
    auto it = bb.upper_bound(a[i]);

    if (it != bb.end()) {
      d = min(d, abs(a[i] - max(running_max, *it)));
    }
    if (it != bb.begin()) {
      it--;
      d = min(d, abs(a[i] - max(running_max, *it)));
    }

    ans = min(ans, d);
    running_max = max(running_max, b[i]);
  }
  cout << ans << '\n';
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