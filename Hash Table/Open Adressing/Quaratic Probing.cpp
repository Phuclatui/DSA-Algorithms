#include<iostream>
#define M 7	
using namespace std;

struct Node
{
	int key;
	int status;
};

void init(Node hashtable[])
{
	for (int i = 0; i < M; i++)
	{
		hashtable[i].key = -1;
		hashtable[i].status = 0;
	}
}

void output(Node hashtable[])
{
	for (int i = 0; i < M; i++)
		cout << i << "| " << hashtable[i].key << "\t" << hashtable[i].status << endl;
}

int hash_func(const int& x)
{
	return (x % M + M) % M;
}

bool addNode(Node hashtable[], const int x)
{
	int h = hash_func(x);
	for (int i = 0; i < M; i++)
	{
		int idx = (h + i * i) % M;
		if (hashtable[idx].status == 0 || hashtable[idx].status == 2)
		{
			hashtable[idx].key = x;
			hashtable[idx].status = 1;
			return true;
		}

		if (hashtable[idx].status == 1 && hashtable[idx].key == x)
			return false;
	}
	return false;
}

int searchNode(Node hashtable[], const int& x)
{
	int h = hash_func(x);
	for (int i = 0; i < M; i++)
	{
		int idx = (h + i * i) % M;
		if (hashtable[idx].status == 0)
			return -1;
		if (hashtable[idx].status == 1 && hashtable[idx].key == x)
			return idx;
	}
	return -1;
}

bool deleteNode(Node hashtable[], const int& x)
{
	int idx = searchNode(hashtable, x);

	if (idx == -1)
		return false;

	hashtable[idx].status = 2;
	hashtable[idx].key = -1;
	return true;
}

int main()
{
	Node hashtable[M];
	init(hashtable);
	output(hashtable);


	do
	{
		int x;
		cout << "Enter x to add: ";
		cin >> x;
		if (x == -1)
			break;

		if (!addNode(hashtable, x))
			cout << "cant not add into hash table (may be full hash table or duplicate)!!!" << endl;
		output(hashtable);
	} while (true);


	do
	{
		int x;
		cout << "Enter x to find: ";
		cin >> x;
		if (x == -1)
			break;

		int find = searchNode(hashtable, x);
		if (find == -1)
			cout << "The node is not founded!!!" << endl;
		else
			cout << "The node at " << find << endl;
 		output(hashtable);
	} while (true);

	do
	{
		int x;
		cout << "Enter x to delete: ";
		cin >> x;
		if (x == -1)
			break;

		deleteNode(hashtable, x);
		output(hashtable);
	} while (true);

}