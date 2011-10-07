#include <stdio.h>
#include <queue.h>
struct node {
	queue_node_t linker;
	int value;
};
#define INT(name)							\
	struct {                                                        \
		name value;                                             \
	}
int main()
{
	DECLARE_QUEUE(queue);
	struct node *node, *itt;
	int i;

	for (i = 0; i < 10; i++) {
		node = new(struct node);
		queue_head_init(node);
		node->value = i;
		enqueue(node, queue);
	}

	while (node = dequeue(queue, struct node)) {
		printf("%d\n", node->value);
	}

	return 0;
}
