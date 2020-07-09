#include <bits/stdc++.h>
using namespace std;
int a[25][25];
bool was[11]{};
int cnt = 0;
int ans = INT_MAX, val = 0;
int n;

void solve(int cur)
{
    if (was[cur])
        return;
    was[cur] = true;
    cnt++;
    if (cnt == n)
        ans = min(ans, val + a[cur][cur + n] + a[cur + n][0]);
    else
        for (int i = 1; i <= n; ++i)
            if (!was[i] && i != cur && val + a[cur][cur + n] + a[cur + n][i] < ans)
            {
                val += a[cur][cur + n] + a[cur + n][i];
                solve(i);
                val -= a[cur][cur + n] + a[cur + n][i];
            }
    cnt--;
    was[cur] = false;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < 2 * n + 1; i++)
        for (int j = 0; j < 2 * n + 1; j++)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
    {
        val = a[0][i];
        solve(i);
    }
    cout << ans;
    return 0;
}