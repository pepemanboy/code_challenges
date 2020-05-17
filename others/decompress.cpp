/**
https://techdevguide.withgoogle.com/resources/compress-decompression/#!
*/

#include <iostream>

using namespace std;

string decompress(string str, int start)
{
	string res = "";
	int n = 0;
	for (int i = start; i < str.size(); i ++)
	{
		char c = str[i];
		if (isalpha(c))
			res += c;
		else if (isdigit(c))
			n = n*10 + c - '0';
		else if (c == '[')
		{
			string s = decompress(str, i+1);
			for (int j = 0; j < n; j++)
				res += s;
			i += s.size() + 1;
			n = 0;
		}
		else if (c == ']')
			return res;
	}
	return res;
}

string solution(string str)
{
	return decompress(str, 0);
}

int main()
{
	string str;
	cin >> str;
	cout << solution(str) << endl;

	return 0;
}