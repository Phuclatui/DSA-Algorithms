#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
using namespace std;

void name(const int& u)
{
	char name[]{ '0' ,'a', 'b', 'c','d', 'e', 'f','g', 'h', 'i' };
	cout << name[u];
}

struct Edge
{
	int u, v, w;
};

struct Node
{
	int u;
	int v;
	int w;
};

vector<vector<Edge>> edge;
vector<bool> visited;
int n, m, start;

bool initData()
{
	ifstream f;
	f.open("Prim.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}


	f >> n >> m >> start;

	edge.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		f >> u >> v >> w;
		edge[u].push_back({ u, v,w });
		edge[v].push_back({ v, u,w });
	}

	f.close();
	visited.resize(n + 1, false);

	return true;
}


vector<Edge> prim()
{
	vector<Edge> T;

	auto cmp = [](Node n1, Node n2) {return n1.w > n2.w; };

	priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);

	q.push({ 0, start, 0 });

	while (!q.empty())
	{
		int u = q.top().u;
		int v = q.top().v;
		int w = q.top().w;
		q.pop();

		if (visited[v] == false)
		{
			visited[v] = true;

			if (u != 0)
				T.push_back({ u,v,w });

			for (auto a : edge[v])
			{
				if (visited[a.v] == 0)
				{
					q.push({ v, a.v, a.w });
				}
			}
		}
	}
	return T;
}



int main()
{
	if (!initData())
		return 0;

	vector<Edge> result = prim();
	for (Edge i : result)
	{
		name(i.u); cout << " "; name(i.v); cout  << " " << i.w << " " << endl;
	}
}