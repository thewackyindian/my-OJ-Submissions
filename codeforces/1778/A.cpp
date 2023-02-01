/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

#define N 100005

int max(int a, int b) { return a > b ? a : b; }
int abs(int a) { return a < 0 ? -a : a;}

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                static int aa[N], p[N];
                int n;
                scanf("%d", &n);
                p[0] = 0;
                for(int i = 1; i <= n; i++) {
                        scanf("%d", &aa[i]);
                        p[i] = aa[i] + p[i - 1];
                }

                int ans = -N;
                for(int i = 1; i + 1 <= n; i++) {
                        int l = p[i - 1], r = p[n] - p[i + 1];
                        int cur = (-aa[i]) + (-aa[i + 1]);
                        ans = max(ans,l + r + cur);
                }
                printf("%d\n", ans);

        }

        return 0;
}