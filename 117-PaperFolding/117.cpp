#include <cstdio>
#include <cstring>

const int SIZE = 300;
const int MAX_POINTS = 10000;

struct Point {
    int row;
    int col;
};

char picture[SIZE][SIZE];
Point points[MAX_POINTS];

int pointCount;

int minRow;
int maxRow;
int minCol;
int maxCol[SIZE];

const int dr[8] = {
    1, 0, 1, 0,
    0, -1, 0, -1
};

const int dc[8] = {
    1, 1, -1, -1,
    -1, -1, 1, 1
};


void addPoint(int row, int col, char symbol) {

    points[pointCount].row = row;
    points[pointCount].col = col;

    picture[row][col] = symbol;

    if (row < minRow)
        minRow = row;

    if (row > maxRow)
        maxRow = row;

    if (col < minCol)
        minCol = col;

    if (col > maxCol[row])
        maxCol[row] = col;

    pointCount++;
}


void dragonCurve(int fold, int n) {

    if (fold > n)
        return;

    addPoint(
        points[pointCount - 1].row - 1,
        points[pointCount - 1].col - 1,
        '_'
    );

    for (int i = pointCount - 2; i > 0; i--) {

        Point current = points[i];
        Point previous = points[i - 1];

        int direction =
            (picture[current.row][current.col] == '_') * 4 +
            (current.row == previous.row) * 2 +
            (current.col > previous.col);

        int newRow =
            points[pointCount - 1].row + dr[direction];

        int newCol =
            points[pointCount - 1].col + dc[direction];

        char symbol;

        if (direction < 4)
            symbol = '|';
        else
            symbol = '_';

        addPoint(newRow, newCol, symbol);
    }

    dragonCurve(fold + 1, n);
}


int main() {

    int n;

    while (true) {

        fscanf(stdin, "%d", &n);

        if (n == 0) break;

        memset(picture, ' ', sizeof(picture));
        memset(maxCol, 0, sizeof(maxCol));

        pointCount = 0;

        minRow = SIZE;
        maxRow = 0;
        minCol = SIZE;

        addPoint(150, 150, '_');
        addPoint(150, 151, '|');

        dragonCurve(2, n);

        for (int row = minRow; row <= maxRow; row++) {

            for (int col = minCol; col <= maxCol[row]; col++) {
                fprintf(stdout, "%c", picture[row][col]);
            }
            fprintf(stdout, "\n");
        }
        fprintf(stdout, "^\n");
    }

    return 0;
}