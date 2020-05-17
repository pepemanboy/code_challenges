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

void propagate(vector<vector<int>> &a, Point2 &p, int initial_val, int final_val)
{
	// x
	for (int i = 0; i < a.size(); i ++)
	{
		if (a[i][p.y] == initial_val) // x
			a[i][p.y] = final_val;
		if (a[p.x][i] == initial_val) // y
			a[p.x][i] = final_val;
	}

	// diagonals
	vector<Point2>diagonals{{1,-1},{-1,-1},{1,1},{-1,1}};
	for (Point2 d: diagonals)
		for(int i = p.x, j = p.y; bounds(a.size(),{i,j}); i += d.x, j += d.y)
			if (a[i][j] == initial_val)
				a[i][j] = final_val;
}

int g_total = 0;

bool queensPropagation(vector<vector<int>> &a, vector<vector<int>> &c, Point2 &p)
{
	if (p.y >= 0)
	{
		if (p.y >= a.size())
			return true;

		if (!bounds(a.size(), p))
			return false;

		if (c[p.x][p.y] != 0)
			return false;

		a[p.x][p.y] = 1;
		propagate(c,p,0,p.y+1);
	}

	g_total++;

	for (int i = 0; i < a.size(); i ++)
	{
		Point2 n {i, p.y + 1};
		if (queensPropagation(a,c,n))
			return true;
	}

	if (p.y >= 0)
	{		
		propagate(c,p,p.y+1,0);
		a[p.x][p.y] = 0;
	}

	return false;
}

vector<vector<int>> solution(int n)
{
	vector<vector<int>> a(n,vector<int>(n,0));
	vector<vector<int>> c(n,vector<int>(n,0));
	Point2 p {0, -1};
	queensPropagation(a,c,p);
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