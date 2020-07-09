#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 6;
int a[N], b[N], dp[N][N], n, m;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; ++j)
    {
        cin >> b[j];
    }
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (a[i] == b[j])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    cout << dp[n][m];
    return 0;
}