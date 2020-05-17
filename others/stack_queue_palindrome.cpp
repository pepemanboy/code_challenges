#include <iostream>
#include <stack>
#include <queue>

using namespace std;

bool isPalindrome(string str)
{
	stack<char> s;
	queue<char> q;

	for (char c : str)
	{
		s.push(c);
		q.push(c);
	}

	while (!q.empty())
	{
		if (s.top() != q.front())
			return false;
		s.pop();
		q.pop();
	}

	return true;
}

int main()
{
	string str;
	cin >> str;

	cout << isPalindrome(str) << endl;


	return 0;
}