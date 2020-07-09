#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> a, int n)
{
    int ans = a[0] * 100 + a[1] * 10 + a[2] - (a[3] * 100 + 62) + a[4] * 1000 + a[5] * 100 + a[6] * 10 + a[2];
    return (ans == n);
}
int find(int n)
{
    int cnt = 0;
    vector<int> d(9);
    iota(d.begin(), d.end(), 1);
    do
    {
        if (check(d, n))
            cnt++;
        reverse(d.begin() + 7, d.end());
    } while (next_permutation(d.begin(), d.end()));
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    cout << find(n);

    return 0;
}