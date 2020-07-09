#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int a[50], c[50];
int dp[50][N];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= b; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (a[i - 1] <= j)
                dp[i][j] = max(dp[i][j], c[i - 1] + dp[i - 1][j - a[i - 1]]);
        }
    cout << dp[n][b];
    return 0;
}