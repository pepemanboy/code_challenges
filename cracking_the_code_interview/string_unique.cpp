/**
Implement an algorithm to determine if a string has all unique characters. What
if you cannot use additional data structures?
*/

#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

// Using set as auxiliary data structure. O(n*log(n))
bool onlyUniqueCharsInString_1(string str)
{
	set<char> s;
	for (char c : str)
		s.insert(c);
	return s.size() == str.length();
}

// Using hash map as auxiliary data structure. O(n)
bool onlyUniqueCharsInString_2(string str)
{
	unordered_map<char,int> m;
	for (char c : str)
		if (0 < m[c]++)
			return false;
	return true;
}

// Not using an auxiliary data structure. O(n^2)
bool onlyUniqueCharsInString(string str)
{
	for (char c: str)
		if (str.find_first_of(c) != str.find_last_of(c))
			return false;
	return true;
}

int main()
{
	string s;
	cin >> s;
	cout << onlyUniqueCharsInString(s)

	return 0;
}