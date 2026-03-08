#include<iostream>
#include<vector>
using namespace std;

struct Vertex
{
	int team1;
	int team2;
};


void match(vector<Vertex> vertex, const int &i)
{
	char name [] = {'A','B','C','D','E','F'};

	cout << name[vertex[i].team1] << name[vertex[i].team2];
}

vector<vector<int>> a
{
	{0,-1,1,1,-1,1},
	{-1,0,1,1,1,-1},
	{-1,-1,0,-1,1,-1},
	{-1,-1,-1,0,1,1},
	{-1,-1,-1,-1,0,1},
	{-1,-1,-1,-1,-1,0},
};

int n = a.size();
vector<Vertex> vertex;


void initData()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i][j] > 0 || a[j][i] > 0)
				vertex.push_back({ i,j });

		}
	}
}

bool cancoloring(vector<int>colorof, const int& m, const int& color, const int &i)
{
	for (int k = 0; k < m; k++)
	{
		bool conflict = vertex[i].team1 == vertex[k].team1 ||
			vertex[i].team1 == vertex[k].team2 ||
			vertex[i].team2 == vertex[k].team1 ||
			vertex[i].team2 == vertex[k].team2;

		if (conflict && colorof[k] == color)
			return false;
	}

	return true;
}

void coloring()
{
	int m = vertex.size();
	vector<int>colorof(m, 0);
	int count = 0;
	int color = 0;


	while (count < m)
	{
		color++; 

		for (int i = 0; i < m; i++)
		{
			if (colorof[i] == 0 && cancoloring(colorof, m, color, i))
			{
				colorof[i] = color;
				count ++;
			}
		}
	}

	


}


int main()
{
	initData();
	coloring();

	for (int i = 0; i < m; i++)
	{
		cout << "Dinh "; match(vertex, i); cout << " mau " << colorof[i] << endl;
	}

}