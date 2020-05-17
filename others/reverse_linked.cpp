#include <iostream>

using namespace std;

class Node
{
public:
	Node * next;
	int data;

public:
	Node (int d, Node * n):data(d),next(n){}
	Node (int d):data(d), next(nullptr){}
	Node ():data(0), next(nullptr){}
};

void solution(Node & list)
{
	Node * prev = nullptr, * next = nullptr;
	Node * n = &list;

	while (n != nullptr )
	{
		next = n->next;
		n->next = prev;
		prev = n;
		n = next;
	}
}

void printLinkedList(Node & list)
{
	Node * n = &list;
	int i = 0;
	while (n != nullptr && i++ < 10)
	{
		cout << n->data << " ";
		n = n->next;
	}
	cout << endl;
}

int main()
{
	Node a (4, nullptr);
	Node b (3, &a);
	Node c (2, &b);
	Node d (1, &c);
	printLinkedList(d);
	solution(d);
	printLinkedList(a);



	return 0;
}