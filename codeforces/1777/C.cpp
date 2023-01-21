/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#define N       100005
#define lim     1000001
#define F       5

unsigned int X;
static int *f[N], eo[N], c[N], aa[N];
int good;
int n, m;

int min(int a, int b) {return a < b ? a : b;}

void srand_() {
        struct timeval tv;

        gettimeofday(&tv, NULL);
        X = tv.tv_sec ^ tv.tv_usec | 1;
}

int rand_() {
        return (X *= 3) >> 1;
}

void sort(int *aa, int l, int r) {
        while (l < r) {
                int i = l, j = l, k = r;
                int a = aa[l + rand_() % (r - l)], tmp;

                while (j < k)
                        if (aa[j] == a)
                                j++;
                        else if (aa[j] < a) {
                                tmp = aa[i], aa[i] = aa[j], aa[j] = tmp;
                                i++, j++;
                        } else {
                                k--;
                                tmp = aa[j], aa[j] = aa[k], aa[k] = tmp;
                        }
                sort(aa, l, i);
                l = k;
        }
}


void append(int i, int j) {
        int o = eo[i]++;

        if (o >= 2 && (o & o - 1) == 0)
                f[i] = (int *) realloc(f[i], o * 2 * sizeof *f[i]);
        f[i][o] = j;
}



void add(int x) {
        for(int i = 0; i < eo[x]; i++) {
                if(f[x][i] > m) break;
                good -= c[f[x][i]] > 0;
                c[f[x][i]]++;
                good += c[f[x][i]] > 0;
        }

}

void rem(int x) {
        for(int i = 0; i < eo[x]; i++) {
                if(f[x][i] > m) break;
                good -= c[f[x][i]] > 0;
                c[f[x][i]]--;
                good += c[f[x][i]] > 0;
        }
}

int main() {
        for (int i = 0; i < N; i++)
                f[i] = (int *) malloc(2 * sizeof *f[i]), eo[i] = 0;
        for(int i = 1; i < N; i++)
                for(int j = i; j < N; j += i)
                        append(j, i);


        // for(int i = 1; i < N; i++) {
        //         for(int k = 0; k < eo[i]; k++)
        //                 printf("%d",f[i][k]);
        //         printf("\n");
        // }
        int t;
        scanf("%d", &t);
        while(t--) {
                scanf("%d%d", &n, &m);
                for(int i = 0; i < N; i++)
                        c[i] = 0;
                for(int i = 0; i < n; i++)
                        scanf("%d", &aa[i]);
                sort(aa, 0, n);
                int ans = lim;
                good = 0;
                int l = 0, r = 0;
                while(r < n) {
                        add(aa[r]);
                        while(good >= m && l <= r) {
                                ans = min(ans, aa[r] - aa[l]);
                                rem(aa[l]);
                                l++;
                        }
                        r++;

                }
                printf("%d\n", ans == lim ? -1 : ans);

        }
        return 0;
}