#include <iostream>

using namespace std;

int nStairs(int n)
{
	if (n < 0)
		return 0;
	if (n == 0)
		return 1;
	return nStairs(n-1) + nStairs(n-2) + nStairs(n-3);
}

int solution(int n)
{
	return nStairs(n);
}

int main()
{
	int n;
	cin >> n;
	cout << solution(n) << endl;
	return 0;
}