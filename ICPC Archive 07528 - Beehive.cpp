// ITNOG
// O(i.og(i) + #tests) Creative Ad Hoc by lnxdx, Mashhad, 2018
// Another solution is BFS.

#include<bits/stdc++.h>
using namespace std;
#define ll long  long
const int N = 1e4 + 4;
map<pair<int, int>, int>mp;
map<int, pair<int, int>>coord;

void model() {
	mp[{0, 0}] = 1;
	coord[1] = { 0,0 };
	int cur = 2; // we have created vertex 1
	int x, y;
	int dir[6][2] = { { 0,-2 },{ -1,-1 },{ -1,1 },{ 0,2 },{ 1,1 },{ 1,-1 } };
	for (int i = 1;i <= 1e4;i++) {
		int x, y;
		x = coord[i].first;
		y = coord[i].second;
		for (int d = 0;d < 6;d++) {
			int xx, yy;
			xx = x + dir[d][0];
			yy = y + dir[d][1];
			if (yy < 0 || mp.count({ xx,yy }))
				continue;
			mp[{xx, yy}] = cur;
			coord[cur] = { xx,yy };
			cur++;
		}
	}
}

int main()
{
	model();
	int u, v;
	while (~scanf("%d%d", &u, &v) && u)
	{
		int x1, x2, y1, y2;
		x1 = coord[u].first;
		x2 = coord[v].first;
		y1 = coord[u].second;
		y2 = coord[v].second;

		if (x1 == x2)
			printf("%d\n", abs(y1 - y2) / 2);
		else if (abs(x1 - x2) < abs(y1 - y2))
			printf("%d\n", abs(x1 - x2) + (abs(y1 - y2) - abs(x1 - x2)) / 2);
		else
			printf("%d\n", abs(x1 - x2));
	}
}
