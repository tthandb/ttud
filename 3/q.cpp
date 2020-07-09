#include <bits/stdc++.h>
using namespace std;
int a[10005];

int main()
{
    int n, m, k, cnt = 0;
    cin >> n >> m >> k;
    memset(a, 0, sizeof(a));
    fill(a, a + m, 1);
    do
    {
        cnt++;
        if (cnt == k)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i])
                    cout << i + 1 << " ";
            }
            return 0;
        }
    } while (prev_permutation(a, a + n));
    cout << -1;
    return 0;
}