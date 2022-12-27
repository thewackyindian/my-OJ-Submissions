#include <bits/stdc++.h>
using namespace std;

#define int        int64_t
#define endl       '\n'
#define all(x)     x.begin(), x.end()
#define sz(x)      (int)x.size()
#define pp         pair<int,int>

template <typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>istream& operator >> (istream &is, T_container &v) {for(T &x : v) is >> x; return is;}
template <typename A, typename B>ostream &operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')';}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){    os << '{';string sep;for (const T &x : v)os << sep << x, sep = ", ";return os << '}';}
template<class P, class Q = vector<P>, class R = less<P> > ostream& operator << (ostream& out, priority_queue<P, Q, R> const& M){static priority_queue<P, Q, R> U;U = M;out << "{ ";while(!U.empty())out << U.top() << " ", U.pop();return (out << "}");}
template<class P> ostream& operator << (ostream& out, queue<P> const& M){static queue<P> U;U = M;out << "{ ";while(!U.empty())out << U.front() << " ", U.pop();return (out << "}");}
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T){cerr << ' ' << H; dbg_out(T...);}
#ifdef LOCAL
  #define dbg(...) cerr << __func__ << " : " << __LINE__ << " " << "(" << #__VA_ARGS__ << ") : ",dbg_out(__VA_ARGS__);
#else
  #define dbg(...) 2529;
#endif

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >;

const string yes = "YES", no = "NO";

void solve() {
  int n , m;
  cin >> n >> m;
  vector<vector<int>> g(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          cin >> g[i][j];
      }
  }
  auto check = [&](int mid) {
    //gfg
    vector<vector<int>> aux(n, vector<int>(m));
    for (int i = 0; i < m; i++)
      aux[0][i] = (g[0][i] >= mid) ? 1 : 0;

    for (int i = 1; i < n; i++)
      for (int j = 0; j < m; j++)
        aux[i][j] = (g[i][j] >= mid ? 1 : 0) +aux[i - 1][j];

    for (int i = 0; i < n; i++)
      for (int j = 1; j < m; j++)
        aux[i][j] += aux[i][j - 1];
    //gfg
    auto sumQuery = [&]( int tli,int tlj, int rbi, int rbj) {
      int res = aux[rbi][rbj];

      if (tli > 0)
        res = res - aux[tli - 1][rbj];

      if (tlj > 0)
        res = res - aux[rbi][tlj - 1];

      if (tli > 0 && tlj > 0)
        res = res + aux[tli - 1][tlj - 1];

      return res;
    };
    //gfg
    for (int x = 0; x < n; x++) {
      for (int y = 0; y < m; y++) {
        if (x + mid - 1 <= n - 1 && y + mid - 1 <= m - 1) {
          int sum = sumQuery(x, y,x + mid - 1, y + mid - 1);
          // dbg(sum);
          if (sum >= mid*mid)
            return true;
        }
      }
    }
    return false;
  };
  int l = 1, h = min(n, m);
  int ans = 0;
  while(l <= h) {
    int mid = (l + h) / 2;
    if(check(mid)) {
      ans = mid;
      l = mid + 1;
    }
    else{
      h = mid - 1;
    }
  }
  cout <<ans << endl;

}

signed main() {
  ios_base::sync_with_stdio(false);
#ifndef LOCAL
  cin.tie(nullptr);
#endif
  int cases = 1;
  cin >> cases;

  for (int tc = 1; tc <= cases; tc++)
    solve();
  return 0;
}