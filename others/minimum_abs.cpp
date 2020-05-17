#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int minAbsDiff(vector<int> v)
{
	vector<int> d;
	for (int i = 1; i < v.size(); i++)
		d.push_back(v[i] - v[i-1]);

	int a = 0;
	int b = INT_MAX;

	for (int i = 0; i < d.size(); i ++)
	{
		a = abs(a+d[i]) < abs(d[i]) ? (a+d[i]) : d[i];
		if (abs(a) < abs(b))
			cout << a << endl;
		b = min(abs(b), abs(a));
	}

	return b;
}

int main()
{
	int n, x;
	vector<int> v;

	ifstream filename("minimum_abs_test_1.txt");
    string line;
    getline(filename, line);
    istringstream strm(line);
    strm >> n;

    while (getline(filename, line))
    {
        istringstream stream(line);
        while (stream.rdbuf()->in_avail())
        {
        	stream >> x;
        	v.push_back(x);
        }
    }
    /*

    cout << "n = " << n << endl;
    for (auto e : v)
    	cout << e << " ";
    cout << endl;*/

	cout << minAbsDiff(v) << endl;
	return 0;
}