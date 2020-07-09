#include <bits/stdc++.h>
using namespace std;
int solve(int a, int b, int c)
{
    int cnt = 0;
    int xq = 0, yq = 0;
    int t;
    while (xq != c && yq != c)
    {
        if (xq == 0)
        {
            xq = a;
            cnt++;
        }
        else if (yq == b)
        {
            yq = 0;
            cnt++;
        }
        else
        {
            t = min(b - yq, xq);
            yq = yq + t;
            xq = xq - t;
            cnt++;
        }
    }
    return cnt;
}
int main()
{
    int a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    if (c < a || c < b)
        if (c % (__gcd(a, b)) == 0)
            cout << min(solve(a, b, c), solve(b, a, c));
        else
            cout << -1;
    else
        cout << -1;
    return 0;
}