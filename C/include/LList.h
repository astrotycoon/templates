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
	}

#define  LList_node_t(list)						\
	struct {                                                        \
		list_head_t linker;                                     \
		typeof(*(list)->data) data;                             \
	}                                                               \

#define LList_init(ptr)							\
({                                                                      \
 	int ret = 0;                                                    \
	LList_headInfo_t *headInfo = new(LList_headInfo_t);             \
	if (headInfo) {                                                 \
		LList_headInfoInit(headInfo);                           \
		(ptr)->data = (typeof((ptr)->data))headInfo;            \
 		list_head_init(&(ptr)->linker);				\
	} else {                                                        \
		ret = -ENOMEM;                                          \
	}                                                               \
	ret;                                                            \
})

#define LList_size(ptr)							\
({                                                                      \
 	((LList_headInfo_t *)((ptr)->data))->size;                      \
})

#define LList_increaseSize(list)					\
	LList_head_increaseSize((LList_headInfo_t *)((list)->data))

#define LList_decreaseSize(list)					\
	LList_head_decreaseSize((LList_headInfo_t *)((list)->data))

#define LList_append(item, list)					\
do {                                                                    \
	typeof(list) __list = (list);					\
	typeof(LList_node_t(__list)) *__new_node = 			\
				new(typeof(LList_node_t(__list)));	\
	list_node_init(&__new_node->linker);                            \
	memcpy(&__new_node->data, &(item),				\
			sizeof(typeof(*__list->data)));			\
	list_add(__new_node, &__list->linker);                          \
	LList_increaseSize(__list);                                     \
} while (0)                                                             

#define LList_begin(list)						\
({                                                                      \
 	typeof(list) __list = (list);					\
	typeof(list) __begin = list_next(__list); 		        \
	&__begin->data;                                                 \
})

#define LList_end(list)							\
({                                                                      \
 	&(list)->data;	                                		\
})

#define LList_next(pos, list)						\
({                                                                      \
 	typeof(list) __pos = list_entry(pos, typeof(*(list)), data);    \
 	typeof(list) __next = list_next(__pos);				\
	&__next->data;                                                  \
})

#endif /*_LIST_H_*/

