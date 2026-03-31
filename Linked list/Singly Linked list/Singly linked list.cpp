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
	cout << "List: ";
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

void menu()
{
	cout << "\n------MENU---------\n";
	cout << "1. Add head\n"
		<< "2. Add tail\n"
		<< "3. Add after\n"
		<< "4. Add before\n"
		<< "5. Delete head\n"
		<< "6. Delete tail\n"
		<< "7. Delete value\n"
		<< "8. Search\n"
		<< "9. Show list\n"
		<< "10. Exit Program\n" << endl;
}

int main()
{
	Node* head;
	init(head);

	int n, x, y, t;
	int count = 0;



	do
	{
		show(head);
		menu();
		cout << "\nEnter your choose: ";
		cin >> t;

		switch (t)
		{
		case 1:
		{
			cout << "\033[32m" << "Enter -1 to exit to the menu: " << "\033[0m\n";
			do
			{
				cout << "Enter x: ";
				cin >> x;

				if (x == -1)
					break;;

				addHead(x, head);

				show(head);
			} while (true);
			break;
		}

		case 2:
		{


			cout << "\033[32m" << "Enter -1 to exit to the menu: " << "\033[0m\n";
			do
			{
				cout << "Enter x: ";
				cin >> x;

				if (x == -1)
					break;;

				addTail(x, head);

				show(head);
			} while (true);
			break;
		}

		case 3:
		{
			cout << "Enter value to add after : ";
			cin >> x;
			cout << "Enter value: ";
			cin >> y;
			addAfter(x, y, head);
			show(head);

			break;
		}

		case 4:
		{
			cout << "Enter value to add before : ";
			cin >> x;
			cout << "Enter value: ";
			cin >> y;

			addBefore(x, y, head);
			show(head);

			break;
		}

		case 5:
		{
			deleteHead(head);
			show(head);

			break;
		}

		case 6:
		{
			deleteTail(head);
			show(head);

			break;
		}

		case 7:
		{

			cout << "Enter value to delete : ";
			cin >> x;
			deleteX(x, head);
			show(head);

			break;
		}

		case 8:
		{

			cout << "Enter the value to search: ";
			cin >> x;

			if (checkValue(head,x, count))
				cout << x << " at location " << count << endl;
			else
				cout << "Dont find q" << endl;
			break;
		}

		case 9:
		{
			show(head); break;
		}

		case 10:
		{
			cout << "Exit successfully!!!" << endl;
			clearList(head);
			return 0;
		}

		default:
		{
			cout << "Enter again!!!!" << endl;
			break;
		}
		}
	} while (true);



}