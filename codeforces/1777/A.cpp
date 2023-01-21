/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

#define N 105

int main() {
        int t;
        scanf("%d", &t);

        while(t--) {
                static int aa[N];
                int n;
                scanf("%d", &n);

                for(int i = 0; i < n; i++)
                        scanf("%d", &aa[i]);

                int ans = 0;
                for(int i = 0; i + 1 < n; i++) {
                        if(aa[i] % 2 == aa[i + 1] % 2)
                                ans++;
                }
                printf("%d\n", ans);

        }
        return 0;
}