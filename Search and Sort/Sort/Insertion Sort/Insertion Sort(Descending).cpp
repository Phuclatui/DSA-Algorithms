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

void InsertionSort(int array[]) // Descending
{
	for (int i = 1; i < MAX; i++)
	{
		int position = i - 1;
		int temp = array[i];

		while (position >= 0 && array[position] < temp)
		{
			array[position + 1] = array[position];
			position--;
		}

		array[position + 1] = temp;
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
	InsertionSort(array);
	showArray(array);


}