#include <bits/stdc++.h>
using namespace std;
int a[25][25];
bool was[11]{};
int cnt = 0, ans = INT_MAX, val = 0, n, k, c_min = INT_MAX, x[15];
void solve(int cur, int as)
{
    if (cnt == 2 * n)
        ans = min(ans, val + a[cur][0]);
    else
        for (int i = 1; i <= n; i++)
        {
            cnt++;
            if (x[i] == 0 && as > 0 && val + a[cur][i] + c_min * (2 * n - cnt - 1) < ans)
            {
                x[i]++;
                val += a[cur][i];
                solve(i, as - 1);
                val -= a[cur][i];
                x[i]--;
            }
            else if (x[i] == 1 && val + a[cur][i + n] + c_min * (2 * n - cnt - 1) < ans)
            {
                x[i]++;
                val += a[cur][i + n];
                solve(i + n, as + 1);
                val -= a[cur][i + n];
                x[i]--;
            }
            cnt--;
        }
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    memset(x, 0, sizeof(x));
    for (int i = 0; i < 2 * n + 1; i++)
        for (int j = 0; j < 2 * n + 1; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                c_min = min(c_min, a[i][j]);
        }
    solve(0, k);
    cout << ans;
    return 0;
}