#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

using namespace std;

struct Cake
{
	int weight;
	int value;
};

typedef struct Cake Cake;

int cakes(vector<Cake> &cakes, int w)
{
	vector<int> b(w+1, 0);
	for(int i = 1; i <= w; i++)
	{
		int m = 0;
		for (auto cake : cakes)
			if (i >= cake.weight)
				m = max(cake.value + b[i-cake.weight], m);
		b[i] = m;
	}
	return b[w];
}

int main()
{
	vector<Cake> v = {{7,160},{3,90},{2,15}};
	int w = 20;
	cout << cakes(v,w) << endl;
	return 0;
}