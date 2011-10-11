#include <stdio.h>
#include <stack.h>
#include <lobject/lassert.h>

struct node {
	stack_node_t linker;
	int value;
};

int main()
{
	DECLARE_STACK(stack);
	struct node *node;
	struct node *itt;
	int i = 0;

	for (i = 0; i < 10; i++) {
		node = _new(struct node);
		stack_head_init(node, linker);
		node->value = i;
		list_add(node, stack);
	}	

	while (node = pop(stack, struct node)) {
		printf("%d\n", node->value);
		free(node);
	}

	return 0;
}
