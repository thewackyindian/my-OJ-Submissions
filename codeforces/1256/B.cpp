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
const int mod = 1e9 + 7, inf = 1e18L + 5, N = 2e5 + 5;
const string yes = "YES", no = "NO";

class BMinimizeThePermutation {
public:
        void solveOne(std::istream& in, std::ostream& out) {
            int n;
            in >> n;
            vector<int> a(n);
            in >> a;
            int ops = n - 1;
            int i = 0;
            while(ops > 0 && i < n) {
                auto pos = min_element(a.begin() + i, a.end()) - a.begin();

//                out << "pos : " << pos << endl;
                for(int j = pos; ops > 0 && j - 1 >= i; j--){
//                    out << "j : " << j << endl;
                    swap(a[j], a[j - 1]);
                    ops--;
                }
                if(pos == i) i++;
                else i = pos;
            }
            for(int i = 0; i < n; i++)
                out << a[i] << " \n"[i + 1 == n];

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
	    BMinimizeThePermutation solver;
	    std::istream& in(std::cin);
	    std::ostream& out(std::cout);
	    in.tie(nullptr);
	    solver.solve(in, out);
	    return 0;
}
