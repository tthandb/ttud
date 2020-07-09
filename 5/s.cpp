#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int n, m, a[N], dp[N][23];
vector<pair<int, int>> p;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        p.push_back({x, y});
    }
    for (int i = 1; i <= n; i++)
        dp[i][0] = a[i];
    for (int k = 1; 1 << k <= n; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            dp[i][k] = min(dp[i][k - 1], dp[i + (1 << (k - 1))][k - 1]);
    long long ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int u = p[i].first + 1, v = p[i].second + 1;
        int k = log2(v - u + 1);
        ans += min(dp[u][k], dp[v - (1 << k) + 1][k]);
    }
    cout << ans;
    return 0;
}