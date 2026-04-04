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

void Heapify(int array[], const int& n, const int i)
{
	int jmin = 2 * i + 1;
	if (jmin < n)
	{
		if (2 * i + 2 < n && array[jmin] > array[2 * i + 2])
			jmin = 2 * i + 2;

		if (array[i] > array[jmin])
		{
			swap(array[i], array[jmin]);
			Heapify(array, n, jmin);
		}
	}
}

void buildMinHeap(int array[])
{
	for (int i = (MAX / 2) - 1; i >= 0; i--)
	{
		Heapify(array, MAX, i);
	}
}


void HeapSort(int array[])
{
	buildMinHeap(array);
	for (int i = MAX - 1; i > 0 ; i--)
	{
		swap(array[0], array[i]);
		Heapify(array, i, 0);
	}
}

int main()
{
	srand(time(0));
	int array[MAX];

	cout << "Original array: ";
	addArray(array);
	showArray(array);

	cout << "\nAfter sort:\n ";
	HeapSort(array);
	showArray(array);
}