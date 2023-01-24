/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

int min(int a, int b) { return a < b ? a : b; }
int abs(int a) { return a < 0 ? -a : a;}

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                int a, b , c, d;
                scanf("%d%d%d%d", &a, &b, &c, &d);
                if (a == 0) {
                        printf("1\n");
                }
                else {
                        printf("%d\n", a + 2 * min(b, c) + min(a + 1, abs(b - c) + d));
                }
        }

        return 0;
}