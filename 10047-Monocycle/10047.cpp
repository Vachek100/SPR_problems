
#include <cstdio>
#include <queue>

using namespace std;

const int MAX = 25;

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

struct State {
    int r, c;
    int dir;
    int color;
    int time;
};

char grid[MAX][MAX];

bool visited[MAX][MAX][4][5];

int main() {
    int M, N;
    int caseNumber = 1;

    while (scanf("%d %d", &M, &N) == 2 && (M != 0 || N != 0)) {

        int startR = 0, startC = 0;
        int targetR = 0, targetC = 0;

        // Nacteni mapy
        for (int i = 0; i < M; i++) {
            scanf("%s", grid[i]);

            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 'S') {
                    startR = i;
                    startC = j;
                }

                if (grid[i][j] == 'T') {
                    targetR = i;
                    targetC = j;
                }
            }
        }

        // Vynulovani navstivenych stavu
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                for (int d = 0; d < 4; d++) {
                    for (int c = 0; c < 5; c++) {
                        visited[i][j][d][c] = false;
                    }
                }
            }
        }

        queue<State> q;

        // Zacatek: sever, zelena barva, cas 0
        State start;

        start.r = startR;
        start.c = startC;
        start.dir = 0;
        start.color = 0;
        start.time = 0;

        q.push(start);

        visited[startR][startC][0][0] = true;

        int result = -1;

        // BFS
        while (!q.empty()) {

            State current = q.front();
            q.pop();

            int r = current.r;
            int c = current.c;
            int dir = current.dir;
            int color = current.color;
            int time = current.time;

            // Kontrola cile
            if (r == targetR && c == targetC && color == 0) {
                result = time;
                break;
            }

            // 1. Pohyb dopredu
            int nr = r + dr[dir];
            int nc = c + dc[dir];

            int newColor = (color + 1) % 5;

            if (nr >= 0 && nr < M &&
                nc >= 0 && nc < N &&
                grid[nr][nc] != '#') {

                if (!visited[nr][nc][dir][newColor]) {

                    visited[nr][nc][dir][newColor] = true;

                    State next;

                    next.r = nr;
                    next.c = nc;
                    next.dir = dir;
                    next.color = newColor;
                    next.time = time + 1;

                    q.push(next);
                }
            }

            // 2. Otoceni doleva
            int leftDir = (dir + 3) % 4;

            if (!visited[r][c][leftDir][color]) {

                visited[r][c][leftDir][color] = true;

                State next;

                next.r = r;
                next.c = c;
                next.dir = leftDir;
                next.color = color;
                next.time = time + 1;

                q.push(next);
            }

            // 3. Otoceni doprava
            int rightDir = (dir + 1) % 4;

            if (!visited[r][c][rightDir][color]) {

                visited[r][c][rightDir][color] = true;

                State next;

                next.r = r;
                next.c = c;
                next.dir = rightDir;
                next.color = color;
                next.time = time + 1;

                q.push(next);
            }
        }

        // Vystup
        if (caseNumber > 1) {
            printf("\n");
        }

        printf("Case #%d\n", caseNumber);

        if (result != -1) {
            printf("minimum time = %d sec\n", result);
        }
        else {
            printf("destination not reachable\n");
        }

        caseNumber++;
    }

    return 0;
}
