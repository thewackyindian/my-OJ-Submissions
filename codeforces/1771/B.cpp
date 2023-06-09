/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author Raj Karan Singh
 */

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

class BHossamAndFriends {
public:
        void rajkaran(std::istream& in, std::ostream& out) {
            int n, m;
            in >> n >> m;
            vector<set<int>>g(n + 1);
            for(int i = 0; i < m; i++) {
                int u, v;
                in >> u >> v;
                if(u > v)swap(u, v);
                g[u].insert(v);
            }
            int ans = 0;
            int l = 1, r = 1;
            multiset<int>s;
            while(r <= n) {
                if(s.count(r)) {
                   while(s.count(r) && l < r) {
                       for(auto &x : g[l])
                           s.erase(s.find(x));
                       l++;
                   }
                }
                
                ans += r - l + 1;
                for(auto &x : g[r])
                    s.insert(x);
                r++;
            }
            out << ans << endl;
        }
        void solve(std::istream& in, std::ostream& out) {
            int cases = 1;
            in >> cases;
            for (int it = 0; it < cases; ++it) {
                // cout << "Case #" << (it + 1) << ": ";
                rajkaran(in, out);
            }
        }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
	BHossamAndFriends solver;
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}
