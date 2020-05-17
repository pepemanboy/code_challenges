/**
https://www.youtube.com/watch?v=GBuHSRDGZBY
*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

pair<int,int> solution(vector<int> v1, vector<int> v2, int sum)
{
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	int i = v1.size() - 1, j = 0;
	pair<int,int>m {0,0};
	while (i >= 0 && j < v2.size())
	{
		int s = v1[i] + v2[j];
		if (s == sum)
			return pair<int,int>{v1[i],v2[j]};

		if (abs(sum-(m.first + m.second)) > abs(sum-s))
		{
			m.first = v1[i];
			m.second = v2[j];
		}

		if (s < sum)
			j++;
		else if (s > sum)
			i--;
	}
	return m;
}

int main()
{
	vector<int> v1 {3,5,1,0,177};
	vector<int> v2 {-1,6,3,9,10};
	int sum = -55;
	auto result = solution(v1,v2,sum);
	cout << result.first << " " << result.second << endl;
	return 0;
}