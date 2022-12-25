#include <bits/stdc++.h>
#include <vector>
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
const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

template<typename T_vector>
void output_vector(const T_vector &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

void solve() {
  int n;
  cin >> n;
  map<pp,set<int>>c;
  vector<int>cc(n + 1, 0);
  for(int i = 0; i < n - 2; i++) {
    int x, y , z;
    cin >> x >> y >> z;
    pp xy = {min(x, y), max(x, y)};
    pp yz = {min(z, y), max(z, y)};
    pp xz = {min(x, z), max(x, z)};
    c[xy].insert(z);
    c[yz].insert(x);
    c[xz].insert(y);
    cc[x]++;
    cc[y]++;
    cc[z]++;
  }
  vector<int>one , two;
  for(int i = 1;i <= n; i++) {
    if(cc[i] == 1)
      one.push_back(i);
    else if(cc[i] == 2)
      two.push_back(i);
  }
  // dbg(c)
  vector<int>ans;
  ans.push_back(one[0]);
  if(c.find({min(one[0],two[0]),max(one[0], two[0])}) != c.end()) {
      ans.push_back(two[0]);
      int l = one[0], r = two[0];
      for(int i = 2; i < n - 2; i++) {

        pp f = {min(l, r), max(l, r)};
        auto t = *c[f].begin();
        pp s = {min(r, t), max(r, t)};

        c[s].erase(l);
        c[f].erase(t);

        l = r;
        r = t;

        ans.push_back(t);
      }
      ans.push_back(two[1]);
      ans.push_back(one[1]);

  }
  else {
    ans.push_back(two[1]);
      int l = one[0], r = two[1];
      for(int i = 2; i < n - 2; i++) {

        pp f = {min(l, r), max(l, r)};
        auto t = *c[f].begin();
        pp s = {min(r, t), max(r, t)};

        c[s].erase(l);
        c[f].erase(t);

        l = r;
        r = t;

        ans.push_back(t);
      }
      ans.push_back(two[0]);
      ans.push_back(one[1]);

  }


  output_vector(ans);


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