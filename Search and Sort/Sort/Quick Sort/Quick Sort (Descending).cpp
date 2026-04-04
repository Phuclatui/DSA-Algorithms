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

void QuickSort(int array[], int left, int right) //Descending
{
	int pivot = (left + right) / 2;
	int i = left, j = right;

	do
	{
		while (array[i] > array[pivot]) i++;
		while (array[j] < array[pivot]) j--;

		if (i <= j)
		{
			swap(array[i], array[j]);
			i++;
			j--;
		}
	} while (i <= j);

	if (left < j)
		QuickSort(array, left, j);

	if (right > i)
		QuickSort(array, i, right);
}

int main()
{
	srand(time(0));
	int array[MAX];

	cout << "Original array: ";
	addArray(array);
	showArray(array);

	cout << "\nAfter sort:\n ";
	QuickSort(array, 0, MAX - 1);
	showArray(array);
}