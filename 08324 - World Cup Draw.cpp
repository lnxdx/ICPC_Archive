// ITNOA
#include<bits/stdc++.h>
using namespace std;

string pots[5][9];
int UEFA_count[9], CONMEBOL_count[9], CONCACAF_count[9], CAF_count[9], AFC_count[9];
int UEFA_count_add[9], CONMEBOL_count_add[9], CONCACAF_count_add[9], CAF_count_add[9], AFC_count_add[9];
map<string, int>ran;
map<string, string>con;
pair<string, int> groups[9][5];
//vector<pair<string, int>> groups[9];

string teams[32] = { "Russia","Germany","Brazil","Portugal","Argentina","Belgium","Poland","France","Spain","Peru","Switzerland","England","Colombia","Mexico","Uruguay","Croatia","Denmark","Iceland","Costa Rica","Sweden","Tunisia","Egypt","Senegal","Iran","Serbia","Nigeria","Australia","Japan","Morocco","Panama","South Korea","Saudi Arabia" };
int ranks[32] = { 65,1,2,3,4,5,6,7,8,10,11,12,13,16,17,18,19,21,22,25,28,30,32,34,38,41,43,44,48,49,62,63 };
string cons[32] = { "UEFA","UEFA", "CONMEBOL", "UEFA", "CONMEBOL", "UEFA", "UEFA", "UEFA","UEFA","CONMEBOL","UEFA","UEFA","CONMEBOL","CONCACAF","CONMEBOL","UEFA","UEFA","UEFA","CONCACAF","UEFA","CAF","CAF","CAF","AFC","UEFA","CAF","AFC","AFC","CAF","CONCACAF","AFC","AFC" };

void init()
{
	for (int i = 0;i < 32;i++)
	{
		ran[teams[i]] = ranks[i];
		con[teams[i]] = cons[i];
	}
	for (int i = 0;i < 9;i++)
	{
		UEFA_count[i] = CONMEBOL_count[i] = CONCACAF_count[i] = CAF_count[i] = AFC_count[i] = 0;
		UEFA_count_add[i] = CONMEBOL_count_add[i] = CONCACAF_count_add[i] = CAF_count_add[i] = AFC_count_add[i] = 0;
	}
}

int main()
{
	string line;
	while (line != "End")
	{
		init();
		for (int i = 0;i<4;i++)
		{
			getline(cin, line, '\n');
			if (line == "End") return 0;
			int j = 0;
			string s = "";
			line += ',';
			for (int k = 0;k < line.size();k++)
			{
				if (line[k] == ',')
				{
					if (s.back() == ' ')	s.pop_back();
					if (s.front() == ' ')	s.erase(s.begin());
					pots[i][j++] = s;
					s = "";
					continue;
				}
				s += line[k];
			}
		}
		for (int i = 0;i < 4;i++)
		{
			int perm[8] = { 0,1,2,3,4,5,6,7 };
			do
			{
				int j;
				for (j = 0;j < 8;j++)
				{
					int k = perm[j];
					if (con[pots[i][j]] == "UEFA")
					{
						if (UEFA_count[k] == 2) break;
						UEFA_count[k]++;
						UEFA_count_add[k]++;
					}
					if (con[pots[i][j]] == "CONMEBOL")
					{
						if (CONMEBOL_count[k]) break;
						CONMEBOL_count[k]++;
						CONMEBOL_count_add[k]++;
					}
					if (con[pots[i][j]] == "CONCACAF")
					{
						if (CONCACAF_count[k]) break;
						CONCACAF_count[k]++;
						CONCACAF_count_add[k]++;
					}
					if (con[pots[i][j]] == "CAF")
					{
						if (CAF_count[k]) break;
						CAF_count[k]++;
						CAF_count_add[k]++;
					}
					if (con[pots[i][j]] == "AFC")
					{
						if (AFC_count[k]) break;
						AFC_count[k]++;
						AFC_count_add[k]++;
					}
					groups[k][i] = { pots[i][j],ran[pots[i][j]] };
				}
				if (j == 8)
				{
					for (int j = 0;j < 8;j++)
					{
						int k = perm[j];
						UEFA_count_add[k] = CONMEBOL_count_add[k] = CONCACAF_count_add[k] = CAF_count_add[k] = AFC_count_add[k] = 0;
					}
					break;
				}
				else
				{
					for (int j = 0;j < 8;j++)
					{
						int k = perm[j];
						UEFA_count[k] -= UEFA_count_add[k];
						CONMEBOL_count[k] -= CONMEBOL_count_add[k];
						CONCACAF_count[k] -= CONCACAF_count_add[k];
						CAF_count[k] -= CAF_count_add[k];
						AFC_count[k] -= AFC_count_add[k];
						UEFA_count_add[k] = CONMEBOL_count_add[k] = CONCACAF_count_add[k] = CAF_count_add[k] = AFC_count_add[k] = 0;
					}
				}
			} while (next_permutation(perm, perm + 8));
		}
		int total_sum = 0;
		pair<int, int>ans[8]; // {weight, index}
		for (int i = 0;i < 8;i++)
		{
			int sum = 0;
			for (int j = 0;j < 4;j++)
				sum += groups[i][j].second;
			ans[i] = { sum,i };
			total_sum += sum;
		}
		sort(ans, ans + 8);
		for (int i = 0;i < 8;i++)
			cout << char(ans[i].second + 'A') << ' ' << ans[i].first << "\n";
	}
}
