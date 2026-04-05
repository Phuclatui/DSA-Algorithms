#include<iostream>
#define M 7
using namespace std;

struct Node
{
	int key;
	int state;
};

void init(Node hashtable[])
{
	for (int i = 0; i < M; i++)
	{
		hashtable[i].key = -1;
		hashtable[i].state = 0;
	}
}

void output(Node hashtable[])
{
	for (int i = 0; i < M; i++)
		cout << i << "| " << hashtable[i].key << "\t" << hashtable[i].state << endl;
}

int hash_func_1(const int& x)
{
	return (x % M + M) % M;
}

int hash_func_2(const int& x)
{
	return 1 +(( x % (M - 1) + (M-1))% (M - 1));
}

bool addNode(Node hashtable[], const int& x)
{
	int h1 = hash_func_1(x);
	int h2 = hash_func_2(x);

	for (int i = 0; i < M; i++)
	{
		int idx = (h1 + i * h2) % M;

		if (hashtable[idx].state == 0 || hashtable[idx].state == 2)
		{
			hashtable[idx].key = x;
			hashtable[idx].state = 1;
			return true;
		}

		if (hashtable[idx].state == 1 && hashtable[idx].key == x)
			return false;
	}
	return false;
}

int searchNode(Node hashtable[], const int& x)
{
	int h1 = hash_func_1(x);
	int h2 = hash_func_2(x);

	for (int i = 0; i < M; i++)
	{
		int idx = (h1 + i * h2) % M;

		if (hashtable[idx].state == 0)
			return - 1;

		if (hashtable[idx].state == 1 && hashtable[idx].key == x)
			return idx;
	}
	return -1;
}

bool deleteNode(Node hashtable[], const int& x)
{
	int idx = searchNode(hashtable, x);

	if (idx == -1)
		return false;
	
	hashtable[idx].state = 2;
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
			cout << "Full table or dupicate!!" << endl;
		output(hashtable);
	} while (true);


	do
	{
		int x;
		cout << "Enter x to search: ";
		cin >> x;
		if (x == -1)
			break;
		int find = searchNode(hashtable, x);
		if (find != -1)
			cout << "The node at: " << find << endl;
		else
			cout << "Do not existed the node!!!" << endl;
	} while (true);

	do
	{
		int x;
		cout << "Enter x to delete: ";
		cin >> x;
		if (x == -1)
			break;
		
		if (!deleteNode(hashtable, x))
			cout << "dont have any node to delete!!" << endl;
		output(hashtable);
	} while (true);



}