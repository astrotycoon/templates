#include <stdio.h>
#include <deque.h>

struct node {
	deque_node_t linker;
	int value;
};

int main()
{
	DECLARE_DEQUE(deque);
	struct node *node, *itt;
	int i;

	for (i = 0; i < 10; i++) {
		node = new(struct node);
		deque_head_init(node);
		node->value = i;
		enqueue(node, deque);
	}
	while (itt = dequeue_tail(deque, struct node)) {
		printf("%d\n", itt->value);
		free(itt);
	}

	for (i = 0; i < 10; i++) {
		node = new(struct node);
		deque_head_init(node);
		node->value = i;
		enqueue_front(node, deque);
	}
	while (itt = dequeue(deque, struct node)) {
		printf("%d\n", itt->value);
		free(itt);
	}
	return 0;
}
