#include<iostream>
#include<ctime>
#define MAX 10
using namespace std;

void addArray(int array[])
{
	for (int i = 0; i < MAX; i++)
	{
		array[i] = rand() % 100 + 1;
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

void QuickSort(int a[], const int& left, const int& right)
{
	int pivot = a[(left + right) / 2];
	int i = left, j = right;

	do
	{
		while (a[i] < pivot) i++;
		while (a[j] > pivot) j--;

		if (i <= j)
		{
			swap(a[i], a[j]);
			i++; j--;
		}
	} while (i <= j);

	if (left < j)
		QuickSort(a, left, j);
	if (i < right)
		QuickSort(a, i, right);
}

int BinarySearch(const int array[], const int &x)
{
	int left = 0, right = MAX;

	while (left < right)
	{
		int p = (left + right) / 2;

		if (x == array[p])
			return p;
	
		if (array[p] > x)
			left = p + 1;
		else
			right = p;
	}

	return -1;
}

int main()
{
	srand(time(0));
	int array[MAX];

	cout << "Original array: ";
	addArray(array);
	showArray(array);

	cout << "After sort: ";
	QuickSort(array, 0, MAX - 1);
	showArray(array);
	int x;
	cout << "\nEnter the number to find: ";
	cin >> x;

	int find = BinarySearch(array, x);
	if (find != -1)
		cout << "The number at location: " << find << endl;
	else
		cout << "Can't find the number in array!!!" << endl;


}