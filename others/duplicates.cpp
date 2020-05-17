#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
	if (n <= 1) return 1;
	return n * factorial (n-1);
}
int solution(vector<int> &v)
{
	int m = factorial(v.size());
	for (auto elem : v)
	{
		if (m % elem != 0)
			return elem;
		m /= elem;
	}
	return 0;
}

int main()
{
	vector<int> v{1,2,2,4,2};
	cout << solution(v) << endl;

	return 0;
}