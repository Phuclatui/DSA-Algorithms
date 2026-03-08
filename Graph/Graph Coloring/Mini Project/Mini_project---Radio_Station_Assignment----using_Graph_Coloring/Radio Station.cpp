#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void dinh(int n)
{
	switch (n)
	{
	case 1: cout << "A"; break;
	case 2: cout << "B"; break;
	case 3: cout << "C"; break;
	case 4: cout << "D"; break;
	case 5: cout << "E"; break;
	case 6: cout << "F"; break;
	case 7: cout << "G"; break;
	case 8: cout << "H"; break;
	}
}


struct Vertex
{
	int id;
	int order;
};

vector<vector<int>> a
{
	{0,100,50,30,200,150,40,120},
	{0,0,30,80,120,50,200,150},
	{0,0,0,120,100,30,80,50},
	{0,0,0,0,50,120,150,30},
	{0,0,0,0,0,200,120,120},
	{0,0,0,0,0,0,180,150},
	{0,0,0,0,0,0,0,50},
	{0,0,0,0,0,0,0,0},
};

int n = a.size();
vector<Vertex> vertex(n);
vector<int> colorof(n, 0);

void initVertex()
{
	for (int i = 0; i < n; i++)
	{
		vertex[i].id = i;
		vertex[i].order = 0;
	}
}

void initData()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (a[i][j] >= 100 || a[j][i] >= 100)
				vertex[i].order++;
		}
	}
}

bool cancoloring(const int& id, const int& color)
{
	for (int k = 0; k < n; k++)
	{
		if (k == id) continue;

		bool near = (a[id][k] >= 100 || a[k][id] >= 100);
		if (near && colorof[k] == color)
			return false;
	}

	return true;
}

int coloring()
{
	sort(vertex.begin(), vertex.end(),
		[](Vertex v1, Vertex v2) {return v1.order > v2.order; });

	int count = 0;
	int color = 0;

	while (count < n)
	{
		color++;

		for (int i = 0; i < n; i++)
		{
			int id = vertex[i].id;
			if (colorof[id] == 0 && cancoloring(id, color))
			{
				colorof[id] = color;
				count++;
			}
		}
	}

	return color;
}



int main()
{
	initVertex();
	initData();

	int c = coloring();
	for (int i = 0; i < n; i++)
	{
		cout << "Vertex "; dinh(i + 1); cout << " color " << colorof[i] << endl;
	}cout << endl;



	const int t = 12;

	bool flag[t] = { false };


	for (int i = 0; i < n; i++)
	{
		int count = 1;
		if (flag[i])
			continue;
		cout << "Color " << colorof[i] << " : ";

		for (int j = 0; j < n; j++)
		{
			if (colorof[j] == colorof[i])
			{
				dinh(j + 1); cout << " ";
				flag[j] = true;
			}

		}cout << endl;
	}
}