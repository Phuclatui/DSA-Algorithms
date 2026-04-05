#include<iostream>
#include<string>
#include<iomanip>
#define M 103
using namespace std;

struct Word
{
	string word;
	string type;
	string meaning;
};

struct Node
{
	Word info;
	Node* right, * left;
};

void init(Node*& root)
{
	root = nullptr;
}

void init_dictionary(Node* dictionary[])
{
	for (int i = 0; i < M; i++)
		init(dictionary[i]);
}

Node* createNode(const Word& word)
{
	Node* p = new Node;
	p->info.meaning = word.meaning;
	p->info.type = word.type;
	p->info.word = word.word;

	p->left = nullptr;
	p->right = nullptr;
	return p;
}

void add_Node(Node*& root, const Word& word)
{
	if (root == nullptr)
		root = createNode(word);
	else if (root->info.word > word.word)
		add_Node(root->left, word);
	else
		add_Node(root->right, word);
}

int hash_func(const string& word)
{
	int h = 0;
	for (int i = 0; i < word.size(); i++)
		h += (int)tolower(word[i]) * (i + 1);
	return h % M;
}

Node* search_Node(Node* root, const string& w)
{
	if (root != nullptr)
	{
		if (root->info.word == w)
			return root;
		else if (root->info.word > w)
			return search_Node(root->left, w);
		else
			return search_Node(root->right, w);
	}
	return nullptr;
}

void add_Word(Node* dictionary[], const Word& w)
{
	int idx = hash_func(w.word);
	add_Node(dictionary[idx], w);
}

void lnr(Node* root)
{
	if (root != nullptr)
	{
		lnr(root->left);
		cout << left << setw(10) << "Word: " << root->info.word << "| "
			<< left << setw(10) << "Type: " << root->info.type << "| "
			<< "Meaning: " << root->info.meaning << endl;
		lnr(root->right);
	}
}



void output_dictionary(Node* dictionary[])
{
	for (int i = 0; i < M; i++)
		if (dictionary[i] != nullptr)
		{
			cout << "Bucket " << i << ": " << endl;
			lnr(dictionary[i]);
			cout << endl;
		}
}


void show_word(Node* dictionary[], const string& x)
{
	int idx = hash_func(x);
	Node* p = search_Node(dictionary[idx], x);

	if (p == nullptr)
		cout << "The word is not exist!!!" << endl;
	else
	{
		cout << left << setw(10) << "Word: " << p->info.word << "| "
			<< left << setw(10) << "Type: " << p->info.type << "| "
			<< "Meaning: " << p->info.meaning << endl;
	}
}


void deleteNode(Node*& root, const string& x)
{
	if (root != nullptr)
	{
		if (root->info.word > x)
			deleteNode(root->left, x);
		else if (root->info.word < x)
			deleteNode(root->right, x);
		else
		{
			if (root->left != nullptr && root->right != nullptr)
			{
				Node* p = root->right;
				while (p->left != nullptr)
					p = p->left;

				root->info = p->info;
				deleteNode(root->right, p->info.word);
			}
			else
			{
				Node* p = root;
				if (root->left == nullptr)
					root = root->right;
				else
					root = root->left;
				delete p;
			}
		}
	}
}

void delete_Word(Node* dictionary[], const string& w)
{
	int idx = hash_func(w);
	Node* p = search_Node(dictionary[idx], w);

	if (p == nullptr)
		cout << "The word dont have exist to delete!!!" << endl;
	else
	{
		deleteNode(dictionary[idx], w);
		cout << "DELETE SUCCESSFULLY" << endl;
		output_dictionary(dictionary);
	}
}

bool checkduplicate(Node* dictionary[], const string& word)
{
	int idx = hash_func(word);
	Node* p = search_Node(dictionary[idx], word);
	if (p != nullptr)
	{
		cout << "The word is duplicate, please try another one!!!" << endl;
		return false;
	}
	return true;
}


int main()
{
	Node* dictionary[M];
	init_dictionary(dictionary);

	do
	{
		int t;
		cout << "MENU\n"
			<< "1.Add Word\n"
			<< "2.Find Word\n"
			<< "3.Delete Word\n"
			<< "4.Show dictionary\n"
			<< "-1. Exit\n";
		cout << "Enter: ";
		cin >> t;
		cin.ignore();
		if (t == -1)
			return 0;

		switch (t)
		{
		case 1:
		{
			cout << "Enter -1 to return to the menu: " << endl;
			do
			{
				string word;
				string type;
				string meaning;

				cout << "Enter word: ";
				getline(cin, word);
				if (word == "-1")
					break;

				if (!checkduplicate(dictionary, word))
					continue;

				cout << "Add type of " << "\033[32m" << word << "\033[0m" << ": ";
				getline(cin, type);

				cout << "Add meaning of " << "\033[32m" << word << "\033[0m" << ": ";
				getline(cin, meaning);

				add_Word(dictionary, { word, type, meaning });
				output_dictionary(dictionary);

			} while (true);
			break;

		}
		case 2:
		{
			cout << "Enter -1 to return to the menu: " << endl;
			do
			{
				string find;
				cout << "Enter word to find: ";
				getline(cin, find);
				if (find == "-1")
					break;

				show_word(dictionary, find);
			} while (true);
			break;
		}
		case 3:
		{
			cout << "Enter -1 to return to the menu: " << endl;
			do
			{
				string deleteWord;
				cout << "Enter word to delete: ";
				getline(cin, deleteWord);
				if (deleteWord == "-1")
					break;

				delete_Word(dictionary, deleteWord);
			} while (true);
			break;
		}
		case 4:
		{
			output_dictionary(dictionary);
			break;
		}
		}
	} while (true);
}