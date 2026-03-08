#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Vertex
{
	int id;
	int order;
};

void subject(const int i)
{

	char name[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i' };
	cout << name[i];

}

vector<vector<int>> a
{
{0,0,1,1,0,0,1,0,0},
{0,0,0,1,1,0,0,0,0},
{1,0,0,1,0,1,0,0,0 },
{1,1,1,0,1,1,1,0,0},
{0,1,0,1,0,0,1,1,0},
{0,0,1,1,0,0,0,0,0},
{1,0,0,1,1,0,0,1,1},
{0,0,0,0,1,0,1,0,1},
{0,0,0,0,0,0,1,1,0},

};

int n = a.size();

vector<int> colorof(n, 0);
vector<Vertex> vertex(n);

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
			if (a[i][j] > 0)
				vertex[i].order++;
		}
	}
}

bool cancoloring(const int& id, const int& color)
{
	for (int k = 0; k < n; k++)
	{
		if (a[id][k] > 0 && colorof[k] == color)
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
	cout << "Sum of day: " << c << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "Topic "; subject(i); cout << " Day: " << colorof[i] << endl;
	}

}