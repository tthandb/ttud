#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<int> g[N];
bool was[N]{};
int color[N];
bool ans = false;
void dfs(int u){
    was[u]=true;
    for(auto v:g[u]){
        if(!was[v]){
            color[v]=3-color[u];
            dfs(v);
        }
        else
            if(color[v]==color[u])
                ans=true;

    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <  m; ++i)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i< n;++i){
        if(!was[i+1]){
            color[i+1]=1;
            dfs(i+1);
        }

    }
    cout<<!ans;
    return 0;
}
