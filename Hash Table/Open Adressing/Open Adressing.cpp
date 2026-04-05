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

void ouput(Node hashtable[])
{
	for (int i = 0; i < M; i++)
	{
		cout << i << "| " << hashtable[i].key << "\t" << hashtable[i].status << endl;
	}
}

int hash_func(const int& x)
{
	return  (x % M + M) % M;
}

bool addNode(Node hashtable[], const int& x)
{
	int h = hash_func(x);

	for (int i = 0; i < M; i++)
	{
		int idx = (h + i) % M;

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

int searchnode(Node hashtable[], const int& x)
{
	int h = hash_func(x);

	for (int i = 0; i < M; i++)
	{
		int idx = (h + i) % M;
		if (hashtable[idx].status == 0)
			return -1;

		if (hashtable[idx].status == 1 && hashtable[idx].key == x)
			return idx;
	}

	return -1;
}

bool deleteNodeE(Node hashtable[], const int x)
{
	int idx = searchnode(hashtable, x);

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
	ouput(hashtable);


	do
	{
		cout << "\nMENU\n"
			<< "1. add Node\n"
			<< "2. find node\n"
			<< "3. delete node\n";
		cout << "Enter your choosee: ";
		int n;
		cin >> n;
		if (n == -1)
			return 0;

		switch (n)
		{
		case 1:
		{
			do
			{
				int x;
				cout << "Enter x to add: ";
				cin >> x;
				if (x == -1)
					break;

				if (!addNode(hashtable, x))
					cout << "The tablee is duplicate or hash table is full!!!" << endl;
				ouput(hashtable);
			} while (true);
			break;
		}

		case 2:
		{
			do
			{
				int x;
				cout << "Enter x to find: ";
				cin >> x;
				if (x == -1)
					break;

				int find = searchnode(hashtable, x);
				if (find == -1)
					cout << "Dont have node!!!" << endl;
				else
					cout << "The node at " << find << endl;
			} while (true);
			break;
		}

		case 3:
		{
			do
			{
				int x;
				cout << "Enter x to delete: ";
				cin >> x;
				if (x == -1)
					break;

				if (!deleteNodeE(hashtable, x))
					cout << "Dont have node to delete!!! " << endl;

				ouput(hashtable);
			} while (true);
			break;
		}
		}
	} while (true);
}
