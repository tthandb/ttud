#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int n, m, a[120], dp[120][520];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    int k;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            k = 1;
            while (a[i] * k <= j)
            {
                (dp[i][j] += dp[i - 1][j - a[i] * k]) %= N;
                k++;
            }
        }
    }
    cout << dp[n][m] % N;
    return 0;
}