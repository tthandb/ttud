#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
vector<int> a = {4, 8, 15, 16, 23, 42};
int b[4];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    for (int i = 0; i < 4; ++i)
    {
        cout << "? " << i + 1 << " " << i + 2 << endl;
        fflush(stdout);
        cin >> b[i];
    }
    int c = 0;
    do
    {
        c = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (a[i] * a[i + 1] == b[i])
                c++;
        }
        if (c == 4)
            break;
    } while (next_permutation(a.begin(), a.end()));
    cout << "! ";
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}