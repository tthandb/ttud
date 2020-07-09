#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n, a[N], dp[N];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        dp[i] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j < i; ++j)
            if (a[i] > a[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}