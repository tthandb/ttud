#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool was[N]{};
void dfs(int u)
{
    was[u] = true;
    for (auto v : g[u])
    {
        if (!was[v])
        {
            was[v] = true;
            dfs(v);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int cnt = 0;
    for (int i = 0; i < n; ++i)
    {
        if (!was[i + 1])
        {
            cnt++;
            dfs(i + 1);
        }
    }
    cout << cnt;
    return 0;
}
