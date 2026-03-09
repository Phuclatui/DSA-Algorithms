#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

struct Edge
{
	int u, v, w;
};

vector<Edge> edge;
vector<int> parent;
vector<int> ranked;
int n, m;

bool initData()
{
	ifstream f;
	f.open("Kruskal.txt");


	if (!f.is_open())
	{
		cout << "the file is not founded!!!" << endl;
		return false;
	}
	f >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		f >> u >> v >> w;

		edge.push_back({ u,v,w });
	}

	parent.resize(n + 1, -1);
	ranked.resize(n + 1, 0);
	f.close();
}

int Getroot(int u)
{
	while (u != parent[u])
		u = parent[u];
	return u;
		
}

bool join(int u, int v)
{
	 u = Getroot(u);
	 v = Getroot(v);

	if (u != v)
	{
		if (ranked[u] == ranked[v])
			ranked[u]++;
		
		if (ranked[u] < ranked[v])
			parent[u] = v;
		else
			parent[v] = u;
		return true;
	}

	return false;
}

vector<Edge> kruskal()
{
	vector<Edge> T;

	sort(edge.begin(), edge.end(),
		[](Edge e1, Edge e2) {return e1.w < e2.w; });

	for (Edge a : edge)
	{
		if (join(a.u, a.v))
			T.push_back(a);
	}

	return T;
}



int main()
{
	initData();

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	vector<Edge> result = kruskal();

	for (const auto re : result)
	{
		cout << re.u <<" " << re.v << " " << re.w << endl;
	}

}