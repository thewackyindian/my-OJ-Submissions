/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <bits/stdc++.h>
#include <cstdio>
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
  vector<vector<char>> g(n, vector<char>(m));
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      g[i][j] = s[j];
    }
  }
  vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
  dp[n - 1][m - 1] = true;
  for (int i = n - 2; i >= 0; i--) {
    dp[i][m - 1] = dp[i + 1][m - 1] && g[i][m - 1] != '#';
  }
  for (int j = m - 2; j >= 0; j--) {
    dp[n - 1][j] = dp[n - 1][j + 1] && g[n - 1][j] != '#';
  }
  for (int i = n - 2; i >= 0; i--) {
    for (int j = m - 2; j >= 0; j--) {
      dp[i][j] = (dp[i + 1][j] || dp[i][j + 1]) && g[i][j] != '#';
    }
  }
  if (dp[0][0] == false) {
    cout << 0 << endl;
    return;
  }
  int xr = 0, yr = 0, xd = 0, yd = 0;
  int moves = n + m - 3;
  while (moves--) {
    if (dp[xr][yr + 1]) {
      yr++;
    } else {
      xr++;
    }
    if (dp[xd + 1][yd]) {
      xd++;
    } else {
      yd++;
    }
    // printf("%ld,%ld :: %ld,%ld\n", xr,yr,xd,yd);
    if (xr == xd && yd == yr) {
      break;
    }
  }
  cout << (xr == xd && yd == yr ? 1 : 2) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
#ifndef LOCAL
  cin.tie(nullptr);
#endif
  int cases = 1;
  // cin >> cases;
  for (int tc = 1; tc <= cases; tc++) {
    solve();
  }

  return 0;
}