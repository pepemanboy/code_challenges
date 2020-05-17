#include <iostream>
#include <stdlib.h>

using namespace std;

int rand5()
{
	return rand()%5 + 1;
}

int rand7()
{
	while (1)
	{
		int a = rand5();
		int b = rand5();
		if (a == 1 && b == 1) return 1;
		else if (a == 1 && b == 2) return 2;
		else if (a == 1 && b == 3) return 3;
		else if (a == 1 && b == 4) return 4;
		else if (a == 1 && b == 5) return 5;
		else if (a == 2 && b == 1) return 6;
		else if (a == 2 && b == 2) return 7;
	}
}

int main()
{	
	srand (time(NULL));
	cout << rand7() << endl;
	return 0;
}