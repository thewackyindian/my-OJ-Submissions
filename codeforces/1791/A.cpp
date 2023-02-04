/**
    author: ਰਾਜ ਕਰਨ ਸਿੰਘ
**/
#include <stdio.h>

char ss[10] = "codeforces";

int main() {
        int t = 1;
        scanf("%d", &t);
        while(t--) {
                char ch;
                scanf("%c", &ch);
                scanf("%c", &ch);

                int ok = 0;
                for(int i = 0; i < 10; i++) {
                        ok |= (ss[i] == ch);
                }
                printf(ok ? "YES\n": "NO\n");
        }
        return 0;
}