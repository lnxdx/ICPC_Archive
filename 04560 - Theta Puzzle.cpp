// ITNOG
// O(BFS, 7!, BST, 7, :)) BFS by lnxdx, Mashhad, 2018

#include <bits/stdc++.h>
using namespace std;

map<string, int>dist;
set<string>seen;
vector<int>adj[7];
map<string, string>par;

void bfs(pair<string, int>src) {
	queue<pair<string, int>>q;
	q.push(src);
	seen.insert(src.first);
	par[src.first] = "-1";
	dist[src.first] = 0;
	while (q.size()) {
		pair<string, int>cur = q.front();
		q.pop();
		string p = cur.first;
		int u = cur.second;
		for (int i = 0;i < adj[u].size();i++) {
			int v = adj[u][i];
			string pp = p;
			swap(pp[u], pp[v]);
			if (seen.count(pp) == 0) {
				q.push({ pp,v });
				dist[pp] = dist[p] + 1;
				seen.insert(pp);
				par[pp] = p;
			}
		}
	}
}
void print(string p) {
	string pp = par[p];
	if (pp == "-1")
		return;
	int emp;
	for (int i = 0;i < p.size();i++) {
		if (p[i] == '-') {
			emp = i;
			break;
		}
	}
	printf("%c", pp[emp]);
	print(pp);
}
int main()
{
	adj[0].push_back(5);
	adj[0].push_back(1);
	adj[1].push_back(6);
	adj[1].push_back(2);
	adj[1].push_back(0);
	adj[2].push_back(3);
	adj[2].push_back(1);
	adj[3].push_back(4);
	adj[3].push_back(2);
	adj[4].push_back(6);
	adj[4].push_back(5);
	adj[4].push_back(3);
	adj[5].push_back(4);
	adj[5].push_back(0);
	adj[6].push_back(4);
	adj[6].push_back(1);

	bfs({ "ABCDEF-",6 });

	int t;
	scanf("%d", &t);
	while (t--) {
		int casi;
		string p;
		char temp[8];
		scanf("%d%s", &casi, &temp);
		p = temp;

		if (dist.count(p + "-") == 0)
			printf("%d NO SOLUTION\n", casi);
		else {
			printf("%d %d ", casi, dist[p + "-"]);
			print(p + "-");
			printf("\n");
		}
	}
}
