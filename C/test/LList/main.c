#include <stdio.h>
#include <LList.h>

struct node {
	int value;
};

int main()
{
	int i;

	LList(struct node) *list = new(LList(struct node));
	LList_init(list);

	for (i = 0; i < 10; i++) {
		struct node node;
		node.value = 10 * (i + 1);
		LList_append(node, list);
	}

	struct node *itt;
	for (itt = LList_begin(list);
			itt != LList_end(list);
			itt = LList_next(itt, list)) {
		printf("%d\n", itt->value);
	}

	return 0;
}
