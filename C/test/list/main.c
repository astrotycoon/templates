#include <stdio.h>
#include <stdlib.h>
#include <list.h>
#include <lobject/lassert.h>
#include <lobject/new.h>

struct mynode {
	list_head_t linker;
	int value;
};
int main()
{
	int i;
	struct mynode *itt;
	struct mynode *first;
	struct mynode *last;
	struct mynode *itt_tmp;
	list_head_t *head;
	list_head_t *new_head;

	puts("=====Test list_head_init, list_entry, list_add=====");
	list_head_t hdr[1];
	list_head_init(hdr);
	for (i = 0; i < 5; i++) {
		struct mynode *tmp = new(struct mynode);
		list_head_init(tmp);
		tmp->value = i;
		list_add_front(tmp, linker, hdr);
	}
	list_head_t *tmp = hdr->next;
	for (i = 0; i < 5; i++) {
		printf("i = %d : %d\n", i, list_entry(tmp, struct mynode)->value);
		tmp = tmp->next;
	}
	puts("=====Test list_end=====");
	for (itt = list_begin(hdr, struct mynode);
			itt != list_end(hdr, struct mynode);
					itt = list_next(itt)) {
		printf("%d\n", itt->value);
	}
	puts("=====Test list_delete=====");
	first = list_remove(list_entry(hdr->next, struct mynode));
	tmp = hdr->next;
	for (i = 0; i < 4; i++) {
		printf("i = %d : %d\n", i, list_entry(tmp, struct mynode)->value);
		tmp = tmp->next;
	}
	puts("=====Test list_begin=====");
	first = list_begin(hdr, struct mynode);
	printf("first mynode value = %d\n", first->value);
	puts("=====Test list_next=====");
	struct mynode * second = list_next(first);
	printf("second mynode value = %d\n", second->value);
	puts("=====Test list_end=====");
	for (itt = list_begin(hdr, struct mynode);
			itt != list_end(hdr, struct mynode);
					itt = list_next(itt)) {
		printf("%d\n", itt->value);
	}
	puts("=====Test list_prev, list_rbegin, list_rend=====");
	for (itt = list_rbegin(hdr, struct mynode);
			itt != list_rend(hdr, struct mynode);
					itt = list_prev(itt)) {
		printf("%d\n", itt->value);
	}
	puts("=====Test list_last=====");
	last = list_last(hdr, struct mynode);
		printf("%d\n", last->value);

	puts("=====Test list_for_each=====");
	list_for_each(itt, hdr) {
		printf("%d\n", itt->value);
	}

	puts("=====Test list_for_each_reverse=====");
	list_for_each_reverse(itt, hdr, linker) {
		printf("%d\n", itt->value);
	}
	
	puts("=====Test list_copy=====");
	list_head_t rethead[1];
	list_head_init(rethead);
	head = list_copy(hdr, struct mynode, linker);

	list_for_each_reverse(itt, head, linker) {
		printf("%d\n", itt->value);
	}

	puts("=====Test list_destroy=====");
	list_destroy(hdr, struct mynode, linker);
	list_for_each_reverse(itt, head, linker) {
		printf("%d\n", itt->value);
	}

	puts("=====Test list_del=====");
	list_del_front(head, struct mynode, linker);
	list_for_each_safe(itt, itt_tmp, head) {
		printf("%d\n", itt->value);
	}

	puts("=====Test list_for_each_safe=====");
	list_for_each_safe(itt, itt_tmp, head) {
		if (itt->value == 2) {
			new_head = list_split(itt, linker, head);
			break;
		}
	}

	puts("=====Test list_split=====");
	puts("head:");
	list_for_each_safe(itt, itt_tmp, head) {
		printf("%d\n", itt->value);
	}
	puts("new_head:");
	list_for_each_safe(itt, itt_tmp, new_head) {
		printf("%d\n", itt->value);
	}


	return 0;
}
