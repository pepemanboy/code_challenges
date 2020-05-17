#include <iostream>

using namespace std;

void printReverse(const char * c)
{
	if (*c == 0)
		return;

	printReverse(c+1);
	cout << *c;
}

int main()
{
	char buf[100];
	cin.getline(buf,sizeof(buf));
	cout << buf << endl;
	printReverse(buf);
	cout << endl;
	return 0;
}