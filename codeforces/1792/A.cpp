/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

int main() {
        int t = 1;
        scanf("%d", &t);

        while(t--) {
                int n;
                scanf("%d", &n);
                int cnt  = 0;
                for(int i = 0; i < n; i++) {
                        int x;
                        scanf("%d", &x);
                        cnt += (x == 1);
                }
                printf("%d\n", (cnt + 2 - 1) / 2 + (n - cnt));
        }
        return 0;
}