#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;

struct Node
{
	int id;
	int degree;
};

vector<Node> order;	
vector<vector<int>> vertex;
vector<int> corlored;
int n, m;

bool initData()
{
	ifstream f;
	f.open("color.txt");

	if (!f.is_open())
	{
		cout << "The file is not founded!!!" << endl;
		return false;
	}

	f >> n >> m;
	vertex.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int v, u;
		f >> u >> v;

		vertex[u].push_back({ v});
		vertex[v].push_back({ u });
	}

	f.close();

	for (int i = 1; i <= n; i++)
	{
		order.push_back(Node{ i, (int) vertex[i].size() });
	}

	corlored.resize(n + 1, 0);
	return true;
}


bool cancoloring(const int id, const int color )
{
	for (int k:	vertex[id])
	{
		if (corlored[k] == color)
			return false;
	}

	return true;
}

void coloring()
{
	sort(order.begin(), order.end(),
		[](Node n1, Node n2) {return n1.degree > n2.degree; });

	int count = 0; 
	int color = 0;

	while (count < n)
	{
		color++;

		for (int i = 0; i < n; i++)
		{
			int id = order[i].id;
			if (corlored[id] == 0 && cancoloring(id, color))
			{
				corlored[id] = color;
				count++;
			}
		}
	}
}

int main()
{
	if (!initData())
		return 0;

	coloring();

	for (int i = 0; i < n; i++)
	{
		cout << "Vertex " << i << " color: " << corlored[i] << endl;
	}
}