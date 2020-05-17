/**
Given three numbers sum S, prime P and N, find all N prime numbers after prime P such that their sum is equal to S.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

template <class T>
void print2DVector(vector<vector<T>> &v)
{
    for (auto row : v)
    {
        for (auto elem : row)
            cout << elem << " ";
        cout << endl;
    }       
    cout << endl;
}

bool isPrime(int n)
{
	if (n == 1)
		return false;

	for (int i = 2; i <= (int)sqrt(n); i ++)
		if (n % i == 0)
			return false;

	return true;
}

int nextPrime(int n)
{
	while(!isPrime(++n)){}
	return n;		
}

void primeSum(int n, int p, int s, vector<int> &primes, int pi, vector<int>&v, vector<vector<int>> &result)
{
	if (n == 0)
	{
		if (s == 0)
			result.push_back(v);
		return;
	}

	for(; pi < primes.size(); pi++)
	{
		int prime = primes[pi];	
		int sum = s-prime;	

		if (sum < 0)
			break;

		v.push_back(prime);
		primeSum(n-1, prime, sum, primes, pi+1, v, result);
		v.pop_back();
	}
}

vector<vector<int>> solution(int n, int p, int s)
{
	// Generate primes, can be replaced by sieve of erathosthenes
	vector<int> primes;
	int x = p;
	while((x = nextPrime(x)) - p < s)
		primes.push_back(x);

	vector<vector<int>> result;
	vector<int> v;
	primeSum(n, p, s, primes, 0, v, result);

	return result;
}

int main()
{
	int n, p, s;
	cin >> n >> p >> s;

	vector<vector<int>> v = solution(n,p,s);
	print2DVector(v);

	return 0;
}