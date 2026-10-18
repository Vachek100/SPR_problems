#include <cstdio>

const int MAX_N = 35;

int n;
int best;

unsigned long long cover[MAX_N];
unsigned long long allCovered;


void dfs(unsigned long long covered, int used) {

    if (used >= best)
        return;

    if (covered == allCovered) {
        best = used;
        return;
    }

    int city = -1;

    for (int i = 0; i < n; i++) {
        unsigned long long bit = 1ULL << i;

        if ((covered & bit) == 0) {
            city = i;
            break;
        }
    }

    unsigned long long possibilities = cover[city];

    for (int i = 0; i < n; i++) {

        unsigned long long bit = 1ULL << i;

        if (possibilities & bit) {

            dfs(covered | cover[i], used + 1);
        }
    }
}


int main() {

    while (true) {

        int m;
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0)
            break;

        for (int i = 0; i < n; i++)
            cover[i] = 0;


        for (int i = 0; i < m; i++) {

            int a, b;
            scanf("%d %d", &a, &b);

            a--;
            b--;

            cover[a] |= 1ULL << b;
            cover[b] |= 1ULL << a;
        }


        for (int i = 0; i < n; i++) {
            cover[i] |= 1ULL << i;
        }

        allCovered = (1ULL << n) - 1;

        best = n;

        dfs(0, 0);

        printf("%d\n", best);
    }

    return 0;
}