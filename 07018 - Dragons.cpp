// ITNOG
// O(n^2) Greedy by lnxdx, Mashhad, 2018

#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 300 + 10;
int INF = 1e9;

struct CC
{
	int s, n;
	CC(int s, int n) :s(s), n(n) {};
	CC() :s(0), n(0) {};
};

bool adj[N][N];
int color[N];
vector<CC>cc[N];
vector<int>pmax[N]; // prefix max
vector<int>ssum[N]; // suffix sum
int n, m, k;
int cc_count, label;

void dfs(int u) // Graph part is here.
{
	color[u] = label;
	for (int v = 0;v < n;v++)
		if (adj[u][v] && color[v] == -1)
			dfs(v);
}
bool cmp(CC a, CC b) { return a.n < b.n; }
int main()
{
	while (~scanf("%d%d%d", &n, &m, &k) && (n || m || k))
	{
		memset(color, -1, sizeof color);
		memset(adj, 0, sizeof adj);
		for (int i = 0;i < n;i++)
		{
			cc[i].clear();
			pmax[i].clear();
			ssum[i].clear();
		}

		for (int i = 0;i < m;i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			u--, v--;
			adj[u][v] = adj[v][u] = true;
		}

		cc_count = 0;
		label = 0;
		for (int i = 0;i < n;i++)
			if (color[i] == -1)
			{
				dfs(i);
				label++;
				cc_count++;
			}

		for (int i = 0;i < k;i++)
		{
			int c, s, n;
			scanf("%d%d%d", &c, &s, &n);
			c--;
			cc[color[c]].push_back(CC(s, n));
		}

		ll ans = 0;
		for (int i = 0;i < cc_count;i++)
		{
			if (cc[i].size() == 0)
				continue;
			sort(cc[i].begin(), cc[i].end(), cmp);
			pmax[i].assign(cc[i].size(), 0);
			ssum[i].assign(cc[i].size(), 0);
			pmax[i].front() = cc[i].front().n;
			ssum[i].back() = cc[i].back().s;

			// DP part here :D			
			for (int j = 1;j < pmax[i].size();j++)
				pmax[i][j] = max(pmax[i][j - 1], cc[i][j].n);
			for (int j = (int)ssum[i].size() - 2;j >= 0;j--)
				ssum[i][j] = ssum[i][j + 1] + cc[i][j].s;

			// Brute Force part here :)
			ll min_war = INF;
			for (int j = 0;j < (int)cc[i].size() - 1;j++)
			{
				// Greedy part here :|
				min_war = min(min_war, (ll)max(pmax[i][j] + 1, ssum[i][j + 1]));
			}

			min_war = min(min_war, (ll)(pmax[i].back() + 1));
			min_war = min(min_war, (ll)(ssum[i].front()));
			ans += min_war;
		}

		printf("%lld\n", ans);

	}
}
