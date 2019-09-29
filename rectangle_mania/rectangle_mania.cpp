#include "iostream"
#include <utility> 
#include <vector>
#include <map>

using namespace std;

typedef pair<int,int> Point;
typedef pair<Point,double> Edge;

int solution(vector<Point> v)
{
	map<Edge,int> count;
	int answer = 0;
	for (Point p : v)
	{
		for (Point p_above : v)
		{
			if (p.second < p_above.second && p_above.first >= p.first)
			{
				// Calculate vector p -> p_above
				Point vec{p_above.first - p.first, p_above.second - p.second};

				// Calculate y intercept of a line perpendicular to the vector
				double slope = (double)(vec.second) / (vec.first);
				double orthogonal_slope = -1 / slope;
				double mid_point_x = (double)(p_above.first + p.first) / 2;
				double mid_point_y = (double)(p_above.second + p.second) / 2;
				double orthogonal_y_intercept = -orthogonal_slope * mid_point_x + mid_point_y;

				Edge e{vec, orthogonal_y_intercept};				
				answer += count[e];
				count[e]++;
			}
		}
	}

	return answer;
}

// Tests
int main()
{
	vector<Point>v1 = {{0,0},{1,0},{2,0},
					  {0,1},{1,1},{2,1},
					  {0,2},{1,2},{2,2},
					  {0,3},{1,3},{2,3},{3,2}};

	vector<Point>v2 = {{0,0},{1,0},{2,0},{3,0},
					  {0,1},{1,1},{2,1},{3,1},
					  {0,2},{1,2},{2,2},{3,2},
					  {0,3},{1,3},{2,3},{3,3}};

	cout << solution(v1) << endl; 
	cout << solution(v2) << endl;

	return 0;
}