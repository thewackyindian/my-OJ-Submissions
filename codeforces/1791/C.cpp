/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

#define N 2005

static char ss[N];

int max(int a, int b) { return a > b ? a : b; }

int main() {
        int t = 1;
        scanf("%d", &t);
        while(t--) {
                int n;
                scanf("%d", &n);

                scanf("%s", ss);
                int l = 0, r = n - 1;
                while(ss[l] != ss[r]){
                        l++;
                        r--;
                }
                printf("%d\n", max(0,r - l + 1));
        }
        return 0;
}