#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, q, c, p;
    int a[100006];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i + 1])
            ans++;
    }
    cin >> q;
    while (q--)
    {
        cin >> p >> c;
        int bef = 0, af = 0;
        if (n != 1)
            if (p == 1)
            {
                if (a[p] != a[p + 1])
                    bef++;
                if (c != a[p + 1])
                    af++;
                ans = ans + af - bef;
            }
            else if (p == n)
            {
                if (a[p] != a[p - 1])
                    bef++;
                if (c != a[p - 1])
                    af++;
                ans += af - bef;
            }
            else
            {
                if (a[p] != a[p - 1])
                    bef++;
                if (a[p] != a[p + 1])
                    bef++;
                if (c != a[p + 1])
                    af++;
                if (c != a[p - 1])
                    af++;
                ans += af - bef;
            }
        a[p] = c;
        cout << ans << endl;
    }
    return 0;
}