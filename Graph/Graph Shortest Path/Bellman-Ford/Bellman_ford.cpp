#include<iostream>
#include<vector>
#include<climits>
#include<fstream>
#include<stack>
#include<iomanip>
using namespace std;

struct Edge
{
	int u, v, w;
};


vector<Edge> edge;
vector<int> parent;
vector<int> d;
int n, m, start;

bool initData()
{
	ifstream f;
	f.open("bellman_ford.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m >> start;

	edge.resize(m);

	for (int i = 0; i < m; i++)
		f >> edge[i].u >> edge[i].v >> edge[i].w;

	f.close();

	parent.resize(n + 1, -1);
	d.resize(n + 1, INT_MAX);
	d[start] = 0;
	return true;
}

bool bellman_ford()
{
	for (int i = 0; i < n - 1; i++)
	{
		bool update = false;

		for (const auto &a : edge)
		{
			if (d[a.u] != INT_MAX && d[a.v] > d[a.u] + a.w)
			{
				d[a.v] = d[a.u] + a.w;
				parent[a.v] = a.u;
				update = true;
			}
		}

		if (!update)
		{
			cout << "Early out at: " << i + 1 << endl;
			break;
		}
	}

	for (const auto& a : edge)
	{
		if (d[a.u] != INT_MAX && d[a.v] > d[a.u] + a.w)
		{
			cout << "Exist a negative cycle!!!!" << endl;
			return false;
		}
	}

	return true;
}

void path(const int& x)
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
	if (bellman_ford())
	{

		for (int i = 1; i <= n; i++)
			if (d[i] != INT_MAX)
			{
				cout << i << " Has a shortest path: " << right << setw(2) << d[i];
				cout << right << setw(7) << "|Path "; path(i);
				cout << endl;
			}
			else
			{
				cout << i << " No path" << endl;
			}
	}
	else
		cout << "Do not have a finite shortest path !!!!" << endl; // be careful!!! 
}