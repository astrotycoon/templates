#include <stdio.h>
#include <stdlib.h>
#include <lobject/lassert.h>
int main()
{
	int a = 0;
	int b = 1;
	int c = 2;
	DOOR(a);
	DOOR(a, b != 1);
	DOOR(a, b != 1, c != 2);
	puts("Hello world");
	return 0;
}
