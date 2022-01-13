#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int x1, y3, x2, y2;
int answer;
int map[1025][1025];
int dp[1025][1025];

int main(int argc, char** argv) {

    scanf("%d", &N);
    scanf("%d", &M);

    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            scanf("%d", &map[i][j]);
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + map[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        scanf("%d", &x1);
        scanf("%d", &y3);
        scanf("%d", &x2);
        scanf("%d", &y2);
        answer = dp[x2][y2] - dp[x2][y3 - 1] - dp[x1 - 1][y2] + dp[x1 - 1][y3 - 1];
        printf("%d\n", answer);
    }
    return 0;
}
