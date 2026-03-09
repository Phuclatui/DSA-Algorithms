#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

struct Edge
{
	int u, v, w;
};

vector<Edge> edge;
vector<bool> visited;
int n, m;

bool initData()
{
	ifstream f;
	f.open("prim.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m;
	edge.resize(m);

	for (int i = 0; i < m; i++)
		f >> edge[i].u >> edge[i].v >> edge[i].w;
	
	f.close();

	visited.resize(n + 1, false);
	return true;
}

vector<Edge> Prim()
{
	vector<Edge> T;
	visited[1] = true;

	while (T.size() < n - 1)
	{
		Edge best = { 0,0,0 };
		int min = 1e9;

		for (auto a : edge)
		{
			if (visited[a.u] && !visited[a.v] && a.w < min)
			{
				min = a.w;
				best = a;
			}

			if (visited[a.v] && !visited[a.u] && a.w < min)
			{
				min = a.w;
				best = {a.v,a.u,a.w};
			}
		}

		if (min == 1e9)
		{
			cout << "The graph is not connected!!!" << endl;
			break;
		}
		T.push_back(best);
		visited[best.v] = true;
	}

	return T;
}



int main()
{
	if (!initData())
		return 0;

	vector<Edge> result = Prim();

	for (Edge a : result)
	{
		cout << a.u << " " << a.v << " " << a.w << endl;
	}
}