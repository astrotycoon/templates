#define FAST_UPCAST
#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <lassert.h>
extern int print();
struct node {
	__linked_as_list__
	int value;
};

int main()
{
	print();
	int a = 0;
	//DOOR(a, 1, 2);
	struct node *head = list_new_head(struct node);
	list_head_t *list;
	list = malloc(sizeof(list_head_t));
	list_head_init(list);
	int i = 6;
	while (i--) {
		struct node *temp = malloc(sizeof(struct node));
		temp->value = i;
		list_insert_after(head, temp);
	}
	struct node *it;
	list_for_each(it, head) {
		printf("%d\n", it->value);
	}

	struct node *new_last  = malloc(sizeof(struct node));
	new_last->value = 100;
	struct node *last = list_prev(head);
	list_replace(last, new_last);

	puts("After replace");
	free(last);
	list_for_each(it, head) {
		printf("%d\n", it->value);
	}
	return 0;
}
