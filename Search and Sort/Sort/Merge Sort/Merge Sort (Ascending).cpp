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

void merge(int a[], int left, int right)
{
	int middle = (left + right + 1) / 2;
	int n1 = middle - left;
	int n2 = right - middle + 1;

	int* a1 = new int[n1];
	int* a2 = new int[n2];

	for (int i = 0; i < n1; i++)
		a1[i] = a[i + left];

	for (int i = 0; i < n2; i++)
		a2[i] = a[i + middle];

	int count = left;
	int i = 0; int j = 0;
	while (i < n1 && j < n2)
	{
		if (a1[i] > a2[j]) //Ascending
			a[count++] = a2[j++];
		else
			a[count++] = a1[i++];
	}

	for (int k = i; k < n1; k++)
		a[count++] = a1[k];

	for (int k = j; k < n2; k++)
		a[count++] = a2[k];

	delete[] a1;
	delete[] a2;
}


void MergeSort(int a[], int left, int right)
{
	if (left < right)
	{
		int middle = (left + right + 1) / 2;
		MergeSort(a, left, middle - 1);
		MergeSort(a, middle, right);
		merge(a, left, right);
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
	MergeSort(array, 0, MAX - 1);
	showArray(array);
}