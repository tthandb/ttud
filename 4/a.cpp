#include <bits/stdc++.h>
using namespace std;
int t, n, f;
const int N = 1e4 + 6;
const double E = 1e-7;
const float pi = atan(1) * 4;
float divide(double l, double r, int a[], int n)
{
    if (l + E >= r)
        return l;
    int cnt = 0;
    double m = (l + r) / 2;
    for (int i = 0; i < n; i++)
    {
        cnt += (int)floor(a[i] * a[i] / m);
    }
    if (cnt < f + 1)
        return divide(l, m, a, n);
    return divide(m, r, a, n);
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> t;
    while (t--)
    {
        cin >> n >> f;
        int a[N];
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        printf("%.6f\n", divide(0, 100000000, a, n) * pi);
    }
    return 0;
}