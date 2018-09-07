// ITNOG
// O(#tests + n) dp by lnxdx, Mashhad, 2018

#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 3;
int dp[N];

int main()
{
	dp[0] = dp[1] = 1;
	for (int i = 2;i <= 1000;i++)
	{
		if (i % 2 == 0)
			dp[i] = dp[i / 2] + dp[i - 2];
		else
			dp[i] = dp[i / 2] + dp[i - 3];
	}
	int t;
	scanf("%d", &t);
	int n, casi = 1;
	while (t--)
	{
		scanf("%d", &n);
		printf("%d %d\n", casi++, dp[n]);
	}
}
