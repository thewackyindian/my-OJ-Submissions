/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>
#include <string.h>

#define N 100010

long long max(long long a, long long b) { return a > b ? a : b; }

int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
                char aa[N], bb[N], dd[26];
                memset(dd, 0, sizeof(dd));
                int n, k;
                scanf("%d%d", &n, &k);
                scanf("%s", aa);
                scanf("%s", bb);
                int cnt[26];
                memset(cnt, 0, sizeof(cnt));
                int m = 0;
                for(int i = 0; i < n; i++)
                        cnt[aa[i] - 'a']++;

                for(int i = 0; i < 26; i++) if(cnt[i] > 0)
                        dd[m++] = i;

                long long best = 0;
                for(int i = 0; i < (1 << m); i++) {
                        int used[26];
                        memset(used, 0, sizeof(used));
                        int cc = 0;
                        for(int j = 0; j < m; j++) if(i & (1 << j)) {
                                used[dd[j]] = 1;
                                cc++;
                        }

                        if(cc > k) continue;

                        long long pp = 0, len = 0;
                        for(int k = 0; k < n; k++) {
                                if(aa[k] == bb[k] || used[aa[k] - 'a']) {
                                        len++;
                                }
                                else {
                                        pp += (len * (len + 1)) / 2;
                                        len = 0;
                                }
                        }
                        pp += (len * (len + 1)) / 2;
                        best = max(best, pp);

                }
                printf("%lld\n", best);

        }
        return 0;
}