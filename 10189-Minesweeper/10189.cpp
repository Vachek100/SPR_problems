#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

int main() {

    int n = 0; // rowCount
    int m = 0; // colCount
    int fieldNumber = 1;

    while (true) {

        fscanf(stdin, "%d %d", &n, &m);

        if (n == 0 && m == 0) {
            break;
        }

        std::vector<std::string> field(n);

        for (int i = 0; i < n; ++i) {
            char row[101];
            fscanf(stdin, "%100s", row);
            field[i] = row;
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {

                if (field[i][j] == '*') {
                    continue;
                }

                int mineCount = 0;

                for (int di = -1; di <= 1; ++di) {
                    for (int dj = -1; dj <= 1; ++dj) {

                        if (di == 0 && dj == 0) {
                            continue;
                        }

                        int ni = i + di;
                        int nj = j + dj;

                        if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                            if (field[ni][nj] == '*') {
                                mineCount++;
                            }
                        }
                    }
                }

                field[i][j] = '0' + mineCount;
            }
        }

        if (fieldNumber > 1) {
            fprintf(stdout, "\n");
        }

        fprintf(stdout, "Field #%d:\n", fieldNumber);

        for (int i = 0; i < n; ++i) {
            fprintf(stdout, "%s\n", field[i].c_str());
        }

        fieldNumber++;
    }

    return 0;
}