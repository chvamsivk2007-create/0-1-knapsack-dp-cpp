#include <iostream>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    int wt[100], val[100];
    for (int i = 0; i < n; i++) {
        cin >> wt[i] >> val[i];
    }
    int dp[101][101] = {0};
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                int include = val[i - 1] + dp[i - 1][w - wt[i - 1]];
                int exclude = dp[i - 1][w];
                if (include >= exclude)
                    dp[i][w] = include;
                else
                    dp[i][w] = exclude;
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    cout << dp[n][W];
    return 0;
}
