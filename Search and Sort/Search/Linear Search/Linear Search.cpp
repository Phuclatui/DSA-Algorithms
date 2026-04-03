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

int LinearSearch(const int array[], const int &x)
{
	for (int i = 0; i < MAX; i++)
	{
		if (array[i] == x)
			return i;
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

	int x;
	cout << "\nEnter the number to find: ";
	cin >> x;

	int find = LinearSearch(array, x);
	if (find != -1)
		cout << "The number at location: " << find << endl;
	else
		cout << "Can't find the number in array!!!" << endl;


}