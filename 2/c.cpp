#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 6;
int dist[2000][2000];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, l, c;
    cin >> t;
    while (t--)
    {
        cin >> l >> c;
        int cnt = -1;
        int tmp;
        int x1[N], y1[N];
        int x2[N], y2[N];
        memset(dist, 0, sizeof dist);
        int lengthx = 0, lengthy = 0;
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> tmp;
                if (tmp == 1)
                {
                    cnt++;
                    x1[cnt] = i;
                    y1[cnt] = j;
                }
            }
        lengthx = cnt;
        cnt = -1;
        for (int i = l; i < 2 * l; i++)
            for (int j = 0; j < c; j++)
            {
                cin >> tmp;
                if (tmp == 1)
                {
                    cnt++;
                    x2[cnt] = i - l;
                    y2[cnt] = j;
                }
            }
        lengthy = cnt;
        for (int i = 0; i <= lengthx; i++)
            for (int j = 0; j <= lengthy; j++)
                dist[1000 + x2[j] - x1[i]][1000 + y2[j] - y1[i]]++;
        int count = 0;
        int maxCount = 0;
        for (int i = 0; i <= lengthx; i++)
            for (int j = 0; j <= lengthy; j++)
                maxCount = max(maxCount, dist[1000 + x2[j] - x1[i]][1000 + y2[j] - y1[i]]);
        cout << maxCount << endl;
    }
    return 0;
}