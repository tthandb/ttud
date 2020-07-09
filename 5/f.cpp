#include <bits/stdc++.h>
using namespace std;
const int N = 1e9 + 7;
int dp[2][1010];
int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, k1, k2;
	cin >> n >> k1 >> k2;
	dp[0][0] = 1;
	dp[1][0] = 1;
	dp[0][1] = 1;
	for (int i = 1; i <= k1 - 1; ++i)
	{
		dp[1][i] = 0;
		dp[0][i + 1] = dp[1][i];
	}
	dp[1][k1] = 1;
	for (int i = k1 + 1; i <= n; i++)
	{
		dp[0][i] = dp[1][i - 1];
		dp[1][i] = 0;
		for (int k = max(0, i - k2); k <= i - k1; ++k)
			(dp[1][i] += dp[0][k]) %= N;
	}
	cout << (dp[0][n] + dp[1][n]);
	return 0;
}