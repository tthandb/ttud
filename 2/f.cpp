#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 6;
int a[N], pm[N], sm[N];
int main()
{
    int n, b;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pm[0] = a[0];
    for (int i = 1; i < n; i++)
    {
        pm[i] = max(pm[i - 1], a[i]);
    }
    sm[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        sm[i] = max(sm[i + 1], a[i]);
    }
    int ans = -1;
    for (int i = 1; i < n - 1; i++)
    {
        int ml = pm[i - 1];
        int mr = sm[i + 1];
        if (ml - a[i] >= b && mr - a[i] >= b)
            ans = max(ans, ml + mr - 2 * a[i]);
    }
    cout << ans;
    return 0;
}
