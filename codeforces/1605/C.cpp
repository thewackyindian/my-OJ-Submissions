#include "bits/stdc++.h"
using namespace std;

#define int int64_t
#define endl '\n'
#define all(x) x.begin(), x.end()
#define sz(x)  (int)x.size()
#define pp  pair<int,int>

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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = 0;
    int a = 0, b = 0,c = 0;
    int len = n + 1;
    for(int i = 0; i < n; i++) {
        int a = (s[i] == 'a');
        int b = (s[i] == 'b');
        int c = (s[i] == 'c');
        for(int j = i + 1; j < min(i + 7, n); j++) {
            a += (s[j] == 'a');
            b += (s[j] == 'b');
            c += (s[j] == 'c');

            if(a > b && a > c) {
                len = min(j - i + 1,len);
            }
        }
    }
    cout << (len == n + 1 ? -1 : len) << endl;
}

signed main(){
    ios_base::sync_with_stdio(false);
#ifndef LOCAL
    cin.tie(nullptr);
#endif
    cout << fixed << std::setprecision(25);
    cerr << fixed << std::setprecision(10);

    int cases = 1;
    cin >> cases;
    for (int tc = 1; tc <= cases; tc++){
        solve();
    }

    return 0;
}