#include <bits/stdc++.h>
using namespace std;
int n, m;
int dist[25][25];
int cnt = 0;
int ans = INT_MAX, val = 0;
bool was[25] = {false};
void track(int start, int cur)
{
    if (was[cur])
        return;
    was[cur] = true;
    cnt++;
    if (cnt == n && dist[cur][start])
        ans = min(ans, val + dist[cur][start]);
    else
        for (int i = 1; i <= n; ++i)
            if (!was[i] && dist[cur][i] && i != cur && val + dist[cur][i] < ans)
            {
                val += dist[cur][i];
                track(start, i);
                val -= dist[cur][i];
            }
    cnt--;
    was[cur] = false;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    memset(dist, 0, sizeof(dist));
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> dist[x][y];
    }
    track(1, 1);
    if (ans != INT_MAX)
        cout << ans;
    else
        cout << -1;
    return 0;
}