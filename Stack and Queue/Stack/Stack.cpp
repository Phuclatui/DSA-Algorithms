#include <iostream>
#include<stack>
using namespace std;

void cal(stack <int> &a, char op)
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
		{
			a.push(x - y);
			break;
		}
	}
	}
}



int main()
{
	stack<int>a;
	stack<int>b;

	string s{ "225+25-50-100" };

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			a.push(s[i] - '0');
		else
		{
			if (!b.empty())
			{
				char op = b.top();
				b.pop();
				cal(a, op);
			}
				b.push(s[i]);
		}
	}

	if (!b.empty())
	{
		char op = b.top();
		b.pop();
		cal(a, op);
	}
	
	int result = a.top();
	a.pop();


	cout << s << " = " << result << endl;

}