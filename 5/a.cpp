#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 6;
long long a[N], dp[N];
priority_queue<pair<int, int>> q;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, l1, l2;
    cin >> n >> l1 >> l2;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i)
        dp[i] = a[i];
    for (int i = l1; i < n; ++i)
    {
        for (int j = l2; j >= l1; --j)
        {
            if (i - j >= 0)
            {
                dp[i] = max(dp[i], dp[i - j] + a[i]);
            }
        }
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
