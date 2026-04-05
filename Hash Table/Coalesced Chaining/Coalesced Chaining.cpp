#include<iostream>
#define M 7
using namespace std;

struct Node
{
	int key;
	int link;
	int freq;
};

void initHashTable(Node hashtable[])
{
	for (int i = 0; i < M; i++)
	{
		hashtable[i].key = hashtable[i].link = -1;
		hashtable[i].freq = 0;
	}
}

void showHashTable(Node hashtable[])
{
	for (int i = 0; i < M; i++)
		cout << i << "| " << hashtable[i].key << "\t" << hashtable[i].link << "\t" << hashtable[i].freq << endl;
}

int hash_func(const int& x)
{
	return x % M;
}

void addNode(Node hashtable[], const int& x)
{
	int idx = hash_func(x);
	if (hashtable[idx].key == -1)
		hashtable[idx] = { x,-1,1 };
	else if (hashtable[idx].key == x)
		hashtable[idx].freq++;
	else
	{
		while (hashtable[idx].link != -1)
		{
			idx = hashtable[idx].link;
			if (hashtable[idx].key == x)
			{
				hashtable[idx].freq++;
				return;
			}
		}

		int available = -1;
		for (int i = M - 1; i >= 0; i--)
			if (hashtable[i].key == -1)
			{
				available = i;
				break;
			}

		if (available < 0)
			cout << "Hash table is full!!!" << endl;
		else
		{
			hashtable[available] = { x,-1,1 };
			hashtable[idx].link = available;
		}
	}
}

void deleteNode(Node hashtable[], const int& x)
{
	int idx = hash_func(x);
	int previous = -1;

	while (idx >= 0 && hashtable[idx].key != x)
	{
		previous = idx;
		idx = hashtable[idx].link;
	}


	if (idx >= 0)
	{
		if (hashtable[idx].freq > 1)
		{
			hashtable[idx].freq--;
			return;
		}

		if (previous >= 0)
		{
			hashtable[previous].link = hashtable[idx].link;
			hashtable[idx] = { -1,-1,0 };
		}

		else
		{
			int newindex = hashtable[idx].link;
			if (newindex >= 0)
			{
				hashtable[idx] = hashtable[newindex];
				hashtable[newindex] = { -1,-1,0 };
			}
			else
				hashtable[idx] = { -1,-1,0 };
		}
	}
	else
		cout << "dont have node to delete!!!" << endl;
}



void menu()
{
	cout << "Menu"
		<< "\n1.add value"
		<< "\n2.delete value"
		<< "\n-1. exit program";
}

int main()
{
	Node hashtable[M];
	initHashTable(hashtable);
	showHashTable(hashtable);

	menu();
	int t;
	do
	{
		cout << "\nEnter yout choose: ";
		cin >> t;

		if (t == -1)
			return 0;

		switch (t)
		{
		case 1:
		{
			cout << "Enter -1 to return menu!!!\n";
			do
			{
				int x;
				cout << "Enter x: ";
				cin >> x;
				if (x == -1)
					break;

				addNode(hashtable, x);
				showHashTable(hashtable);
			} while (true);

			menu();
			break;
		}

		case 2:

		{
			cout << "Enter -1 to return menu!!!\n";
			do
			{
				int x;
				cout << "Enter x to delete: ";
				cin >> x;
				if (x == -1)
					break;

				deleteNode(hashtable, x);
				showHashTable(hashtable);
				menu();

			} while (true);
			break;
		}

		default:
			cout << "Enter again!!!" << endl;
		}
	} while (true);

	


}