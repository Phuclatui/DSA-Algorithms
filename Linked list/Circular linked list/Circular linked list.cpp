#include<iostream>
using namespace std;

struct Node
{
	int infor;
	Node* next;
};

void init(Node*& head, Node*& tail)
{
	head = nullptr;
	tail = nullptr;
}

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->infor = x;
	p->next = nullptr;

	return p;
}

void addhead(Node* &head, Node*& tail, const int& x)
{
	Node* p = createNode(x);
	p->next = head;

	if (head == nullptr)
		tail = p;
	head = p;
	tail->next = p;
}

void deletehead(Node*& head, Node*& tail)
{
	Node* p = head;
	if (p->next == nullptr)
		head = tail = nullptr;
	else
	{
		head = p->next;
		tail->next = head;
	}
	p->next = nullptr;
	delete p;
}


void show(Node* head)
{
	if (head != nullptr)
	{
		Node* p = head;
		do
		{
			cout << p->infor << " ";
			p = p->next;
		} while (p != head);
	}cout << endl;
}

int main()
{
	Node* head;
	Node* tail;
	init(head, tail);

	addhead(head, tail, 10);
	addhead(head, tail, 20);
	addhead(head, tail, 30);
	addhead(head, tail, 40);
	show(head);
	deletehead(head, tail);
	deletehead(head, tail);
	deletehead(head, tail);
	show(head);


}
