/**
 * code generated by JHelper
 * More info: https://github.com/AlexeyDmitriev/JHelper
 * @author : Raj Karan Singh
 */


//Actual solution is in solveOne function


#include <bits/stdc++.h>
using namespace std;

#define int     int64_t
#define endl    '\n'
#define all(x)  x.begin(), x.end()
#define sz(x)   (int)x.size()
#define pp      pair<int,int>

template <typename A, typename B> istream& operator>>(istream &is, pair<A, B> &p) { return is >> p.first >> p.second; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>istream& operator >> (istream &is, T_container &v) {for(T &x : v) is >> x; return is;}
template <typename A, typename B>ostream &operator<<(ostream &os, const pair<A, B> &p){return os << '(' << p.first << ", " << p.second << ')';}
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>ostream &operator<<(ostream &os, const T_container &v){    os << '{';string sep;for (const T &x : v)os << sep << x, sep = ", ";return os << '}';}

template<class T>
using min_heap = priority_queue<T,vector<T>,greater<T> >;
const int mod = 998244353, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

namespace mod_operations {
    int madd(int a, int b) {
        return (a + b) % mod;
    }
    int msub(int a, int b) {
        return (((a - b) % mod) + mod) % mod;
    }
    int mmul(int a, int b) {
        return ((a % mod) * (b % mod)) % mod;
    }
    int mpow(int base, int exp) {
        int res = 1;
        while (exp) {
            if (exp % 2 == 1){
                res = (res * base) % mod;
            }
            exp >>= 1;
            base = (base * base) % mod;
        }
        return res;
    }
    int minv(int base) {
        return mpow(base, mod - 2);
    }
    int mdiv(int a, int b) {
        return mmul(a, minv(b));
    }

    const int FACTORIAL_SIZE = 1.1e6;
    int fact[FACTORIAL_SIZE], ifact[FACTORIAL_SIZE];
    bool __factorials_generated__ = 0;
    void gen_factorial(int n) {
        __factorials_generated__ = 1;
        fact[0] = fact[1] = ifact[0] = ifact[1] = 1;

        for (int i = 2; i <= n; i++) {
            fact[i] = (i * fact[i - 1]) % mod;
        }
        ifact[n] = minv(fact[n]);
        for (int i = n - 1; i >= 2; i--) {
            ifact[i] = ((i + 1) * ifact[i + 1]) % mod;
        }
    }
    int ncr(int n, int k) {
        if (!__factorials_generated__) {
            cerr << "Call gen_factorial you dope" << endl;
            exit(1);
        }
        if (k < 0 || n < k) return 0;
        int den = (ifact[k] * ifact[n - k]) % mod;
        return (den * fact[n]) % mod;
    }
}
using namespace mod_operations;

class CBinaryStringsAreFun {
public:
        void solveOne(std::istream& in, std::ostream& out) {
            int n;
            in >> n;
            string s;
            in >> s;
            string ss(2 * n - 1, ' ');
            for(int i = 0; i < n; i++)
                ss[2*i] = s[i];

            int z = 0, o = 0;
            int ans = 0;
            int gone = 0;
            for(int i = 0; i < 2*n - 1; i += 2) {
                int sum = 0;
                int m = i + 1, mm = (m + 1) / 2;
                int g = m / 2 - gone;
                z += ss[i] == '0';
                o += ss[i] == '1';
                if(ss[i] == '0') {
                    if(z >= mm)
                        sum = (mpow(2,g));
                    else{
                        int req = mm - z;
                        z += req;
                        g -= req;
                        gone += req;
                        sum = mpow(2,g);
                    }
                }
                else{
                    if(o >= mm)
                        sum = mpow(2,g);
                    else{
                        int req = mm - o;
                        o += req;
                        g -= req;
                        gone += req;
                        sum = mpow(2,g);
                    }
                }
                ans = madd(ans, sum);
            }
            out << ans << endl;

        }
        void solve(std::istream& in, std::ostream& out) {
            int cases = 1;
            in >> cases;
            for (int tc = 1; tc <= cases; tc++) {
//                out << "Case #" << tc << ": ";
                solveOne(in , out);
            }
        }
};


signed main() {
        ios_base::sync_with_stdio(false);
	    CBinaryStringsAreFun solver;
	    std::istream& in(std::cin);
	    std::ostream& out(std::cout);
	    in.tie(nullptr);
	    solver.solve(in, out);
	    return 0;
}
