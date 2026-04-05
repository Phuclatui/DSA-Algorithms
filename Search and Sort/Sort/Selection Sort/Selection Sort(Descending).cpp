#include<iostream>
#define M 7
using namespace std;

struct Node
{
	int key;
	int link;
	int freq;
};

void init(Node hashtable[])
{
	for (int i = 0; i < M; i++)
	{
		hashtable[i].key = hashtable[i].link = -1;
		hashtable[i].freq = 0;
	}
}

void show_hash_table(Node hashtable[])
{
	for (int i = 0; i < M; i++)
		cout << i << "| " << hashtable[i].key << "\t" << hashtable[i].link << "\t" << hashtable[i].freq << endl;
}

int hash_func(const int& x)
{
	return x % M;
}

void addFregNode(Node hashtable[], const int& x)
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

		if (available >= 0)
		{
			hashtable[available] = { x,-1,1 };
			hashtable[idx].link = available;
		}
		else
			cout << "Hash table is full" << endl;
	}
}

int main()
{
	Node hashtable[M];
	init(hashtable);
	show_hash_table(hashtable);

	do
	{
		int x;
		cout << "Enter x: ";
		cin >> x;
		if (x == -1)
			break;

		addFregNode(hashtable, x);
		show_hash_table(hashtable);
	} while (true);
}