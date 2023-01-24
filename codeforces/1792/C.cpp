/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

int main() {

        int t;
        scanf("%d", &t);
        while(t--) {
                int n;
                scanf("%d", &n);
                int p[n + 1];
                for(int i = 0; i < n; i++) {
                        int x;
                        scanf("%d", &x);
                        p[--x] = i;
                }
                int m = n / 2;
                while(m > 0) {
                        if(p[m] > p[m - 1] && p[n - m - 1] < p[n  - m])
                                m--;
                        else
                                break;
                }
                printf("%d\n", m);

        }
        return 0;
}