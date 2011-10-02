#ifndef TEMPLATE_LIST
#define TEMPLATE_LIST
#include <stdlib.h>
#include <trickes/container-of.h>
struct _double_list {
	struct _double_list * next;
	struct _double_list * prev;	
};
typedef struct _double_list * list_t;
#define __linked_as_list__ struct _double_list __list_linkers;

#define list_new_head(type) ({ \
	type * _head = malloc(sizeof(type)); \
	__list_init(&_head->__list_linkers); \
	_head;})

#define list_init(hdr) {\
	struct _double_list *ptr = &(hdr)->__list_linkers; \
	__list_init(ptr);}

static inline void __list_init(struct _double_list * ptr)
{
	ptr->prev = ptr;
	ptr->next = ptr;
}

static inline struct _double_list * list_pickup(struct _double_list *ptr) 
{ 
	if (ptr->prev) 
		ptr->prev->next = ptr->next;
	if (ptr->next)
		ptr->next->prev = ptr->prev; 
	return ptr->next; 
}

static inline void __list_replace(struct _double_list *ptr, struct _double_list *nptr)
{
	nptr->prev = ptr->prev;
	nptr->next = ptr->next;
	nptr->next->prev = nptr;
	nptr->prev->next = nptr;
}

#define list_prev(ptr) ({ \
	typeof(ptr) __ptr = ptr; \
	struct _double_list *__ptmp = __ptr->__list_linkers.prev;\
	__ptmp ? container_of(__ptmp, typeof(*__ptr), __list_linkers) : NULL; })

#define list_next(ptr) ({ \
	typeof(ptr) __ptr = ptr; \
	struct _double_list *__ntmp = __ptr->__list_linkers.next;\
	__ntmp ? container_of(__ntmp, typeof(*__ptr), __list_linkers) : NULL; })

#define list_is_empty(head) \
	(head == list_next(head))

#define list_for_each(ptr, hdr) \
	for (ptr = list_next(hdr); \
			 ptr && ptr != (hdr); \
		       		ptr = list_next(ptr))

#define list_insert_before(ptr, nptr) ({\
	typeof(ptr) __ptr = ptr; \
	struct _double_list *__tmp; \
	__tmp = __list_insert_before(&(ptr)->__list_linkers, \
		&(nptr)->__list_linkers); \
	__tmp ? container_of(__tmp, typeof(*__ptr), __list_linkers) : NULL; })
	
#define list_insert_after(ptr, nptr) ({\
	typeof(ptr) __ptr = ptr; \
	struct _double_list *__tmp; \
	__tmp = __list_insert_after(&(ptr)->__list_linkers, \
		&(nptr)->__list_linkers); \
	__tmp ? container_of(__tmp, typeof(*__ptr), __list_linkers) : NULL; })

#define __list_insert_before(ptr, nptr) ({\
	struct _double_list *__ptr = ptr; \
	struct _double_list *__nptr = nptr; \
	struct _double_list *__ibtmp = __ptr->prev; \
	__ptr->prev = __nptr; \
	__nptr->next = __ptr; \
	__nptr->prev = __ibtmp; \
	if (__ibtmp) \
		__ibtmp->next = __nptr; \
	__ibtmp; })

#define __list_insert_after(ptr, nptr) ({\
	struct _double_list *__ptr = ptr; \
	struct _double_list *__nptr = nptr; \
	struct _double_list *__ibtmp = __ptr->next; \
	__ptr->next = __nptr; \
	__nptr->prev = __ptr; \
	__nptr->next = __ibtmp; \
	if (__ibtmp) \
		__ibtmp->prev = __nptr; \
	__ibtmp; })


#define list_replace(ptr, nptr) {\
	__list_replace(&(ptr)->__list_linkers, &(nptr)->__list_linkers);}

#define list_delete(ptr) ({ \
	typeof(ptr) __ptr = ptr; \
	if (__ptr) \
		list_pickup(&((__ptr)->__list_linkers)); \
	free(__ptr); \
	})\

#define list_destroy(hdr) ({ \
	typeof(hdr) __hdr = hdr; \
	typeof(__hdr) it; \
	list_foreach(it, __hdr) \
		free(it); \
	free(__hdr); \
	})
#endif
