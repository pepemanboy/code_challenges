#include <iostream>
#include <vector>

using namespace std;

 bool firstSubsetSum(vector<int> &choices, vector<int> &visited, vector<int> &result, int sum)
 {
 	if (sum < 0)
 		return false;

 	if (sum == 0)
 		return true;

 	for (int i = 0; i < choices.size(); i ++)
 	{
 		if (visited[i])
 			continue;

 		auto e = choices[i];
 		result.push_back(e);
 		visited[i] = 1; 
 		if (firstSubsetSum(choices, visited, result, sum - e))
 			return true;
 		result.pop_back();
 		visited[i] = 0;
 	}
 }

vector<int> solution(const vector<int> &v, int sum)
{
	vector<int> visited (v.size(), 0);
	vector<int> result;
	firstSubsetSum(v,visited,result,sum);
	return result;
}

int main()
{
	vector<int> v{1,2,3,6,4,5};
	int sum = 3;
	auto res = solution(v,sum);
	for (auto e : res)
		cout << e << " ";
	cout << endl;	

	return 0;
}