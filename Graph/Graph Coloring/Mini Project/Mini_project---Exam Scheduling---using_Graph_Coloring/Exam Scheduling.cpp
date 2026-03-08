#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void subject(int i)
{
	char name[]{ 'A','B','C','D','E','F','G','H','I' };
	cout << name[i];
}


vector<vector<int>> a
{
	{0,1,1,0,1,0,0,0,0},
	{1,0,1,1,0,0,0,1,1},
	{1,1,0,1,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0},
	{1,0,0,0,0,1,1,0,1},
	{0,0,0,0,1,0,1,0,0},
	{0,0,0,0,1,1,0,1,1},
	{0,1,0,0,0,0,1,0,1},
	{0,1,0,0,1,0,1,1,0},
};

struct Vertex
{
	int id;
	int order;
};

int n = a.size();

vector<Vertex>vertex(n);
vector<int>colorof(n, 0);

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

bool cancoloring(const int id, const int color)
{
	for (int k = 0; k < n; k++)
	{
		if (a[id][k] > 0 && colorof[k] == color)
			return false;
	}

	return true;
}

int coloring( )
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
	cout << "Need " << c << " Day!!!" << endl;

	for (int i = 0; i < n; i++)
	{
		int id = vertex[i].id;
		cout << "Subject "; subject(id);  cout << " Day: " << colorof[id] << endl;
	}cout << endl;

	vector<bool>flag (n, false);

	for (int i = 0; i < n; i++)
	{
		if (flag[i])
			continue;

		cout << "Day " << colorof[i] << ": Subject ";
		for (int j = 0; j < n; j++)
		{
			if (colorof[i] == colorof[j])
			{
				subject(j); cout << " ";
				flag[j] = true;
			}
		} cout << endl;
	}

}