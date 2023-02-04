/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

#define N 50

static char ss[N];

int main() {
        int t = 1;
        scanf("%d", &t);
        while(t--) {
                int n;
                scanf("%d", &n);

                scanf("%s", ss);
                int ok = 0;
                int x = 0, y = 0;
                for(int i = 0; i < n; i++) {
                        switch (ss[i]) {
                                case 'U' : y++;
                                        break;
                                case 'D' : y--;
                                        break;
                                case 'R' : x++;
                                        break;
                                case 'L' : x--;
                                        break;
                        }
                        // printf("%d % d\n", x, y);
                        ok |= (x == 1 && y == 1);

                }
                printf(ok ? "YES\n": "NO\n");
        }
        return 0;
}