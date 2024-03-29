#ifndef _LIST_PRIVATE_H_
#define _LIST_PRIVATE_H_
#include <stdlib.h>
#include <lobject/container-of.h>
#include <memory.h>
struct __double_list {
	struct __double_list * next;
	struct __double_list * prev;	
};

#define list_entry(...) container_of(__VA_ARGS__)

static inline void __list_head_init(struct __double_list * ptr)
{
	ptr->prev = ptr;
	ptr->next = ptr;
}

static inline void
__list_concatenate(struct __double_list *front, struct __double_list *later)
{
	front->next = later;
	later->prev = front;
}

static inline void
__list_insert(struct __double_list *node, struct __double_list *before,
		struct __double_list *after)
{
	__list_concatenate(before, node);
	__list_concatenate(node, after);
}


static inline struct __double_list *__list_prev(struct __double_list *node)
{
	return node->prev;
}

static inline struct __double_list *__list_next(struct __double_list *node)
{
	return node->next;
}

static inline void
__list_add(struct __double_list *node, struct __double_list *head)
{
	__list_insert(node, head, __list_next(head));
}

static inline void
__list_add_tail(struct __double_list *node, struct __double_list *head)
{
	__list_insert(node, __list_prev(head), head);
}

static inline struct __double_list * __list_delete(struct __double_list *node)
{
	__list_concatenate(__list_prev(node), __list_next(node));
	__list_head_init(node);
	return node;
}

static inline struct __double_list * __list_begin(struct __double_list *head)
{
	return __list_next(head);
}

static inline struct __double_list * __list_rbegin(struct __double_list *head)
{
	return __list_prev(head);
}


#endif /*_LIST_PRIVATE_H_*/
