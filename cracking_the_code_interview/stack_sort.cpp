/**
Write a program to sort a stack in ascending order (with biggest items on top).
You may use at most one additional stack to hold items, but you may not copy
the elements into any other data structure (such as an array). The stack supports
the following operations: push, pop, peek, and isEmpty.
*/

#include <iostream>
#include <stack>
#include<bits/stdc++.h> 

using namespace std;

template <class T>
void printStack(stack<T> s)
{
	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

void stackSort(stack<int> &a)
{
	stack<int> b;
	bool finished = false;
	while (!finished)
	{
		int tmp = INT_MAX;
		while (!a.empty() && ((!b.empty() && a.top() < b.top()) || b.empty()))
			b.push(a.top()), a.pop();

		if (!a.empty())
			tmp = a.top(), a.pop();
		
		if (a.empty())
			finished = true;

		while (!b.empty() && (b.top() <= tmp))
			a.push(b.top()), b.pop();

		if (tmp != INT_MAX)
			a.push(tmp);

		while (!b.empty())
			a.push(b.top()), b.pop();
	}

	return;
}

int main()
{

	stack<int> s;
	for (auto& e : {1,5,2,6,3,4,7})
        s.push(e);

	printStack<int>(s);
	stackSort(s);
	cout << "HHA" << endl;
	printStack<int>(s);

	return 0;
}