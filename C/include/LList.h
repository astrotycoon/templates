#ifndef _LLIST_H_
#define _LLIST_H_
#include <list.h>
#include <memory.h>
#include <LList-private.h>
#include <LDECLARE.h>
#include <errno.h>


#define LList(type)							\
	struct {                                                        \
		list_head_t linker;                                     \
		type *data;                                             \
		LList_headInfo_t headInfo;				\
	}

#define iterator_typeof(ptr) typeof(ptr->data)

#define  LList_node_t(list)						\
	struct {                                                        \
		list_head_t linker;                                     \
		typeof(*(list)->data) data;                             \
	}                                                               \

#define LList_init(ptr)							\
do {                                                                    \
 	typeof(ptr) __LList_init_ptr = (ptr);				\
	LList_headInfoInit(&(__LList_init_ptr)->headInfo);              \
	list_head_init(&(__LList_init_ptr)->linker);			\
} while (0)

#define LList_new(type)							\
({                                                                      \
 	struct {                                                        \
		list_head_t linker;                                     \
		type * data;                                            \
		LList_headInfo_t headInfo;                              \
	} *ret;                                                         \
	ret = _new(typeof(*ret));                                       \
	if (ret)                                                        \
		LList_init(ret);                                        \
	(void *) ret;                                                   \
})

#define LList_size(ptr)							\
({                                                                      \
 	(ptr)->headInfo.size;			                        \
})

#define LList_increaseSize(list)					\
	LList_head_increaseSize(&(list)->headInfo)			

#define LList_decreaseSize(list)					\
	LList_head_decreaseSize(&(list)->headInfo)

#define LList_append(item, list)					\
do {                                                                    \
 	typedef typeof(LList_node_t(list)) __Node_t;			\
	typeof(list) __list = (list);					\
	__Node_t *__new_node = 	_new(__Node_t);				\
	list_node_init(&__new_node->linker);                            \
	memcpy(&__new_node->data, &(item),				\
			sizeof(typeof(*__list->data)));			\
	list_add(__new_node, &__list->linker);                          \
	LList_increaseSize(__list);                                     \
} while (0)                                                             

#define LList_push_back(...) LList_append(__VA_ARGS__)

#define LList_begin(list)						\
({                                                                      \
 	typeof(list) __list = (list);					\
	typeof(list) __begin = list_next(__list); 		        \
	(typeof((list)->data))&__begin->data;		                \
})

#define LList_end(list)							\
({                                                                      \
 	(typeof((list)->data))&(list)->data;	              		\
})

#define LList_next(pos, list)						\
({                                                                      \
 	typedef typeof(LList_node_t(list)) __Node_t;			\
 	__Node_t *__pos = list_entry(pos, __Node_t, data);       	\
 	__Node_t *__next = list_next(__pos);				\
	&__next->data;                            			\
})

#endif /*_LIST_H_*/
