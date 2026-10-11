
#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int t = 0; t < N; t++) {
        int M;
        cin >> M;

        string a = "";
        string b = "";

        for (int i = 0; i < M; i++) {
            int x, y;
            cin >> x >> y;

            a += char(x + '0');
            b += char(y + '0');
        }

        string result = "";
        int carry = 0;

        for (int i = M - 1; i >= 0; i--) {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;

            result += char(sum % 10 + '0');
            carry = sum / 10;
        }

        if (carry > 0) {
            result += char(carry + '0');
        }

        for (int i = result.size() - 1; i >= 0; i--) {
            cout << result[i];
        }

        cout << '\n';

        if (t < N - 1) {
            cout << '\n';
        }
    }

    return 0;
}
