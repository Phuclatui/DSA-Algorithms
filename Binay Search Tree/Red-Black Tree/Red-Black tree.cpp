#include<iostream>
using namespace std;

enum Color {RED, BLACK};

struct Node
{
	int key;
	Node* left, * right;
	Node* parent;
	Color color;
};

void init(Node*& root)
{
	root = nullptr;
}

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->key = x;
	p->left = p->right = p->parent = nullptr;
	p->color = RED;

	return p;
}

void LeftRotate(Node*& root, Node* p)
{
	Node* q = p->right;
	p->right = q->left;

	if (q->left != nullptr)
		q->left->parent = p;

	q->parent = p->parent;

	if (p->parent == nullptr)
		root = q;
	else if (p == p->parent->left)
		p->parent->left = q;
	else
		p->parent->right = q;

	p->parent = q;
	q->left = p;
}

void RightRotate(Node*& root, Node* p)
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

void fixing_Insert(Node*& root, Node* p)
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
					LeftRotate(root, parent);
					p = parent;
					parent = p->parent;
				}

				RightRotate(root, grandparent);
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
					RightRotate(root, parent);
					p = parent;
					parent = p->parent;
				}

				LeftRotate(root, grandparent);
				swap(parent->color, grandparent->color);
				p = parent;
			}
		}
	}
	root->color = BLACK;
}


void fixing_delete(Node*& root, Node* p)
{
	while (p != root && p->color == BLACK)
	{
		if (p == p->parent->left)
		{
			Node* sibling = p->parent->right;
			if (sibling != nullptr && sibling->color == RED)
			{
				sibling->color = BLACK;
				p->parent->color = RED;
				LeftRotate(root, p->parent);
				sibling = p->parent->right;
			}

			if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK))
			{
				sibling->color = RED;
				p = p->parent;
			}
			else
			{
				if (sibling->right == nullptr || sibling->right->color == BLACK)
				{
					if (sibling->left != nullptr)
					{
						sibling->left->color = BLACK;
						sibling->color = RED;
						RightRotate(root, sibling);
						sibling = p->parent->right;
					}
				}

					sibling->color = p->parent->color;
					p->parent->color = BLACK;
					if (sibling->right != nullptr)
					{
						sibling->right->color = BLACK;
					}
					LeftRotate(root, p->parent);
					p = root;
				}
		}
		else
		{
			Node* sibling = p->parent->left;
			if (sibling != nullptr && sibling->color == RED)
			{
				sibling->color = BLACK;
				p->parent->color = RED;
				RightRotate(root, p->parent);
				sibling = p->parent->left;
			}

			if ((sibling->left == nullptr || sibling->left->color == BLACK) && (sibling->right == nullptr || sibling->right->color == BLACK))
			{
				sibling->color = RED;
				p = p->parent;
			}
			else
			{
				if (sibling->left == nullptr || sibling->left->color == BLACK)
				{
					if (sibling->right != nullptr)
					{
						sibling->left->color = BLACK;
						sibling->color = RED;
						LeftRotate(root, sibling);
						sibling = p->parent->left;
					}
				}

				sibling->color = p->parent->color;
				p->parent->color = BLACK;

				if (sibling->left != nullptr)
				{
					sibling->left->color = BLACK;
				}
				RightRotate(root, p->parent);
				p = root;
			}
		}
		p->color = BLACK;
	}
}



int main()
{
	Node* root;
	init(root);


}