#include<iostream>
#include<ctime>
#define MAX 1000
using namespace std;

void addArray(int array[])
{
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % 1000;
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


void SelectionSort(int array[]) // Descending
{
	for (int i = 0; i < MAX - 1; i++)
	{
		int max = i;
		for (int j = i + 1; j < MAX; j++)
		{
			if (array[max] < array[j])
				max = j;
		}
		swap(array[i], array[max]);
	}
}


int main()
{
	srand(time(0));
	int array[MAX];

	cout << "Original array: ";
	addArray(array);
	showArray(array);


	cout << "\nAfter Sort: ";
	SelectionSort(array);
	showArray(array);

}