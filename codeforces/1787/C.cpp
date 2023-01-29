/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
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

const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

int dp[N][2];
int a[N];
int n, s;

void solve() {
        cin >> n >> s;
        for(int i = 0; i < n; i++)
                cin >> a[i];
        for(int i = 0; i < n + 1; i++)
                dp[i][0] = dp[i][1] = 0;

        // dp[1][0] = (a[1] < s) ? 0 : a[0] * s;
        // dp[1][1] = (a[1] < s) ? a[1] * a[0] : (a[1] - s) * a[0];
        int ans = inf;
        for(int i = 1; i < n; i++) {
                if(i == 1){
                        if(a[i] < s) {
                                dp[i][0] = 0;
                                dp[i][1] = a[i] * a[i - 1];
                        }
                        else {
                                dp[i][0] = a[i - 1] *s;
                                dp[i][1] = (a[i] - s) * (a[i - 1]);
                        }
                        continue;
                }
                if(i == n - 1) {
                        if(a[i - 1] < s) {
                                int v = a[i - 1] * a[i];
                                dp[i][0] = dp[i - 1][0] + v;
                                dp[i][1] = dp[i - 1][1];
                        }
                        else {
                                int v = a[i] * s, v_ = a[i] * (a[i - 1] - s);
                                dp[i][0] = dp[i - 1][0] + v_;
                                dp[i][1] = dp[i - 1][1] + v;
                        }
                        continue;
                }
                if(a[i] < s) {
                        if(a[i - 1] < s) {
                                int v = a[i - 1] * a[i];
                                dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
                                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + v);
                        }
                        else {
                                int v = a[i] * s, v_ = a[i] * (a[i - 1] - s);
                                dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]);
                                dp[i][1] = min(dp[i - 1][1] + v, dp[i - 1][0] + v_);
                        }
                }
                else {
                        if(a[i - 1] < s) {
                                int v = a[i - 1] * s, v_ = a[i - 1] * (a[i] - s);
                                dp[i][0] = min(dp[i - 1][1], dp[i - 1][0] + v);
                                dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + v_);
                        }
                        else {
                                int v = a[i] - s, v_ = a[i - 1] - s;
                                dp[i][0] = min(dp[i - 1][1] + (s * s), dp[i - 1][0] + (v_ * s));
                                dp[i][1] = min(dp[i - 1][1] + (s * v), dp[i - 1][0] + (v * v_));
                        }
                }
        }
        // for(int i = n - 1; i < n; i++)
        //         dbg(dp[i][0], dp[i][1]);

        cout << min(dp[n - 1][1], dp[n - 1][0]) << endl;
        // if(a[n - 2] )

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