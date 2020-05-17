#include <stdio.h>

struct{
	int x;
	int y;
} p1;

int main()
{
	p1.x = 1;
	p1.y = 2;
	printf("[%d,%d]\n", p1.x, p1.y);
}