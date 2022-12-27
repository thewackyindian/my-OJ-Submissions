#include <bits/stdc++.h>
#include <cstdlib>
#include <cstring>
#include <unordered_map>
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
const int mod = 1e9 + 7, inf = 1e18L + 5, N = 3e4 + 5;
const string yes = "YES", no = "NO";
// struct custom_hash {
//     static uint64_t splitmix64(uint64_t x) {
//         // http://xorshift.di.unimi.it/splitmix64.c
//         x += 0x9e3779b97f4a7c15;
//         x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
//         x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
//         return x ^ (x >> 31);
//     }

//     size_t operator()(uint64_t x) const {
//         static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
//         return splitmix64(x + FIXED_RANDOM);
//     }
// };
// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };
int n, d;
int C[N];
int lim = 0;
int *dp[N];

int recur(int i,int j) {
  if(i > lim)
    return 0;

  if(dp[i][j - d + 250] != -1)
    return dp[i][j - d + 250];

  int zero = (j - 1 > 0) ? C[i] + recur(i + (j - 1), (j - 1)) : C[i];
  int one = C[i] + recur(i + (j), j);
  int two = C[i] + recur(i + (j + 1), j + 1);

  return dp[i][j - d + 250] = max({zero, one, two});
}

void solve() {
  cin >> n >> d;
  for(int i = 0; i < N; i++) {
    C[i] = 0;
    dp[i] = (int *)malloc((501) * sizeof(int));
  }
  for(int i = 0; i < n; i++) {
    int x; cin >> x;
    C[x]++;
    lim = max(lim, x);
  }

  for(int i = 0; i < N; i++)
    for(int j = 0; j <= 500; j++)
      dp[i][j] = -1;

  cout << recur(d, d) << endl;
}

signed main() {
  ios_base::sync_with_stdio(false);
#ifndef LOCAL
  cin.tie(nullptr);
#endif
  int cases = 1;
  // cin >> cases;

  for (int tc = 1; tc <= cases; tc++)
    solve();
  return 0;
}