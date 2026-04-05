#include<iostream>
#include<iomanip>
#include<string>
#define M 101
using namespace std;

struct Product
{
	int id;
	string name;
	double price;
};

struct Node
{
	Product product;
	int link;
	int freq;
};


void init_cart(Node cart[])
{
	for (int i = 0; i < M; i++)
	{
		cart[i].freq = 0;
		cart[i].link = -1;
		cart[i].product.id = -1;
		cart[i].product.name = "null";
		cart[i].product.price = -1;
	}
}

double sum_all_product(Node cart[])
{
	double sum = 0;
	for (int i = 0; i < M; i++)
		if (cart[i].product.id != -1)
			sum += (cart[i].product.price * cart[i].freq);
	return sum;
}

void export_cart(Node cart[])
{
	int stt = 1;
	cout <<  left << setw(10)<< "Number" 
		<<left << setw(10) << "ID"
		<< left << setw(20) << "Name Product"
		<< left << setw(20) << "Product price"
		<< left << setw(20) << "Quantity"
		<< left << setw(20) << "Price" << endl;
	cout << string(90, '-') << endl;
	for (int i = 0; i < M; i++)
	{
		if (cart[i].product.id != -1)
		{
			cout  <<left << setw(10) << stt++ 
				<< left << setw(10) << cart[i].product.id
				<<left << setw(20) << cart[i].product.name
				<< left << setw(20) << cart[i].product.price
				<< left << setw(20) << cart[i].freq
				<< left << setw(20) << cart[i].freq * cart[i].product.price << endl;
			cout << string(90, '-') << endl;
		}
	}


	double sum = sum_all_product(cart);
	cout << "\033[32m " << "SUM" << right << setw(73) << sum  << "\033[0m" << endl;
}



int hash_function(const int& id)
{
	return id % M;
}

void add_product(Node cart[], const Product& item)
{
	int idx = hash_function(item.id);

	if (cart[idx].product.id == -1)
	{
		cart[idx].product = { item.id, item.name, item.price };
		cart[idx].freq = 1;
	}
	else if (cart[idx].product.id == item.id)
		cart[idx].freq++;
	else
	{
		while (cart[idx].link != -1)
		{
			idx = cart[idx].link;

			if (cart[idx].product.id == item.id)
			{
				cart[idx].freq++;
				return;
			}
		}

		int avaiable = -1;
		for (int i = M - 1; i >= 0; i--)
		{
			if (cart[i].product.id == -1)
			{
				avaiable = i;
				break;
			}
		}

		if (avaiable >= 0)
		{
			cart[avaiable].product = { item.id, item.name, item.price };
			cart[avaiable].freq = 1;
			cart[idx].link = avaiable;
		}
		else
			cout << "you are not customer, you are tester!!!" << endl;
	}
}

int search_item (Node cart[], const int &id)
{
	int idx = hash_function(id);

	while (idx >= 0 && cart[idx].product.id != id)
		idx = cart[idx].link;

	return idx;
 }

void delete_item(Node cart[], const int& id)
{
	int idx = hash_function(id);
	int previous = -1;
	while (idx >= 0 && cart[idx].product.id != id)
	{
		previous = idx;
		idx = cart[idx].link;

	}
	if (idx >= 0)
	{
		if (cart[idx].freq > 1)
		{
			cart[idx].freq--;
			return;
		}

		if (previous >= 0)
		{
			cart[previous].link = cart[idx].link;
			cart[idx].product = { -1,"null",-1 };
			cart[idx].freq = -1;
			cart[idx].link = -1;
		}
		else
		{
			int newindex = cart[idx].link;
			if (newindex >= 0)
			{
				cart[idx] = cart[newindex];
				cart[newindex].product = { -1,"null",-1 };
				cart[newindex].freq = -1;
				cart[newindex].link = -1;
			}
			else
			{
				cart[idx].product = { -1,"null",-1 };
				cart[idx].freq = -1;
				cart[idx].link = -1;
			}
		}
	}
	else
		cout << "The item is not exist to delete!!!" << endl;
}

void menu()
{
	cout << "-------------Bang gia san pham-----------------\n";
	cout << "|  1 | Gao ST25 (5kg)        | 180000 |\n"
		<< "|  2 | Mi tom Hao Hao        |  4500  |\n"
		<< "|  3 | Sua tuoi Vinamilk     | 32000  |\n"
		<< "|  4 | Trung ga (10 qua)     | 38000  |\n"
		<< "|  5 | Dau an Tuong An       | 52000  |\n"
		<< "|  6 | Nuoc mam Nam Ngu      | 29000  |\n"
		<< "|  7 | Duong Bien Hoa        | 27000  |\n"
		<< "|  8 | Banh Oreo             | 15000  |\n"
		<< "|  9 | Nuoc ngot Coca        | 11000  |\n"
		<< "| 10 | Ca phe G7             | 65000  |\n"
		<< "|0. Delete item                        \n";
}

void table_of_product(Node cart[])
{
	menu();

	do
	{
		int x;
		cout << "Enter your choose(-1 to exit): ";
		cin >> x;
		cin.ignore();

		if (x == -1)
			return;

		switch (x)
		{
		case 0:
		{
			do
			{
				int id;
				cout << "Enter id to delete item(-1 to return menu): ";
				cin >> id;
				cin.ignore();
				if (id == -1)
				{
					menu();
					break;
				}
				int searchItem = search_item(cart, id);

				if (searchItem != -1)
				{
					delete_item(cart, id);
					export_cart(cart);
				}
				else
					cout << "Dont have item to delete!!!" << endl;
			} while (true);
			break;
		}
		case 1:
		{
		
			add_product(cart, { 1,"Gao ST25 (5kg)",180000 });
			export_cart(cart);
			break;
		}

		case 2:
		{

			add_product(cart, { 2,"Mi tom Hao Hao",4500 });
			export_cart(cart);
			break;
		}

		case 3:
		{
			add_product(cart, { 3,"Sua tuoi Vinamilk",32000 });
			export_cart(cart);
			break;
		}

		case 4:
		{
			add_product(cart, { 4,"Trung ga (10 qua)",38000 });
			export_cart(cart);
			break;
		}


		case 5:
		{
			add_product(cart, { 5,"Dau an Tuong An",52000 });
			export_cart(cart);
			break;
		}

		case 6:
		{
			add_product(cart, { 6,"Nuoc mam Nam Ngu ",29000 });
			export_cart(cart);
			break;
		}

		case 7:
		{
			add_product(cart, { 7,"Duong Bien Hoa ",27000 });
			export_cart(cart);
			break;
		}

		case 8:
		{
			
			add_product(cart, { 8,"Banh Oreo ",15000 });
			export_cart(cart);
			break;
		}

		case 9:
		{
			
			add_product(cart, { 9,"Nuoc ngot Coca",11000 });
			export_cart(cart);
			break;
		}

		case 10:
		{
			
			add_product(cart, { 10,"Ca phe G7 ",65000 });
			export_cart(cart);
			break;
		}

		default:
		{
			cout << "the item is not exist!!!" << endl;
			break;
		}
		}
	} while (true);


}

int main()
{
	Node cart[M];
	init_cart(cart);
	table_of_product(cart);
}