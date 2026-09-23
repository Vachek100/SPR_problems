#include <cstdio>
#include <vector>

using namespace std;

void printIndent(int depth) {
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
}

void generate(vector<char> sorted, vector<char> remaining, int depth) {
   
    if (remaining.empty()) {
        printIndent(depth);
        printf("writeln(");

        for (int i = 0; i < (int)sorted.size(); i++) {
            if (i > 0) {
                printf(",");
            }
            printf("%c", sorted[i]);
        }

        printf(")\n");
        return;
    }


    char x = remaining[0];

    vector<char> rest;
    for (int i = 1; i < (int)remaining.size(); i++) {
        rest.push_back(remaining[i]);
    }


    for (int i = 0; i <= (int)sorted.size(); i++) {

        if (i == (int)sorted.size()) {

            printIndent(depth);
            printf("if %c > %c then\n", x, sorted.back());

            vector<char> newSorted = sorted;
            newSorted.push_back(x);

            generate(newSorted, rest, depth + 1);
        } else {
            // x < sorted[i]
            printIndent(depth);
            printf("if %c < %c then\n", x, sorted[i]);

            vector<char> newSorted = sorted;
            newSorted.insert(newSorted.begin() + i, x);

            generate(newSorted, rest, depth + 1);
        }
    }
}

int main() {
    int M;
    scanf("%d", &M);

    for (int test = 0; test < M; test++) {
        int n;
        scanf("%d", &n);

        if (test > 0) {
            printf("\n");
        }


        printf("program sort(input,output);\n");
        printf("var\n");

        // Proměnné a,b,c,...
        for (int i = 0; i < n; i++) {
            printf("%c", 'a' + i);

            if (i + 1 < n) {
                printf(",");
            }
        }

        printf(" : integer;\n");
        printf("begin\n");

        printf("readln(");

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(",");
            }

            printf("%c", 'a' + i);
        }

        printf(");\n");


        vector<char> sorted;
        vector<char> remaining;

        sorted.push_back('a');

        for (int i = 1; i < n; i++) {
            remaining.push_back('a' + i);
        }

        if (n == 1) {
            printf("writeln(a)\n");
        } else {
            generate(sorted, remaining, 0);
        }

        printf("end.\n");
    }

    return 0;
}