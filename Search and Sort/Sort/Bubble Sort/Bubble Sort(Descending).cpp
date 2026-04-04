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

void BubbleSort(int array[])
{
	for (int i = 0; i < MAX - 1; i++)
	{
		for (int j = MAX - 1; j > i; j--)
		{
			if (array[j] > array[j - 1])
				swap(array[j], array[j - 1]);
		}
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
	BubbleSort(array);
	showArray(array);
}