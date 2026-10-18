#include <cstdio>

const int MAX = 1002;

int cuts[MAX];
int dp[MAX][MAX];

int main() {
    int l;

    while (scanf("%d", &l) == 1 && l != 0) {
        int n;
        scanf("%d", &n);

        cuts[0] = 0;

        for (int i = 1; i <= n; i++) {
            scanf("%d", &cuts[i]);
        }

        cuts[n + 1] = l;

        int total = n + 2;

        
        for (int i = 0; i < total; i++) {
            dp[i][i] = 0;

            if (i + 1 < total) {
                dp[i][i + 1] = 0;
            }
        }


        for (int len = 2; len < total; len++) {
            for (int i = 0; i + len < total; i++) {
                int j = i + len;

                dp[i][j] = 1000000000;


                for (int k = i + 1; k < j; k++) {
                    int cost = dp[i][k]
                             + dp[k][j]
                             + cuts[j] - cuts[i];

                    if (cost < dp[i][j]) {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        printf("The minimum cutting is %d.\n", dp[0][total - 1]);
    }

    return 0;
}