#include <bits/stdc++.h>
using namespace std;
int n;
char s[10000];
int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> s;
    bool add = true, check = true;
    for (int i = n - 1; i >= 0; --i)
    {
        if (add)
        {
            if (s[i] == '0')
            {
                s[i] = '1';
                add = false;
            }
            else
            {
                s[i] = '0';
                add = true;
            }
        }
        if (!i && add)
            check = false;
    }
    if (check)
        cout << s;
    else
        cout << "-1";
    return 0;
}