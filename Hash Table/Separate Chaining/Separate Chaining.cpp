	#include<iostream>
	#define M 7
	using namespace std;

	struct Node
	{
		int key;
		Node* next;
	};

	Node* createNode(const int& x)
	{
		Node* p = new Node;
		p->key = x;
		p->next = nullptr;
		return p;
	}

	void init (Node*& head)
	{
		head = nullptr;
	}

	void init_hash_table(Node* heads[])
	{
		for (int i = 0; i < M; i++)
		{
			init(heads[i]);
		}
	}

	void addTail(Node*& head, const int& x)
	{
		Node* p = createNode(x);
		if (head == nullptr)
			head = p;
		else
		{
			Node* tail = head;
			while (tail->next != nullptr)
			{
				tail = tail->next;
			}
			tail->next = p;
		}
	}

	int hashFunc(int x)
	{
		return x % M;
	}

	void addNode_to_hashtable(Node* heads[], const int& x)
	{
		int idx = hashFunc(x);
		addTail(heads[idx], x);
	}

	void output(Node* head)
	{
		if (head != nullptr)
		{
			Node* p = head;
			while (p != nullptr)
			{
				cout << p->key << " ";
				p = p->next;
				
			}
		}
		
	}

	void output_hashtable(Node* heads[])
	{
		for (int i = 0; i < M; i++)
			if (heads[i] != nullptr)
			{
				cout << "Bucket " << i << ": ";
				output(heads[i]);
				cout << endl;
			}
	}

	int main()
	{
		Node* heads[M];
		init_hash_table(heads);

		addNode_to_hashtable(heads, 55);
		addNode_to_hashtable(heads, 21);
		addNode_to_hashtable(heads, 22);
		addNode_to_hashtable(heads, 10);
		addNode_to_hashtable(heads, 27);
		addNode_to_hashtable(heads, 45);
		addNode_to_hashtable(heads, 17);
		addNode_to_hashtable(heads, 15);

		output_hashtable(heads);
	}