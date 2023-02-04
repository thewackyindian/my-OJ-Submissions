/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>
#include <string.h>

#define N 200005

int max(int a, int b) { return a > b ? a : b;}

static char ss[N];

int main() {
        int t = 1;
        scanf("%d", &t);
        while(t--) {
                int n;
                scanf("%d", &n);

                scanf("%s", ss);
                int cntl[26], cntr[26];
                
                memset(cntr, 0, sizeof(cntr));
                memset(cntl, 0, sizeof(cntl));
                
                int l = 0, r = 0;
                for(int i = 0; i < n; i++)
                        r += !cntr[ss[i] - 'a']++;
                int ans = 0;
                for(int i = 0; i < n; i++) {
                        r -= !--cntr[ss[i] - 'a'];
                        l += !cntl[ss[i] - 'a']++;
                        ans = max(ans, l + r);

                }
                printf("%d\n", ans);
        }
        return 0;
}