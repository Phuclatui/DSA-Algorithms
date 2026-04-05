#include<iostream>
#include<ctime>
#define MAX 1000
using namespace std;

void addArray(int array[])
{
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % MAX;
	}
}

void showArray(const int array[])
{
	for (int i = 0; i < MAX; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


void CountingSort(int a[], const int& n, const int& k)
{
	int* c = new int[k + 1];
	for (int i = 0; i <= k; i++)
		c[i] = 0;
	for (int i = 0; i < n; i++)
		c[a[i]]++;

	int start = 0;
	for (int i = 0; i <= k; i++)
	{
		for (int j = start; j < start + c[i]; j++)
			a[j] = i;
		start += c[i];
	}
}

int main()
{
	srand(time(0));
	int array[MAX];

	cout << "Original array: ";
	addArray(array);
	showArray(array);

	int k = array[0];
	for (int i = 0; i < MAX; i++)
	{
		if (array[i] > k)
			k = array[i];
	}
	cout << "\nAfter sort:\n ";
	CountingSort(array, MAX, k);
	showArray(array);
}