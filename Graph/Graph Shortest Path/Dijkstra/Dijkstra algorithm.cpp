#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<fstream>
#include<stack>
#include<iomanip>
using namespace std;

struct Edge
{
	int u, v, w;
};

struct Node
{
	int u, w;
};

vector<vector<Edge>> edge;
vector<int> parent;
vector<bool> visited;
vector<int> d;
int n, m, start;

bool initData()
{
	ifstream f;
	f.open("dijsktra.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m >> start;

	edge.resize(n + 1);

	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		f >> u >> v >> w;

		edge[u].push_back({ u,v,w });
		edge[v].push_back({ v,u,w });
	}

	f.close();

	parent.resize(n + 1, -1);
	visited.resize(n + 1, false);
	d.resize(n + 1, INT_MAX);
	d[start] = 0;
	return true;
}

void dijkstra()
{
	auto cmp = [](Node u1, Node u2) {return u1.w > u2.w; };

	priority_queue<Node, vector<Node>, decltype(cmp)> q(cmp);

	q.push({ start, d[start] });

	while (!q.empty())
	{
		int u = q.top().u;
		q.pop();

		if (visited[u] == false)
		{
			visited[u] = true;

			for (const auto& a : edge[u])
			{
				int v = a.v;

				if (visited[v] == false && d[v] > d[u] + a.w)
				{
					d[v] = d[u] + a.w;
					parent[v] = u;
					q.push({ v, d[v] });
				}
			}

		}
	}
}


void PrintPath(const int& x)
{
	stack<int> t;
	int idx = parent[x];

	while (idx != -1)
	{
		t.push(idx);
		idx = parent[idx];
	}

	while (!t.empty())
	{
		cout << t.top() << " -> ";
		t.pop();
	}
	cout << x;
}



int main()
{
	if (!initData())
		return 0;

	dijkstra();

	for (int i = 1; i <= n; i++)
		if (d[i] != INT_MAX)
		{
			cout << i << " has a shortest path from " << start << " is: " << left << setw(5) << d[i];
			cout << left << setw(5) << "| Path: ";  PrintPath(i);
			cout << endl;
		}
		else
			cout << i << "dont have path from " << start << endl;
}