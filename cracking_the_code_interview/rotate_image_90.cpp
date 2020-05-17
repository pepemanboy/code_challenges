/**
Given an image represented by an NxN matrix, where each pixel in the image is
4 bytes, write a method to rotate the image by 90 degrees. Can you do this in
place?
*/

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

typedef int Pixel;

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

// Rotate image 90deg clockwise. Time O(n^2), Space O(1)
void rotateImage(vector<vector<Pixel>> &v)
{
	for (int i = 0; i < ceil(v.size()/2.0); i++)
	{
		for (int j = 0; j < v.size()/2; j++)
		{
			int n = v.size() - 1;

			int i_2 = j, j_2 = n - i;
			int i_3 = n - i, j_3 = n - j;
			int i_4 = n - j, j_4 = i;

			Pixel tmp = v[i_2][j_2];
			v[i_2][j_2] = v[i][j];
			v[i][j] = v[i_4][j_4];
			v[i_4][j_4] = v[i_3][j_3];
			v[i_3][j_3] = tmp;
		}
	}
}

int main()
{
	vector<vector<Pixel>> v1 = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
	print2DVector<Pixel>(v1);
	rotateImage(v1);
	print2DVector<Pixel>(v1);


	vector<vector<Pixel>> v2 = {{1,2,3},{4,5,6},{7,8,9}};
	print2DVector<Pixel>(v2);
	rotateImage(v2);
	print2DVector<Pixel>(v2);

	vector<vector<Pixel>> v3 = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
	print2DVector<Pixel>(v3);
	rotateImage(v3);
	print2DVector<Pixel>(v3);

	return 0;
}