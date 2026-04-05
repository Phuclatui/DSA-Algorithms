#include<iostream>
using namespace std;

enum Color { RED, BLACK };

struct Node
{
	int key;
	Node* right, * left;
	Node* parent;
	Color color;
};

void init(Node*& root)
{
	root = nullptr;
}

void leftRotate(Node*& root, Node* p)
{
	Node* q = p->right;
	p->right = q->left;

	if (q->left != nullptr)
		q->left->parent = p;

	q->parent = p->parent;

	if (p->parent == nullptr)
		root = q;
	else if (p->parent->left == p)
		p->parent->left = q;
	else
		p->parent->right = q;

	p->parent = q;
	q->left = p;
}

void rightRotate(Node*& root, Node* p)
{
	Node* q = p->left;
	p->left = q->right;

	if (q->right != nullptr)
		q->right->parent = p;

	q->parent = p->parent;

	if (p->parent == nullptr)
		root = q;
	else if (p->parent->left == p)
		p->parent->left = q;
	else
		p->parent->right = q;

	p->parent = q;
	q->right = p;
}

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->key = x;
	p->left = p->right = p->parent = nullptr;

	p->color = RED;
	return p;
}

void insert_fix(Node*& root, Node* p)
{
	while (p != root && p->parent->color == RED)
	{
		Node* parent = p->parent;
		Node* grandparent = parent->parent;

		if (parent == grandparent->left)
		{
			Node* uncle = grandparent->right;
			if (uncle != nullptr && uncle->color == RED)
			{
				grandparent->color = RED;
				uncle->color = parent->color = BLACK;
				p = grandparent;
			}
			else
			{
				if (p == parent->right)
				{
					leftRotate(root, parent);
					p = parent;
					parent = p->parent;
				}

				rightRotate(root, grandparent);
				swap(parent->color, grandparent->color);
				p = parent;
			}
		}
		else
		{
			Node* uncle = grandparent->left;
			if (uncle != nullptr && uncle->color == RED)
			{
				grandparent->color = RED;
				uncle->color = parent->color = BLACK;
				p = grandparent;
			}
			else
			{
				if (p == parent->left)
				{
					rightRotate(root, parent);
					p = parent;
					parent = p->parent;
				}

				leftRotate(root, grandparent);
				swap(parent->color, grandparent->color);
				p = parent;
			}
		}
	}
	root->color = BLACK;
}

void insert(Node*& root, const int& x)
{
	Node* q = createNode(x);
	Node* p = root;
	Node* parent = nullptr;

	while (p != nullptr)
	{
		parent = p;
		if (p->key > x)
			p = p->left;
		else
			p = p->right;
	}

	q->parent = parent;
	if (parent == nullptr)
		root = q;
	else if (parent->key > x)
		parent->left = q;
	else
		parent->right = q;

	insert_fix(root, q);
}


void lnr(Node* root)
{
	if (root != nullptr)
	{
		lnr(root->left);
		cout << root->key << " ";
		lnr(root->right);
	}
}

void fixing_delete(Node*& root, Node* p)
{
	while (p != root && p->color == BLACK)
	{
		if (p == p->parent->left)
		{
			Node* sibling = p->parent->right;

			//Case 1: mục đích là chuyển sibling thành black, case sau dựa vào con mới của sibling
			if (sibling != nullptr && sibling->color == RED)
			{
				sibling->color = BLACK;
				p->parent->color = RED;
				leftRotate(root, p->parent);
				sibling = p->parent->right;

			}
			//Case 2: p double black, và sibling có 2 con là black (tính cả NIL)
			if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK))
			{
				sibling->color = RED;
				p = p->parent;
			}
			else
			{
				//case 3: con gần là RED, con xa là BLack/NIL
				if (sibling->right == nullptr || sibling->right->color == BLACK)
				{
					if (sibling->left != nullptr)
					{
						sibling->left->color = BLACK;
						sibling->color = RED;
						rightRotate(root, sibling);
						sibling = p->parent->right; // sibling có con phải là RED
					}
				}

				sibling->color = p->parent->color; // kế thừa màu color của parent nhằm duy trì black height
				p->parent->color = BLACK; // dùng parent (nếu nó RED) làm nguồn BLACK để triệt tiêu double black ở nhánh p
				if (sibling->right != nullptr)
					sibling->right->color = BLACK; // bù black nếu như sibling = parent color - red
				leftRotate(root, p->parent); //dùng con xa RED của sibling làm nguồn BLACK để bù cho nhánh còn lại và tránh RED–RED
				p = root;

			}
		}

		else {
			Node* sibling = p->parent->left;
			if (sibling != nullptr && sibling->color == RED)
			{
				sibling->color = BLACK;
				p->parent->color = RED;
				rightRotate(root, p->parent);
				sibling = p->parent->left;
			}
			if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK)) {
				sibling->color = RED;
				p = p->parent;
			}
			else {
				if (sibling->left == nullptr
					|| sibling->left->color == BLACK)
				{
					if (sibling->right != nullptr)
						sibling->right->color = BLACK;
					sibling->color = RED;
					leftRotate(root, sibling);
					sibling = p->parent->left;
				}
				sibling->color = p->parent->color;
				p->parent->color = BLACK;
				if (sibling->left != nullptr)
					sibling->left->color = BLACK;
				rightRotate(root, p->parent);
				p = root;
			}
		}
	}
	p->color = BLACK;
}


void deleteNode(Node*& root, const int& x)
{
	Node* p = root;
	Node* parent = nullptr;

	Color deletedColor;
	Node* fixNode = nullptr;

	while (p != nullptr && p->key != x)
	{
		parent = p;
		if (p->key > x)
			p = p->left;
		else
			p = p->right;
	}

	if (p == nullptr)
	{
		cout << "The node is not found!!!" << endl;
		return;
	}

	if (p->left != nullptr && p->right != nullptr)
	{
		Node* temp = p->right;
		parent = p;
		while (temp->left != nullptr)
		{
			parent = temp;
			temp = temp->left;
		}
		p->key = temp->key;
		p = temp;
	}
	deletedColor = p->color;

	Node* r;
	if (p->left == nullptr)
		r = p->right;
	else
		r = p->left;

	fixNode = r;

	if (parent == nullptr)
	{
		root = r;
		if (r != nullptr)
			r->parent = nullptr;
	}
	else
	{
		if (parent->left == p)
			parent->left = r;
		else
			parent->right = r;

		if (r != nullptr)
			r->parent = parent;
	}

	delete p;

	if (deletedColor == BLACK)
	{
		if (fixNode != nullptr)
			fixing_delete(root, fixNode);
		else
			fixing_delete(root, parent); // double black NIL
	}
}



int main()
{
	Node* root;
	init(root);

	insert(root, 10);
	insert(root, 30);
	insert(root, 20);

	lnr(root);
	cout << endl;

	deleteNode(root, 20);
	lnr(root);

}