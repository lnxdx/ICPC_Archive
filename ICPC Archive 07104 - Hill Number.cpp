// ITNOG
// O(400.log(n)) dp by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
const int N = 72;

unsigned long long dp[N][2][2][11];
char n[72];

void init()
{
	memset(dp, 0, sizeof dp);

	// y < n[0]
	for (int y = 0;y < n[0];y++)
		dp[0][0][1][y] = 1;

	// y == n[0]
	dp[0][0][0][n[0]] = 1;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		//n[0] = '0';
		scanf("%s", n + 0);
		int size = strlen(n);

		for (int i = 0;i < size;i++)
			n[i] -= '0';
		init();

		for (int i = 0;i < size - 1;i++)
		{
			for (int x = 0;x < 10;x++)
			{
				// y < n[i + 1]
				for (int y = 0;y < n[i + 1];y++)
				{
					if (y > x) // increasing. no prev peak.
					{
						dp[i + 1][0][1][y] += dp[i][0][0][x];
						dp[i + 1][0][1][y] += dp[i][0][1][x];
					}
					else if (y == x)
					{
						dp[i + 1][0][1][y] += dp[i][0][0][x];
						dp[i + 1][0][1][y] += dp[i][0][1][x];
						dp[i + 1][1][1][y] += dp[i][1][0][x];
						dp[i + 1][1][1][y] += dp[i][1][1][x];
					}
					else // decreasing. maybe prev peak.
					{
						dp[i + 1][1][1][y] += dp[i][0][0][x];
						dp[i + 1][1][1][y] += dp[i][0][1][x];
						dp[i + 1][1][1][y] += dp[i][1][0][x];
						dp[i + 1][1][1][y] += dp[i][1][1][x];
					}
				}

				// y == n[i + 1]
				int y = n[i + 1];
				if (y > x)
				{
					dp[i + 1][0][0][y] += dp[i][0][0][x];
					dp[i + 1][0][1][y] += dp[i][0][1][x];
				}
				else if (y == x)
				{
					dp[i + 1][0][0][y] += dp[i][0][0][x];
					dp[i + 1][0][1][y] += dp[i][0][1][x];
					dp[i + 1][1][0][y] += dp[i][1][0][x];
					dp[i + 1][1][1][y] += dp[i][1][1][x];
				}
				else
				{
					dp[i + 1][1][0][y] += dp[i][0][0][x];
					dp[i + 1][1][1][y] += dp[i][0][1][x];
					dp[i + 1][1][0][y] += dp[i][1][0][x];
					dp[i + 1][1][1][y] += dp[i][1][1][x];
				}

				// y > n[i + 1]
				for (int y = n[i + 1] + 1;y < 10;y++)
				{
					if (y > x)
					{
						dp[i + 1][0][1][y] += dp[i][0][1][x];
					}
					else if (y == x)
					{
						dp[i + 1][0][1][y] += dp[i][0][1][x];
						dp[i + 1][1][1][y] += dp[i][1][1][x];
					}
					else
					{
						dp[i + 1][1][1][y] += dp[i][0][1][x];
						dp[i + 1][1][1][y] += dp[i][1][1][x];
					}
				}
			}
		}
		unsigned long long ans = 0;
		for (int peak = 0;peak<2;peak++)
			for (int less_than = 0;less_than<2;less_than++)
				for (int y = 0;y<10;y++)
					ans += dp[size - 1][peak][less_than][y];

		if (dp[size - 1][0][0][n[size - 1]] || dp[size - 1][1][0][n[size - 1]])
			printf("%lld\n", ans - 1);
		else
			printf("-1\n");
	}
}
