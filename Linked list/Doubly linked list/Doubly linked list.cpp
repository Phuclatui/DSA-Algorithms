#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node* next;
	Node* previous;
};

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->value = x;
	p->next = nullptr;
	p->previous = nullptr;

	return p;
}

void init(Node*& head, Node*& tail)
{
	head = nullptr;
	tail = nullptr;
}

void addHead(const int& x, Node*& head, Node*& tail)
{
	if (head == nullptr)
		head = tail = createNode(x);
	else
	{
		Node* p = createNode(x);
		p->next = head;
		head->previous = p;
		head = p;
	}
}

void addTail(const int& x, Node*& head, Node*& tail)
{
	if (tail == nullptr)
		head = tail = createNode(x);
	else
	{
		Node* p = createNode(x);
		tail->next = p;
		p->previous = tail;
		tail = p;
	}
}

void addBeforeValue(const int& x, const int& value, Node*& head, Node*& tail)
{
	if (head != nullptr)
	{
		Node* p = head;

		while (p != nullptr && p->value != x)
		{
			p = p->next;
		}

		if (p != nullptr)
		{
			Node* q = createNode(value);

			if (p == head)
			{
				q->next = head;
				head->previous = q;
				head = q;
			}
			else
			{
				q->next = p->previous->next;
				p->previous->next = q;
				q->previous = p->previous;
				p->previous = q;
			}
		}
		else
			cout << "Dont have any value to add after!!!" << endl;
	}
}


void addAfterValue(const int& x, const int& value, Node*& head, Node*& tail)
{
	if (head == nullptr) return;
	Node* p = head;

	while (p != nullptr && p->value != x)
		p = p->next;

	if (p != nullptr)
	{
		Node* q = createNode(value);
		if (p == tail)
		{
			tail->next = q;
			q->previous = tail;
			tail = q;
		}
		else
		{
			q->next = p->next;
			p->next->previous = q;
			q->previous = p;
			p->next = q;
		}
	}
	else
		cout << "Dont have " << x << " to add after!!!" << endl;
}

void deleteHead(Node*& head, Node*& tail)
{
	if (head != nullptr)
	{
		Node* p = head;
		if (p->next == nullptr)
			head = tail = nullptr;
		else
		{
			p->next->previous = nullptr;
			head = p->next;
		}
		delete p;
	}
}

void deleteTail(Node*& head, Node*& tail)
{
	if (tail != nullptr)
	{
		Node* p = tail;
		if (tail->previous == nullptr)
			tail = head = nullptr;
		else
		{
			p->previous->next = nullptr;
			tail = p->previous;
		}
		delete p;
	}
}

void deleteX(const int& x, Node*& head, Node*& tail)
{
	if (head == nullptr) return;

	Node* p = head;

	while (p != nullptr && p->value != x)
		p = p->next;

	if (p != nullptr)
	{
		if (p->previous == nullptr)
			head = p->next;
		else
		{
			p->previous->next = p->next;
		}

		if (p->next == nullptr)
			tail = p->previous;
		else
			p->next->previous = p->previous;

		delete p;
	}
	else
		cout << "Dont have " << x << " to delete!!!" << endl;
}

Node* searchValue(const int& x, int& count, Node* head)
{
	if (head == nullptr) return nullptr;
	count = 0;

	Node* p = head;
	while (p != nullptr && p->value != x)
	{
		count++;
		p = p->next;
	}

	return p;
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
			p = p->next;
		}
		cout << endl;
	}
}

void clearall(Node*& head, Node*& tail)
{
	if (head != nullptr)
	{
		while (head != nullptr)
			deleteHead(head, tail);
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
	Node* head, * tail;
	init(head, tail);

	int n, x, y, t;
	int count = 0;



	do
	{
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

				addHead(x, head, tail);

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

				addTail(x, head, tail);

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
			addAfterValue(x, y, head, tail);
			show(head);

			break;
		}

		case 4:
		{
			cout << "Enter value to add before : ";
			cin >> x;
			cout << "Enter value: ";
			cin >> y;

			addBeforeValue(x, y, head, tail);
			show(head);

			break;
		}

		case 5:
		{
			deleteHead(head, tail);
			show(head);

			break;
		}

		case 6:
		{
			deleteTail(head, tail);
			show(head);

			break;
		}

		case 7:
		{

			cout << "Enter value to delete : ";
			cin >> x;
			deleteX(x, head, tail);
			show(head);

			break;
		}

		case 8:
		{

			cout << "Enter the value to search: ";
			cin >> x;

			if (searchValue(x, count, head))
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
			clearall(head, tail);
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