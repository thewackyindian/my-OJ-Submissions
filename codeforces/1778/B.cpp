/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

#define N 100005

int min(int a, int b) { return a < b ? a : b; }
int max(int a, int b) { return a > b ? a : b; }
int abs(int a) { return a < 0 ? -a : a;}

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                static int aa[N], pp[N], loc[N];
                int n, m, d;
                scanf("%d%d%d", &n, &m, &d);
                for(int i = 0; i < n; i++) {
                        scanf("%d", &pp[i]);
                        loc[pp[i]] = i + 1;
                }
                for(int i = 0; i < m; i++)
                        scanf("%d", &aa[i]);
                int best = N;
                for(int i = 0; i + 1 < m; i++) {
                        int swaps;
                        if((loc[aa[i]] > loc[aa[i + 1]]) || (loc[aa[i + 1]] > loc[aa[i]] + d)) {
                                swaps  = 0;
                        }
                        else {
                                swaps = loc[aa[i + 1]] - loc[aa[i]];
                                int dd = d, l = loc[aa[i]], r = loc[aa[i + 1]];
                                if(l + d + 1 <= n) {
                                        swaps = min(swaps,l + d - r + 1);
                                }
                                else {
                                        dd = n - l;
                                        if(l - (d - dd) - 1 >= 1) {
                                                swaps = min(swaps,(d - dd) + 1 + (n - r));
                                        }
                                }


                        }
                        best = min(swaps, best);

                }
                printf("%d\n", best);

        }

        return 0;
}