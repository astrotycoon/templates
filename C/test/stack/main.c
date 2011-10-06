#include <stdio.h>
#include <stack.h>
#include <lobject/lassert.h>

struct node {
	stack_head_t linker;
	int value;
};

int main()
{
	stack_head_t stack[1];	
	struct node *node;
	struct node *itt;
	int i = 0;

	stack_head_init(stack);
	for (i = 0; i < 10; i++) {
		node = new(struct node);
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
