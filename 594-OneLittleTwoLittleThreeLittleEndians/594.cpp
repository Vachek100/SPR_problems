#include <vector>
#include <string>
#include <iostream>

int main(int argc, char *argv[]) {

    std::vector<std::string> board(8);

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            fscanf(stdin, "%c", &board[i][j]);
        }
    }

    for (int i = 0; i < 8; i++) {
        fprintf(stdout, "%s\n", board[i].c_str());
    }


    return 0;
}