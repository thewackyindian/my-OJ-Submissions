/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>


#define int long long
#define mod 1000000007

signed main() {
        int t;
        scanf("%lld", &t);

        while(t--) {
                int n;
                scanf("%lld", &n);
                int ans = (n * (n - 1))  % mod;
                for(int i = 1; i <= n; i++)
                        ans = (ans * i) % mod;

                printf("%lld\n", ans);

        }
        return 0;
}