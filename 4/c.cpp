#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
int a[N];
bool r[N]{};
int main()
{
   ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
   int n, m, l = 0, r = 0;
   cin >> n >> m;
   for (int i = 0; i < n; ++i)
   {
      cin >> a[i];
      r = max(r, a[i]);
   }
   int mid;
   long long s;
   while (l < r - 1)
   {
      s = 0;
      mid = (l + r) / 2;
      for (int i = 0; i < n; ++i)
      {
         int tmp = a[i] - mid;
         if (tmp > 0)
            s += tmp;
      }
      if (s < m)
      {
         r = mid;
      }
      else
         l = mid;
   }
   cout << l;
   return 0;
}