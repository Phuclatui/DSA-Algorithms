#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node* left, * right;
};

void init(Node*& root)
{
	root = nullptr;
}

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->key = x;
	p->left = nullptr;
	p->right = nullptr;
	return p;
}

void addNode_with_recursion(Node*&root, const int& x)
{
	if (root == nullptr)
		root = createNode(x);
	else if (root->key > x)
		addNode_with_recursion(root->left, x);
	else
		addNode_with_recursion(root->right, x);
}

void addNode_no_recursion(Node*& root, const int& x)
{
	if (root == nullptr)
		root = createNode(x);
	else
	{
		Node* q = root;
		Node* parent = nullptr;

		while (q != nullptr)
		{
			parent = q;
			if (q->key > x)
				q = q->left;
			else
				q = q->right;
		}

		if (parent->key > x)
			parent->left = createNode(x);
		else
			parent->right = createNode(x);
	}
}

void lrn(Node* root)
{
	if (root != nullptr)
	{
		lrn(root->left);
		lrn(root->right);
		cout << root->key << "\t";
	}
}

void deleteNode_no_recursion(Node*& root, const int& x)
{
	Node* q = root;
	Node* parent = nullptr;

	while (q != nullptr && q->key != x)
	{
		parent = q;
		if (q->key > x)
			q = q->left;
		else
			q = q->right;
	}

	if (q != nullptr)
	{
		if (q->left == nullptr && q->right == nullptr)
		{
			if (parent == nullptr)
				root = nullptr;
			else
			{
				if (parent->left == q)
					parent->left = nullptr;
				else
					parent->right = nullptr;
			}
			delete q;
		}

		else
		{
			if (q->left != nullptr && q->right != nullptr)
			{
				parent = q;
				Node* tmp = q->right;

				while(tmp->left != nullptr)
				{
					parent = tmp;
					tmp = tmp->left;
				}

				q->key = tmp->key;
				q = tmp;
			}

			Node* r;
			if (q->left == nullptr)
				r = q->right;
			else
				r = q->left;

			if (parent == nullptr)
				root = r;
			else
			{
				if (parent->left == q)
					parent->left = r;
				else
					parent->right = r;
			}
			delete q;
		}
	}
}	

void deleteNode_with_recursion(Node*& root, const int& x)
{
	if (root != nullptr)
	{
		if (root->key > x)
			deleteNode_with_recursion(root->left, x);
		else if (root->key < x)
			deleteNode_with_recursion(root->right, x);
		else
		{
			if (root->left != nullptr && root->right != nullptr)
			{
				Node* parent = root;
				Node* tmp = root->right;

				while (tmp->left != nullptr)
					tmp = tmp->left;
				root->key = tmp->key;
				deleteNode_with_recursion(root->right, tmp->key);
			}
			else
			{
				Node* p = root;
				if (root->left == nullptr)
					root = root->right;
				else if (root->right == nullptr)
					root = root->left;
				delete p;
			}
		}
	}
}

int main()
{
	Node* root;
	init(root);

	addNode_no_recursion(root, 50);
	addNode_no_recursion(root, 30);
	addNode_no_recursion(root, 80);
	addNode_with_recursion(root, 20);
	addNode_with_recursion(root, 40);
	addNode_with_recursion(root, 60);
	addNode_with_recursion(root, 90);
	addNode_with_recursion(root, 35);
	addNode_with_recursion(root, 70);
	addNode_no_recursion(root, 55);
	deleteNode_with_recursion(root, 60);
	deleteNode_with_recursion(root, 20);
	deleteNode_with_recursion(root, 50);
	
	lrn(root);

}