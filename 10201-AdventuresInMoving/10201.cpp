
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAX_STATIONS = 105;
const int TANK = 200;
const long long INF = 1LL << 60;

struct Station {
    int distance;
    int price;
};

Station stations[MAX_STATIONS];

char line[256];

bool isBlank(const char *s) {
    while (*s != '\0') {
        if (*s != ' ' && *s != '\t' &&
            *s != '\r' && *s != '\n') {
            return false;
        }
        s++;
    }
    return true;
}

bool readNonBlankLine(char *buffer) {
    while (fgets(buffer, sizeof(line), stdin)) {
        if (!isBlank(buffer)) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;

    if (!readNonBlankLine(line)) {
        return 0;
    }

    sscanf(line, "%d", &T);

    for (int test = 0; test < T; test++) {
        int destination;

        if (!readNonBlankLine(line)) {
            break;
        }

        sscanf(line, "%d", &destination);

        int n = 0;

        while (fgets(line, sizeof(line), stdin)) {
            if (isBlank(line)) {
                break;
            }

            int d, p;

            if (sscanf(line, "%d %d", &d, &p) == 2) {
                stations[n].distance = d;
                stations[n].price = p;
                n++;
            }
        }

        sort(stations, stations + n,
             [](const Station &a, const Station &b) {
                 return a.distance < b.distance;
             });

        // dp[f] = minimal cost with f liters
        // at the current position, after refueling.
        long long dp[TANK + 1];
        long long nextDP[TANK + 1];

        for (int f = 0; f <= TANK; f++) {
            dp[f] = INF;
        }

        // The truck starts with half a tank for free.
        dp[100] = 0;

        int previousDistance = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            int d = stations[i].distance;
            int price = stations[i].price;
            int travel = d - previousDistance;

            // Drive to the station.
            for (int f = 0; f <= TANK; f++) {
                nextDP[f] = INF;
            }

            for (int fuel = travel; fuel <= TANK; fuel++) {
                if (dp[fuel] != INF) {
                    int remaining = fuel - travel;

                    if (dp[fuel] < nextDP[remaining]) {
                        nextDP[remaining] = dp[fuel];
                    }
                }
            }

            // Refuel at this station.
            for (int f = 0; f <= TANK; f++) {
                dp[f] = INF;
            }

            for (int fuel = 0; fuel <= TANK; fuel++) {
                if (nextDP[fuel] == INF) {
                    continue;
                }

                for (int target = fuel; target <= TANK; target++) {
                    long long cost =
                        nextDP[fuel] +
                        1LL * (target - fuel) * price;

                    if (cost < dp[target]) {
                        dp[target] = cost;
                    }
                }
            }

            previousDistance = d;
        }

        // Drive to the destination.
        int remainingDistance = destination - previousDistance;
        long long answer = INF;

        for (int fuel = 0; fuel <= TANK; fuel++) {
            if (fuel >= remainingDistance + 100 &&
                dp[fuel] < answer) {
                answer = dp[fuel];
            }
        }

        if (answer == INF) {
            printf("Impossible\n");
        } else {
            printf("%lld\n", answer);
        }

        if (test + 1 < T) {
            printf("\n");
        }
    }

    return 0;
}
