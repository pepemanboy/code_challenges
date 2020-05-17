/**
A Maze is given as N*N binary matrix of blocks where source block is the upper left most block 
i.e., maze[0][0] and destination block is lower rightmost block i.e., maze[N-1][N-1]. 
A rat starts from source and has to reach the destination. 
The rat can move only in two directions: forward and down.
In the maze matrix, 0 means the block is a dead end and 1 means 
the block can be used in the path from source to destination. 
Note that this is a simple version of the typical Maze problem.
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

vector<Point2> valid_moves = {{1,0},{0,1}};

bool isValidSquare(vector<vector<int>> &a, Point2 &p)
{
    return ((p.x < a.size() && p.y < a[0].size()) &&
            ((p.x >= 0) && (p.y >= 0)) &&
            (a[p.x][p.y] == 1));
}

bool mazeBacktrack(vector<vector<int>> &a, vector<vector<int>> &b, Point2 p)
{
    if (!isValidSquare(a,p))
        return false;

    b[p.x][p.y] = 1;

    if (p.x == a.size()-1 && p.y == a[0].size()-1)
        return true;

    for (Point2 m : valid_moves)
    {
        Point2 n {p.x + m.x, p.y + m.y};
        if (mazeBacktrack(a,b,n))
            return true;
    }    

    b[p.x][p.y] = 0;  
    return false;  
}

vector<vector<int>> solution(vector<vector<int>> &a)
{
    vector<vector<int>> b (a.size(), vector<int>(a[0].size(), 0));
    mazeBacktrack(a,b,{0,0});    
    return b;
}

int main()
{
    vector<vector<int>> a {{1,1,1,0},
                           {1,1,1,1},
                           {1,0,1,1},
                           {1,1,0,1}};
    vector<vector<int>> b;
    b = solution(a);
    print2DVector<int>(a);
    print2DVector<int>(b);
    return 0;
}