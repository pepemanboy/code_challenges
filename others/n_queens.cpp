/**
The N Queen is the problem of placing N chess queens on an 
N×N chessboard so that no two queens attack each other. 
*/

#include <iostream>
#include <vector>

using namespace std;

// Helper function to print 2D vector
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

struct Point2
{
    int x;
    int y;
};
typedef struct Point2 Point2;

bool bounds (int n, Point2 p)
{
	return ((p.x) < n && 
		    (p.y) < n && 
		    (p.x) >= 0 && 
		    (p.y) >= 0);
}

bool isSafe(vector<vector<int>> &a, Point2 &p)
{
	// Check position
	if (!bounds(a.size(), p))
		return false;

	// Check x
	for (int i = 0; i < a.size(); i ++)
		if (a[i][p.y] == 1)
			return false;

	// Check y
	for (int i = 0; i < a.size(); i ++)
		if (a[p.x][i] == 1)
			return false;

	// Check diagonals
	vector<Point2>diagonals{{1,-1},{-1,-1}};
	for (Point2 d: diagonals)
		for(int i = p.x, j = p.y; bounds(a.size(),{i,j}); i += d.x, j += d.y)
			if (a[i][j] == 1)
				return false;

	return true;
}

int g_total = 0;

bool queensBacktrack(vector<vector<int>> &a, Point2 &p)
{
	if (p.y >= 0)
	{
		if (p.y >= a.size())
			return true;

		if (!isSafe(a,p))
			return false;

		a[p.x][p.y] = 1;
	}

	g_total++;

	for (int i = 0; i < a.size(); i ++)
	{
		Point2 n {i, p.y + 1};
		if (queensBacktrack(a,n))
			return true;
	}

	if (p.y >= 0)
		a[p.x][p.y] = 0;

	return false;
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> a(n,vector<int>(n,0));
	Point2 p {0, -1};
	queensBacktrack(a,p);
	return a;
}

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> a;
	a = solution(n);
	print2DVector<int>(a);
	cout << g_total << endl;
	return 0;
}