#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
#include <math.h>

using namespace std;

long long dp[1005][1005];
long long a[1005][3];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    for (int lap = 1; lap <= t; lap++)
    {
        int n, k;
        long long sum1, sum2, sum3;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= k; j++)
                dp[i][j] = -1e15;
        dp[0][0] = 0;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i][0] >> a[i][1] >> a[i][2];
            if (i == 1)
            {
                dp[i][1] = max(a[i][0], a[i][2]) + a[i][1];
                continue;
            }
            for (int j = 1; j <= min(k, i); j++)
            {
                dp[i][j] = dp[i - 1][j];
                dp[i][j] = max(dp[i][j], a[i][0] + a[i][1] + dp[i - 1][j - 1]);
                dp[i][j] = max(dp[i][j], a[i][2] + a[i][1] + dp[i - 1][j - 1]);
            }
            if (i > 1)
            {
                sum1 = a[i][0] + a[i - 1][0];
                sum2 = a[i][1] + a[i - 1][1];
                sum3 = a[i][2] + a[i - 1][2];
                for (int j = 1; j <= min(k, i); j++)
                {
                    if (i > 2)
                        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 2][j]));
                    if (j >= 3)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + sum3 + dp[i - 2][j - 3]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum3 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum2 + sum3 + dp[i - 2][j - 2]);
                    dp[i][j] = max(dp[i][j], sum1 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum2 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum3 + dp[i - 2][j - 1]);
                }
                sum1 = a[i][0] + a[i - 1][0];
                sum2 = a[i][1] + a[i][2];
                sum3 = a[i - 1][1] + a[i - 1][2];
                for (int j = 1; j <= min(k, i); j++)
                {
                    if (i > 2)
                        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 2][j]));
                    if (j >= 3)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + sum3 + dp[i - 2][j - 3]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum3 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum2 + sum3 + dp[i - 2][j - 2]);
                    dp[i][j] = max(dp[i][j], sum1 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum2 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum3 + dp[i - 2][j - 1]);
                }
                sum1 = a[i - 1][0] + a[i - 1][1];
                sum2 = a[i][0] + a[i][1];
                sum3 = a[i][2] + a[i - 1][2];
                for (int j = 1; j <= min(k, i); j++)
                {
                    if (i > 2)
                        dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i - 2][j]));
                    if (j >= 3)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + sum3 + dp[i - 2][j - 3]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum3 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum1 + sum2 + dp[i - 2][j - 2]);
                    if (j >= 2)
                        dp[i][j] = max(dp[i][j], sum2 + sum3 + dp[i - 2][j - 2]);
                    dp[i][j] = max(dp[i][j], sum1 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum2 + dp[i - 2][j - 1]);
                    dp[i][j] = max(dp[i][j], sum3 + dp[i - 2][j - 1]);
                }
            }
        }
        cout << dp[n][k];
    }
}
