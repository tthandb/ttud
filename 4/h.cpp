#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 6;
int l, a[N], n;
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> l;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    int tmp = 2 * max(a[0], l - a[n - 1]);
    for (int i = 0; i < n - 1; ++i)
        tmp = max(tmp, a[i + 1] - a[i]);
    float ans = tmp;
    printf("%.10f", ans / 2);
    return 0;
}