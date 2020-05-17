#include <iostream>
#include <algorithm>
#include<bits/stdc++.h> 

using namespace std;

int egg(int n, int k, vector<vector<int>> &v, vector<int> &p)
{
		if (k < 1)
			return 0;

		if (v[n-1][k-1] != -1)
			return v[n-1][k-1];

		if (n == 1 || k == 1)
		{
			v[n-1][k-1] = k;
			return k;
		}
		else
		{
			int m = INT_MAX;
			for (int j = 1; j <= k; j++)
			{
				int b = 1 + egg(n-1, j-1, v, p); // breaks in floor j
				int nb = 1 + egg(n, k-j, v, p); // does not break in floor j
				// For printing
				if ((max(b,nb) <= m) && (n == v.size()))
					p[k-1] = k-j;
				// Update min
				m = min(m,max(b,nb));					
			}
			v[n-1][k-1] = m;
			return m;
		}
}

int solution(int n, int k)
{
	vector<vector<int>> v(n,vector<int>(k,-1));
	vector<int> p(k, 0);
	int res = egg(n,k,v,p);

	// Print solution
	int r = k;
	int b = 0;
	while (r > 0)
	{
		b += r- p[r-1];
		cout << b << " ";
		r = p[r-1];
	}
	cout << endl;

	return res;
}

int main()
{
	int n,k;
	cin >> n >> k;
	cout << solution(n,k) << endl;
	return 0;
}