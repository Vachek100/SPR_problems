#include <vector>
#include <string>
#include <cstdio>

void markPawnMoves(std::vector<std::string>& board, int row, int col) {

    char pawn = board[row][col];

    // =========================================
    // BÍLÝ PĚŠEC
    // =========================================

    if (pawn == 'P') {

        // Bílý pěšec se pohybuje nahoru
        int nextRow = row - 1;

        // Pohyb o jedno pole dopředu
        if (nextRow >= 0 && board[nextRow][col] == '.') {
            board[nextRow][col] = '*';

            // Pohyb o dvě pole - pouze z výchozí řady
            if (row == 6 && board[row - 2][col] == '.') {
                board[row - 2][col] = '*';
            }
        }

        // Braní vlevo
        if (nextRow >= 0 && col - 1 >= 0) {
            char target = board[nextRow][col - 1];

            // Černá figura
            if (target >= 'a' && target <= 'z') {
                board[nextRow][col - 1] = '*';
            }
        }

        // Braní vpravo
        if (nextRow >= 0 && col + 1 < 8) {
            char target = board[nextRow][col + 1];

            // Černá figura
            if (target >= 'a' && target <= 'z') {
                board[nextRow][col + 1] = '*';
            }
        }
    }


    // =========================================
    // ČERNÝ PĚŠEC
    // =========================================

    else if (pawn == 'p') {

        // Černý pěšec se pohybuje dolů
        int nextRow = row + 1;

        // Pohyb o jedno pole dopředu
        if (nextRow < 8 && board[nextRow][col] == '.') {
            board[nextRow][col] = '*';

            // Pohyb o dvě pole - pouze z výchozí řady
            if (row == 1 && board[row + 2][col] == '.') {
                board[row + 2][col] = '*';
            }
        }

        // Braní vlevo
        if (nextRow < 8 && col - 1 >= 0) {
            char target = board[nextRow][col - 1];

            // Bílá figura
            if (target >= 'A' && target <= 'Z') {
                board[nextRow][col - 1] = '*';
            }
        }

        // Braní vpravo
        if (nextRow < 8 && col + 1 < 8) {
            char target = board[nextRow][col + 1];

            // Bílá figura
            if (target >= 'A' && target <= 'Z') {
                board[nextRow][col + 1] = '*';
            }
        }
    }
}

void markRookMoves(std::vector<std::string>& board, int row, int col) {

    char rook = board[row][col];

    // =========================================
    // BÍLÁ VĚŽ a ČERNÁ VĚŽ POHYB
    // =========================================

    if (rook == 'R' || rook == 'r') {

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;

            if (newRow < 0) {
                break;
            }

            if (board[newRow][col] == '.' || board[newRow][col] == '*') {
                board[newRow][col] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;

            if (newRow >= 8) {
                break;
            }

            if (board[newRow][col] == '.' || board[newRow][col] == '*') {
                board[newRow][col] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newCol = col + i;

            if (newCol >= 8) {
                break;
            }

            if (board[row][newCol] == '.' || board[row][newCol] == '*') {
                board[row][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newCol = col - i;

            if (newCol < 0) {
                break;
            }

            if (board[row][newCol] == '.' || board[row][newCol] == '*') {
                board[row][newCol] = '*';
            } else {
                break;
            }
        }

    }
}

void markBishopMoves(std::vector<std::string>& board, int row, int col) {

    char bishop = board[row][col];

    if (bishop == 'B' || bishop == 'b') {

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;
            int newCol = col + i;

            if (newRow < 0 || newCol >= 8) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;
            int newCol = col - i;

            if (newRow < 0 || newCol < 0) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;
            int newCol = col + i;

            if (newRow >= 8 || newCol >= 8) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;
            int newCol = col - i;

            if (newRow >= 8 || newCol < 0) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }
    }

}

void markQueenMoves(std::vector<std::string>& board, int row, int col) {

    char queen = board[row][col];

    if (queen == 'Q' || queen == 'q') {

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;
            int newCol = col + i;

            if (newRow < 0 || newCol >= 8) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;
            int newCol = col - i;

            if (newRow < 0 || newCol < 0) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;
            int newCol = col + i;

            if (newRow >= 8 || newCol >= 8) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;
            int newCol = col - i;

            if (newRow >= 8 || newCol < 0) {
                break;
            }

            if (board[newRow][newCol] == '.' || board[newRow][newCol] == '*') {
                board[newRow][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row - i;

            if (newRow < 0) {
                break;
            }

            if (board[newRow][col] == '.' || board[newRow][col] == '*') {
                board[newRow][col] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newRow = row + i;

            if (newRow >= 8) {
                break;
            }

            if (board[newRow][col] == '.' || board[newRow][col] == '*') {
                board[newRow][col] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newCol = col + i;

            if (newCol >= 8) {
                break;
            }

            if (board[row][newCol] == '.' || board[row][newCol] == '*') {
                board[row][newCol] = '*';
            } else {
                break;
            }
        }

        for (int i = 1; i < 8; i++) {
            int newCol = col - i;

            if (newCol < 0) {
                break;
            }

            if (board[row][newCol] == '.' || board[row][newCol] == '*') {
                board[row][newCol] = '*';
            } else {
                break;
            }
        }



    }

}



int main(int argc, char *argv[]) {

    int gameNum = 1;

    while (true) {

        std::vector<std::string> board(8);

        // Načtení šachovnice
        for (int i = 0; i < 8; i++) {
            char row[9];

            if (fscanf(stdin, "%8s", row) != 1) {
                return 0;
            }

            board[i] = row;
        }

        // Kontrola konce vstupu
        bool end = true;

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] != '.') {
                    end = false;
                    break;
                }
            }

            if (!end) {
                break;
            }
        }

        if (end) {
            fprintf(stdout, "\nKONECNA BOARDA KTERA SE NEKONTROLUJE\n");
            break;
        }

        // Hledání postaviček
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {

                if (board[row][col] == 'P' ||
                    board[row][col] == 'p') {

                    markPawnMoves(board, row, col);
                }else if (board[row][col] == 'R' ||
                    board[row][col] == 'r') {

                    markRookMoves(board, row, col);
                }else if (board[row][col] == 'B' ||
                    board[row][col] == 'b') {

                    markBishopMoves(board, row, col);
                }else if (board[row][col] == 'Q' ||
                    board[row][col] == 'q') {

                    markQueenMoves(board, row, col);
                }

            }
        }

        // Výpis šachovnice
        for (int i = 0; i < 8; i++) {
            fprintf(stdout, "%s\n", board[i].c_str());
        }
        fprintf(stdout, "\n");
    }

    return 0;
}