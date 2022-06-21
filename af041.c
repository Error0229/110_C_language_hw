#include <stdio.h>
#include <string.h>
#define min(x, y) ((x < y) ? (x) : (y))
#define inf 1000000009
int solve(int a[15][15], int start, int n)
{
    int dp[32768][15], i, j, k, ans = inf;
    memset(dp, 0, sizeof(dp));

    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            dp[i][j] = inf;
        }
    }
    dp[1 << start][start] = 0;
    for (i = 0; i < (1 << n); i++) {
        for (j = 0; j < n; j++) {
            if (i & (1 << j)) {
                for (k = 0; k < n; k++) {
                    if ((i & (1 << k)) && j != k)
                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + a[k][j]);
                }
            }
        }
    }
    for (i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i] + a[i][start]);
    return ans;
}
int main()
{
    int graph[15][15], N, i, ans = 1e9;
    scanf("%d", &N);
    for (i = 0; i < N * N; i++) {
        scanf("%d", &graph[i / N][i % N]);
    }
    for (i = 0; i < N; i++)
        ans = min(ans, solve(graph, i, N));
    printf("%d\n", ans);
}