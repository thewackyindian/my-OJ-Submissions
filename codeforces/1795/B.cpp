/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {

                int n, m;
                scanf("%d%d", &n, &m);


                int ll = 0, rr = 0;
                for(int i = 0; i < n; i++) {
                        int l, r;
                        scanf("%d%d", &l, &r);
                        if(l == m) ll++;
                        if(r == m) rr++;

                }
                printf((ll > 0 && rr > 0) ? "YES\n" : "NO\n");


        }

        return 0;
}