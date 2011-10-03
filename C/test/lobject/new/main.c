#include <stdio.h>
#include <lobject/new.h>
#include <lobject/lassert.h>
struct node {
	int a;
	int b;
};
void show(struct node * node)
{
	printf("%d\t%d\n",node->a,node->b);
}
int main()
{
	DOOR(0, 1, 2, 0);
	struct node *node_a;
	node_a = new(struct node);
	node_a->a = 0;
	node_a->b = 10;
	show(node_a);
	struct node *array;
	array = new(struct node, 4);
	puts("");
	int i;
	for (i = 0; i < 4; i++) {
		array[i].a = 0;
		array[i].b = 10;
	}
	for (i = 0; i < 4; i++) {
		show(array + i);
	}
}
