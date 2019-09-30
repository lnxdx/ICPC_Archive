// ITNOG
// O(n^2) Bryte Force by lnxdx, Mashhad, 2018

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
const int N = 1e3 + 13;

int a[N];
PII b[N];
bool seen[N];

bool cmp(PII p, PII q) {
	if (p.first < q.first)
		return true;
	if(p.first==q.first)
		return p.second > q.second;
	return false;
}
bool sorted(int n) {
	vector<int>v;
	for (int i = 0;i < n;i++) {
		if (!seen[i])
			v.push_back(a[i]);
	}
	for (int i = 0;i < (int)v.size()-1;i++) {
		if (v[i] > v[i + 1])
			return false;
	}
	return true;
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(seen, 0, sizeof seen);

		int casi, n;
		cin >> casi >> n;

		for (int i = 0;i < n;i++) {
			cin >> a[i];
			b[i] = { a[i],i };
		}

		sort(b, b + n, cmp);

		int ans = 0;
		for (int i = n - 1;i >= 0;i--) {
			if (sorted(n)) {
				cout << casi << ' ' << ans << "\n";
				break;
			}
			seen[b[i].second] = true;
			ans++;
		}
	}
}
