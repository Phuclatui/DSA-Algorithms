#include<iostream>
#include<vector>
#include<queue>
#include<Stack>
#include<fstream>
using namespace std;

vector<vector<int>> Vertex;
vector<bool> visited;
vector<int> parent;
int n, m, start, goal;

bool initData()
{
	ifstream f;
	f.open("BFS.txt");


	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m >> start >> goal;

	Vertex.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		f >> u >> v;
		Vertex[u].push_back(v);
	}
	f.close();

	visited.resize(n + 1, 0);
	parent.resize(n + 1, -1);
	return true;
}


void print_Path(const int &goal)
{
	stack<int>t;
	int idx = parent[goal];

	while (idx != -1)
	{
		t.push(idx);
		idx = parent[idx];
	}

	while(!t.empty())
	{
		cout << t.top() << " -> ";
		t.pop();
	}
	cout << goal;
}

void BFS()
{
	queue<int> q;

	q.push(start);
	visited[start] = 1;
	bool flag = false;

	while (!q.empty())
	{
		int r = q.front();
		q.pop();

		if (r == goal)
		{
			flag = true;
			break;
		}
		for (auto a : Vertex[r])
		{
			if ( visited[a] == 0)
			{
				q.push(a);
				visited[a] = 1;
				parent[a] = r;
			}
		}
	}

	if (flag)
		print_Path(goal);
	else
		cout << "Dont have path from " << start << " to " << goal << endl;
}




int main()
{
	if (!initData())
		return 0;

	BFS();
}