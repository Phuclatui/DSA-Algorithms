#include<iostream>
using namespace std;

struct Node
{
	int value;
	Node* nextNode;
};

void init(Node*& head)
{
	head = nullptr;
}

Node* createNewNode(const int& x)
{
	Node* p = new Node;
	p->value = x;
	p->nextNode = nullptr;
	return p;
}

void addHead(const int& x, Node*& head)
{
	Node* p = createNewNode(x);
	p->nextNode = head;
	head = p;
}

void addTail(const int& x, Node*& head)
{
	if (head == nullptr)
		head = createNewNode(x);
	else
	{
		Node* p = head;

		while (p->nextNode != nullptr)
			p = p->nextNode;

		p->nextNode = createNewNode(x);
	}
}

void addAfter(const int& x, const int& value, Node* head)
{
	Node* p = head;
	while (p != nullptr && p->value != x)
		p = p->nextNode;

	if (p != nullptr)
	{
		Node* q = createNewNode(value);
		q->nextNode = p->nextNode;
		p->nextNode = q;
	}
	else
		cout << "Dont exist value " << x << " to add " << endl;
}

void addBefore(const int& x, const int& value, Node*& head)
{
	Node* p = head;
	Node* previous = nullptr;

	while (p != nullptr && p->value != x)
	{
		previous = p;
		p = p->nextNode;
	}

	if (p != nullptr)
	{
		Node* q = createNewNode(value);
		if (previous == nullptr)
		{
			q->nextNode = head;
			head = q;
		}
		else
		{
			previous->nextNode = q;
			q->nextNode = p;
		}
	}
	else
		cout << "Dont exist value " << x << " to add " << endl;
}


void deleteHead(Node*& head)
{
	if (head != nullptr)
	{
		Node* p = head;
		head = p->nextNode;

		p->nextNode = nullptr;
		delete p;
	}
}

void deleteTail(Node*& head)
{
	if (head != nullptr)
	{
		Node* p = head;
		Node* previous = nullptr;

		while (p->nextNode != nullptr)
		{
			previous = p;
			p = p->nextNode;
		}

		if (p != nullptr)
		{
			if (previous == nullptr)
				head = nullptr;
			else
				previous->nextNode = nullptr;

			delete p;
		}
	}
}


void deleteX(const int& x, Node*& head)
{
	if (head == nullptr) return;
	Node* p = head;
	Node* previous = nullptr;

	while (p != nullptr && p->value != x)
	{
		previous = p;
		p = p->nextNode;
	}

	if (p != nullptr)
	{
		if (previous == nullptr)
		{
			Node* q = head;
			head = q->nextNode;
		}
		else
			previous->nextNode = p->nextNode;

		delete p;
	}
	else
		cout << x << " is not existed to delete!!!" << endl;
}


void show(Node* head)
{
	if (head != nullptr)
	{
		Node* p = head;
		while (p != nullptr)
		{
			cout << p->value << " ";
			p = p->nextNode;
		}
	}
	cout << endl;
}

Node* checkValue(Node* head, const int& x, int& index)
{
	index = 0;
	Node* p = head;
	while (p != nullptr && p->value != x)
	{
		index++;
		p = p->nextNode;
	}

	return p;
}

int countValues(Node* head)
{
	int count = 0;
	Node* p = head;

	while (p != nullptr)
	{
		count++;
		p = p->nextNode;
	}

	return count;
}

void clearList(Node*& head)
{
	while (head != nullptr)
	{
		deleteHead(head);
	}
}




int main()
{
	Node* head;
	init(head);

	addHead(10, head);
	addTail(25, head);
	addHead(35, head);
	addTail(40, head);
	show(head);

	int x; int index = 0;  cout << "Enter x to check: "; cin >> x;
	if (checkValue(head, x, index))
		cout << "The values had been existed at index " << index << endl;
	else
		cout << "The value dont exist!!!" << endl;

	cout << "The list have " << countValues(head) << " elements " << endl;

	addAfter(25, 100, head);
	show(head);

	addBefore(40, 11, head);
	show(head);

	cout << "Enter the value to delete: ";
	cin >> x;
	deleteX(x, head);
	show(head);


	clearList(head);
}