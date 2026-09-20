#include <vector>
#include <string>
#include <cstdio>


bool pawnAttacks(std::vector<std::string>& board,
                 int row, int col,
                 int kingRow, int kingCol) {

    if (board[row][col] == 'P') {

        int newRow = row - 1;

        if (newRow >= 0) {

            if (col - 1 >= 0 &&
                newRow == kingRow &&
                col - 1 == kingCol) {
                return true;
            }

            if (col + 1 < 8 &&
                newRow == kingRow &&
                col + 1 == kingCol) {
                return true;
            }
        }
    }

    if (board[row][col] == 'p') {

        int newRow = row + 1;

        if (newRow < 8) {

            if (col - 1 >= 0 &&
                newRow == kingRow &&
                col - 1 == kingCol) {
                return true;
            }

            if (col + 1 < 8 &&
                newRow == kingRow &&
                col + 1 == kingCol) {
                return true;
            }
        }
    }

    return false;
}


bool rookAttacks(std::vector<std::string>& board,
                 int row, int col,
                 int kingRow, int kingCol) {

    for (int i = 1; i < 8; i++) {

        int newRow = row - i;

        if (newRow < 0) {
            break;
        }

        if (newRow == kingRow && col == kingCol) {
            return true;
        }

        if (board[newRow][col] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newRow = row + i;

        if (newRow >= 8) {
            break;
        }

        if (newRow == kingRow && col == kingCol) {
            return true;
        }

        if (board[newRow][col] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newCol = col + i;

        if (newCol >= 8) {
            break;
        }

        if (row == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[row][newCol] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newCol = col - i;

        if (newCol < 0) {
            break;
        }

        if (row == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[row][newCol] != '.') {
            break;
        }
    }

    return false;
}


bool bishopAttacks(std::vector<std::string>& board,
                   int row, int col,
                   int kingRow, int kingCol) {

    for (int i = 1; i < 8; i++) {

        int newRow = row - i;
        int newCol = col + i;

        if (newRow < 0 || newCol >= 8) {
            break;
        }

        if (newRow == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[newRow][newCol] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newRow = row - i;
        int newCol = col - i;

        if (newRow < 0 || newCol < 0) {
            break;
        }

        if (newRow == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[newRow][newCol] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newRow = row + i;
        int newCol = col + i;

        if (newRow >= 8 || newCol >= 8) {
            break;
        }

        if (newRow == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[newRow][newCol] != '.') {
            break;
        }
    }

    for (int i = 1; i < 8; i++) {

        int newRow = row + i;
        int newCol = col - i;

        if (newRow >= 8 || newCol < 0) {
            break;
        }

        if (newRow == kingRow && newCol == kingCol) {
            return true;
        }

        if (board[newRow][newCol] != '.') {
            break;
        }
    }

    return false;
}


bool queenAttacks(std::vector<std::string>& board,
                  int row, int col,
                  int kingRow, int kingCol) {

    if (bishopAttacks(board, row, col, kingRow, kingCol)) {
        return true;
    }

    if (rookAttacks(board, row, col, kingRow, kingCol)) {
        return true;
    }

    return false;
}


bool kingAttacks(std::vector<std::string>& board,
                 int row, int col,
                 int kingRow, int kingCol) {

    int rowDifference = row - kingRow;

    if (rowDifference < 0) {
        rowDifference = -rowDifference;
    }

    int colDifference = col - kingCol;

    if (colDifference < 0) {
        colDifference = -colDifference;
    }

    return rowDifference <= 1 &&
           colDifference <= 1 &&
           !(rowDifference == 0 && colDifference == 0);
}


bool knightAttacks(std::vector<std::string>& board,
                   int row, int col,
                   int kingRow, int kingCol) {

    if (row - 2 == kingRow && col - 1 == kingCol) {
        return true;
    }

    if (row - 2 == kingRow && col + 1 == kingCol) {
        return true;
    }

    if (row + 2 == kingRow && col - 1 == kingCol) {
        return true;
    }

    if (row + 2 == kingRow && col + 1 == kingCol) {
        return true;
    }

    if (row - 1 == kingRow && col - 2 == kingCol) {
        return true;
    }

    if (row - 1 == kingRow && col + 2 == kingCol) {
        return true;
    }

    if (row + 1 == kingRow && col - 2 == kingCol) {
        return true;
    }

    if (row + 1 == kingRow && col + 2 == kingCol) {
        return true;
    }

    return false;
}


int main(int argc, char *argv[]) {

    int gameNum = 1;

    while (true) {

        std::vector<std::string> board(8);

        for (int i = 0; i < 8; i++) {

            char row[9];

            if (fscanf(stdin, "%8s", row) != 1) {
                return 0;
            }

            board[i] = row;
        }

        bool emptyBoard = true;

        for (int row = 0; row < 8; row++) {

            for (int col = 0; col < 8; col++) {

                if (board[row][col] != '.') {
                    emptyBoard = false;
                    break;
                }
            }

            if (!emptyBoard) {
                break;
            }
        }

        if (emptyBoard) {
            break;
        }

        int whiteKingRow = -1;
        int whiteKingCol = -1;

        int blackKingRow = -1;
        int blackKingCol = -1;

        for (int row = 0; row < 8; row++) {

            for (int col = 0; col < 8; col++) {

                if (board[row][col] == 'K') {
                    whiteKingRow = row;
                    whiteKingCol = col;
                }

                if (board[row][col] == 'k') {
                    blackKingRow = row;
                    blackKingCol = col;
                }
            }
        }

        bool whiteInCheck = false;
        bool blackInCheck = false;

        for (int row = 0; row < 8; row++) {

            for (int col = 0; col < 8; col++) {

                char piece = board[row][col];


                // ČERNÉ FIGURY -> kontrolují bílého krále
                if (piece == 'p') {

                    if (pawnAttacks(board, row, col,
                                    whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }

                else if (piece == 'r') {

                    if (rookAttacks(board, row, col,
                                    whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }

                else if (piece == 'b') {

                    if (bishopAttacks(board, row, col,
                                      whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }

                else if (piece == 'q') {

                    if (queenAttacks(board, row, col,
                                     whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }

                else if (piece == 'n') {

                    if (knightAttacks(board, row, col,
                                      whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }

                else if (piece == 'k') {

                    if (kingAttacks(board, row, col,
                                    whiteKingRow, whiteKingCol)) {
                        whiteInCheck = true;
                    }
                }


                // BÍLÉ FIGURY -> kontrolují černého krále
                else if (piece == 'P') {

                    if (pawnAttacks(board, row, col,
                                    blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }

                else if (piece == 'R') {

                    if (rookAttacks(board, row, col,
                                    blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }

                else if (piece == 'B') {

                    if (bishopAttacks(board, row, col,
                                      blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }

                else if (piece == 'Q') {

                    if (queenAttacks(board, row, col,
                                     blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }

                else if (piece == 'N') {

                    if (knightAttacks(board, row, col,
                                      blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }

                else if (piece == 'K') {

                    if (kingAttacks(board, row, col,
                                    blackKingRow, blackKingCol)) {
                        blackInCheck = true;
                    }
                }
            }
        }


        // Výstup
        if (whiteInCheck) {

            fprintf(stdout,
                    "Game #%d: white king is in check.\n",
                    gameNum);

        } else if (blackInCheck) {

            fprintf(stdout,
                    "Game #%d: black king is in check.\n",
                    gameNum);

        } else {

            fprintf(stdout,
                    "Game #%d: no king is in check.\n",
                    gameNum);
        }


        gameNum++;
    }


    return 0;
}