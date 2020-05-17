#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
	stack<char> s;
	for (auto c : str)
	{
		if (c == '(' || c == '{' || c == '[')
		{
			s.push(c);
		}
		else
		{
			switch(c)
			{
				case ')' : 
					if (s.top() != '(') 
						return false;
					break;
				case '}' :
					if (s.top() != '{')
						return false;
					break;
				case ']' :
					if (s.top() != '[')
						return false;
					break;
			}
			s.pop();
		}
	}
	return s.empty();
}

int main()
{
	string str;
	cin >> str;
	bool b = solution(str);
	cout << (b ? "balanced" : "unbalanced") << endl;
	return 0;
}