/**
https://techdevguide.withgoogle.com/resources/former-coding-interview-question-word-squares/#code-challenge
*/

#include <iostream>
#include <vector>

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

void wordSquare(vector<string> &v, vector<string> &b, vector<vector<string>> & result)
{
	int k = b.size();
	for (int i = 0; i < k - 1; i++)
		if (b[k-1][i] != b[i][k-1])
			return;

	if (k > 0 && k == b[0].size())
	{
		result.push_back(b);
		return;
	}

	for (auto word : v)
	{
		if (k > 0 && word.size() != b[0].size())
			continue;
		b.push_back(word);
		wordSquare(v,b,result);			
		b.pop_back();
	}
}

vector<vector<string>> solution(vector<string> &v)
{
	vector<string> b;
	vector<vector<string>> result;
	wordSquare(v,b,result);
	return result;
}

int main()
{
	vector<string> v = {"AREA", "BALL", "DEAR", "LADY", "LEAD", "YARD"};
	auto res = solution(v);
	print2DVector(res);
	return 0;
}