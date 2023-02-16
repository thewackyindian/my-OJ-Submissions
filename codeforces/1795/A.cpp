/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>


#define N 100

int max(int a, int b) { return a > b ? a : b; }
int abs(int a) { return a < 0 ? -a : a;}

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                static char ss[N], tt[N];
                int n, m;
                scanf("%d%d", &n, &m);

                scanf("%s", ss);
                scanf("%s", tt);


                for(int i = 0; i < m; i++)
                        ss[n + i] = tt[m - 1 - i];

                int ok = 0;
                for(int i = 1; i < n + m; i++) {
                        if(ss[i] == ss[i - 1])
                                ok++;
                }

                printf((ok <= 1) ? "YES\n" : "NO\n");


        }

        return 0;
}