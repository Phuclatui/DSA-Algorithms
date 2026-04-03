#include<iostream>
#include<string>
#include<stack>
using namespace std;

void cal(stack <int>& a, const char& op)
{
	int y = a.top();
	a.pop();

	int x = a.top();
	a.pop();


	switch (op)
	{
	case '+':
	{
		a.push(x + y);
		break;
	}
	case '-':
	{
		a.push(x - y);
		break;
	}

	case '*':
	{
		a.push(x * y);
		break;
	}

	case '/':
	{
		a.push(x / y);
		break;
	}

	}
}

int priority(char c)
{
	if (c == '+' || c == '-')
		return 1;
	if (c == '*' || c == '/')
		return 2;
}

int main()
{
	string s{ "200+25*2-50/10+100" };

	stack <int> a;
	stack <char>b;

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int num = 0;
			while (s[i] >= '0' && s[i] <= '9')
			{
				num = num * 10 + (s[i] - '0');
				i++;
			}
			i--;
			a.push(num);
		}

		else
		{
			while (!b.empty() && priority(b.top()) >= priority(s[i]))
			{
				char op = b.top();
				b.pop();
				cal(a, op);
			}

			b.push(s[i]);
		}
	}

	while (!b.empty())
	{
		char op = b.top();
		b.pop();
		cal(a, op);
	}

	int temp = a.top();
	cout << s << " = " << temp << endl;
	return 0;
}