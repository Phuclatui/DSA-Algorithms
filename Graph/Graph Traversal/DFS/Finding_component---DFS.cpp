#include<iostream>
#include<vector>
#include<stack>
#include<fstream>
using namespace std;

vector<vector<int>> vertex;
vector<int> Labels;
vector<int> parent;
int n, m;

bool initData()
{
	ifstream f;
	f.open("DFS.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m;

	vertex.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int u, v;
		f >> u >> v;
		vertex[u].push_back(v);
		vertex[v].push_back(u);
	}

	f.close();

	Labels.resize(n + 1, 0);
	parent.resize(n + 1, -1);

	return true;
}


void DFS(const int& i, const int& label)
{
	
	stack<int> q;
	q.push(i);
	Labels[i] = label;

	cout << "Component " << label << " : ";
	while (!q.empty())
	{
		int u = q.top();
		cout << u << " ";
		q.pop();

		for (const auto &a : vertex[u])
		{
			if (Labels[a] == 0)
			{
				q.push(a);
				Labels[a] = label;
			}
		}
	}
}



int main()
{
	if (!initData())
		return 0;
	
	int label = 0;

	for (int i = 1; i <= n; i++)
		if (Labels[i] == 0)
		{
			label++;
			DFS(i, label);
			cout << endl;
		}



}