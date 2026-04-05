#include<iostream>
using namespace std;

struct Node
{
	int key;
	Node* left, * right;
	int height;
};

void init(Node*& root)
{
	root = nullptr;
}

int height(Node* p)
{
	return p == nullptr ? 0 : p->height;
}

int balanceFactor(Node* p)
{
	return p == nullptr ? 0 : (height(p->left) - height(p->right));
}

Node* createNode(const int& x)
{
	Node* p = new Node;
	p->key = x;
	p->left = nullptr;
	p->right = nullptr;
	p->height = 1;

	return p;
}


Node* rightRotate(Node* p)
{
	Node* q = p->left;
	Node* r = q->right;

	q->right = p;
	p->left = r;

	p->height = max(height(p->left), height(p->right)) + 1;
	q->height = max(height(q->left), height(q->right)) + 1;

	return q;
}


Node* leftRotate(Node* p)
{
	Node* q = p->right;
	Node* r = q->left;

	q->left = p;
	p->right = r;

	p->height = max(height(p->left), height(p->right)) + 1;
	q->height = max(height(q->left), height(q->right)) + 1;

	return q;
}

Node* insert(Node* root, const int& x)
{
	if (root == nullptr)
		return root = createNode(x);

	else if (root->key > x)
		root->left = insert(root->left, x);
	else
		root->right = insert(root->right, x);

	root->height = max(height(root->left), height(root->right)) + 1;
	int balance = balanceFactor(root);

	if (balance > 1 && balanceFactor(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && balanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && balanceFactor(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && balanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}

Node* findSuccessor(Node* root)
{
	Node *p = root;
	while (p->left != nullptr)
		p = p->left;
	return p;
}

Node * deleteNode(Node* root, const int& x)
{
	if (root == nullptr)
		return nullptr;

	if (root->key > x)
		root->left = deleteNode(root->left, x);
	else if (root->key < x)
		root->right = deleteNode(root->right, x);
	else
	{
		if (root->left != nullptr && root->right != nullptr)
		{
			Node* tmp = findSuccessor(root->right);
			root->key = tmp->key;
			root->right = deleteNode(root->right, tmp->key);
		}

		else
		{
			Node* tmp = root;
			if (root->left == nullptr)
				root = root->right;
			else
				root = root->left;
			delete tmp;
		}
	}

	if (root == nullptr)
		return root;
	root->height = max(height(root->left), height(root->right)) + 1;
	int balance = balanceFactor(root);

	if (balance > 1 && balanceFactor(root->left) >= 0)
		return rightRotate(root);

	if (balance > 1 && balanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	if (balance < -1 && balanceFactor(root->right) <= 0)
		return leftRotate(root);

	if (balance < -1 && balanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	return root;
}



int main()
{
	Node* root;
	init(root);

}
