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

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    map<char,vector<int>>cc;

    for(int i = 0; i < n; i++) {
        cc[s[i]].push_back(i);
    }


    int m = n;
    string ss;
    map<char,vector<int>>ans;
    map<char,vector<int>>c;

    auto get = [&](int x)->int{
        set<char>ihave;
        for(char ch = 'a'; ch <= 'z'; ch++)
            ihave.insert(ch);
        vector<int>denewale;
        set<pair<int,char>>lenewale;
        for(auto &y : c){
            int sz = sz(y.second);
            if(sz == x)ihave.erase(y.first);
            if(sz > x){
                int d = sz - x;
                while(d > 0){
                    denewale.push_back(y.second.back());
                    y.second.pop_back();
                    d--;
                }
                ihave.erase(y.first);
            }
            else if(sz < x){
                lenewale.insert({sz,y.first});
            }
        }

        int change = 0;
        while(!lenewale.empty() && !denewale.empty()){
            auto b = lenewale.end();
            b--;
            int bc = b->first;
            char cb = b->second;
            int req = x - bc;
            lenewale.erase(b);
            while(!denewale.empty() && req > 0){
                c[cb].push_back(denewale.back());
                denewale.pop_back();
                req--;
                change++;
            }

            if(req == 0)
                ihave.erase(cb);
            else
                lenewale.insert({sz(c[cb]), cb});
        }

        while(sz(lenewale) > 1){
            auto b = lenewale.end();
            b--;
            int bc = b->first;
            char cb = b->second;
            auto f = lenewale.begin();
            int fc = f->first;
            char cf = f->second;
            int req = x - bc;
            lenewale.erase(b);
            lenewale.erase(f);
            while(!c[cf].empty() && req > 0){
                c[cb].push_back(c[cf].back());
                c[cf].pop_back();
                change++;
                req--;
            }
            if(req == 0)
                ihave.erase(cb);
            else
                lenewale.insert({sz(c[cb]), cb});
            if(c[cf].empty()){

            }
            else
                lenewale.insert({sz(c[cf]), cf});
        }

        bool cannot = false;
        while(!denewale.empty()){
            if(ihave.empty()){
                cannot = true;
                break;
            }
            char ch = *ihave.begin();
            c[ch].push_back(denewale.back());
            change++;
            denewale.pop_back();
            if(sz(c[ch]) == x){
                ihave.erase(ch);
            }
        }

        if(cannot)return -1;
        else
           return change;
    };

    for(int x = 1; x * x <= n; x++) {
        if(n % x == 0) {
            c = cc;
            int p = get(x);
            if(p != -1){
                if(p < m){
                    m = p;
                    ans = c;
                }
            }
            c = cc;
            p = get(n / x);
            if(p != -1){
                if(p < m){
                    m = p;
                    ans = c;
                }
            }

        }
    }
    string S(n,' ');
    for(auto &x : ans){
        for(auto &y : x.second){
            S[y] = x.first;
        }
    }
    cout << m << endl;
    cout << S << endl;

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