#ifndef _LIST_H_
#define _LIST_H_
#include <lobject/new.h>
#include <list-private.h>
typedef struct __double_list list_head_t;
typedef list_head_t list_node_t;

/**
 * the linker should act as the first member of @ptr
 * We strongly recommand you NOT to use list_head_init_1, if you have
 * not understanded it yet.
**/

#define list_head_init_1(ptr)					\
do {                                                            \
	list_head_t *__ptr = (list_head_t *)(ptr);              \
	__list_head_init(__ptr);                                \
} while (0)

#define list_head_init_2(ptr, member)				\
do {                                                            \
	__list_head_init(&(ptr)-> member);                      \
} while (0)

#define list_head_init(...) LCALL(list_head_init, __VA_ARGS__)(__VA_ARGS__)
#define list_node_init(...) list_head_init(__VA_ARGS__)

#define DECLARE_LIST(name)						\
	list_head_t name[1];                                            \
	list_head_init(name)

#define list_entry(...) container_of(__VA_ARGS__)

#define list_empty(head)					\
({                                                              \
 	__list_prev(head) == head && __list_next(head) == head; \
})

/**
 * the linker should act as the first member of @ptr
 * We strongly recommand you NOT to use list_add_2, if you have
 * not understanded it yet.
**/

#define list_add_front_2(ptr, head)				\
do {                                                            \
	list_head_t *__ptr = (list_head_t *)(ptr);              \
	list_head_t *__head = (head);                           \
	__list_add(__ptr, __head);   		                \
} while (0)

#define list_add_front_3(ptr, member, head)	  		\
do {                                                            \
	list_head_t *__ptr = &(ptr)->member;                    \
	list_head_t *__head = (head);                           \
	__list_add(__ptr, __head);                 		\
} while (0)

#define list_add_front(...) LCALL(list_add_front, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of @ptr
 * We strongly recommand you NOT to use list_add_tail_2, if you have
 * not understanded it yet.
**/

#define list_add_tail_2(ptr, head)				\
do {                                                            \
	list_head_t *__ptr = (list_head_t *)(ptr);              \
	list_head_t *__head = (head);                           \
	__list_add_tail(__ptr, __head);  	                \
} while (0)

#define list_add_tail_3(ptr, member, head)			\
do {                                                            \
	list_head_t *__ptr = &(ptr)->member;                    \
	list_head_t *__head = (head);                           \
	__list_add_tail(__ptr, __head);                		\
} while (0)

#define list_add_tail(...) LCALL(list_add_tail, __VA_ARGS__)(__VA_ARGS__)

#define list_add(...) list_add_tail(__VA_ARGS__)


/**
 * the linker should act as the first member of @ptr
 * We strongly recommand you NOT to use list_delete_1, if you have
 * not understanded it yet.
**/

#define list_remove_1(ptr)						\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);					\
	list_head_t *__lks = (list_head_t *)__ptr;                      \
	__list_delete(__lks);                                           \
 	__ptr;								\
})

#define list_remove_2(ptr, member)					\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);					\
	list_head_t *__lks = &__ptr->member;                            \
	__list_delete(__lks);                                           \
 	__ptr;								\
})

#define list_remove(...) LCALL(list_remove, __VA_ARGS__)(__VA_ARGS__)



/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_begin_2, if you have
 * not understanded it yet.
**/

#define list_begin_2(head, type)					\
({                                                                      \
	list_head_t *begin = __list_begin(head);                        \
	list_entry(begin, type);                                        \
})


#define list_begin_3(head, type, member)				\
({                                                                      \
	list_head_t *begin = __list_begin(head);                        \
	list_entry(begin, type, member);                                \
})
#define list_begin(...) LCALL(list_begin, __VA_ARGS__)(__VA_ARGS__)

/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_rbegin_2, if you have
 * not understanded it yet.
**/

#define list_rbegin_2(head, type)					\
({                                                                      \
	list_head_t *rbegin = __list_rbegin(head);                      \
	list_entry(rbegin, type);                                       \
})


#define list_rbegin_3(head, type, member)				\
({                                                                      \
	list_head_t *rbegin = __list_rbegin(head);                      \
	list_entry(rbegin, type, member);                               \
})
#define list_rbegin(...) LCALL(list_rbegin, __VA_ARGS__)(__VA_ARGS__)

#define list_end(head, type, ...) (void *)(head)

#define list_rend(head, type, ...) (void *)(head)

#define list_last(...) list_rbegin(__VA_ARGS__)


/**
 * the linker should act as the first member of @ptr
 * We strongly recommand you NOT to use list_del_front_2, if you have
 * not understanded it yet.
**/

#define list_del_front_2(head, type)					\
({                                                                      \
 	type *ret = NULL;                                               \
 	if (!list_empty(head)) {                                        \
		ret = list_begin(head, type);                           \
		list_remove(ret);                                       \
	}                                                               \
	ret;                                                            \
})

#define list_del_front_3(head, type, member)				\
({                                                                      \
 	type *ret = NULL;                                               \
	if (!list_empty(head)) {                                        \
		ret = list_begin(head, type, member);                   \
		list_remove(ret, member);                               \
	}                                                               \
	ret;                                                            \
})

#define list_del_front(...) LCALL(list_del_front, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of containing structure
 * We strongly recommand you NOT to use list_del_tail_2, if you have
 * not understanded it yet.
**/

#define list_del_tail_2(head, type)					\
({                                                                      \
 	type *ret = NULL;                                               \
 	if (!list_empty(head)) {                                        \
		ret = list_last(head, type);                            \
		list_remove(ret);                                       \
	}                                                               \
	ret;                                                            \
})

#define list_del_tail_3(head, type, member)				\
({                                                                      \
 	type *ret = NULL;                                               \
	if (!list_empty(head)) {                                        \
		ret = list_last(head, type, member);                    \
		list_remove(ret, member);                               \
	}                                                               \
	ret;                                                            \
})

#define list_del_tail(...) LCALL(list_del_tail, __VA_ARGS__)(__VA_ARGS__)

#define list_del(...) list_del_tail(__VA_ARGS__)

/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_prev_1, if you have
 * not understanded it yet.
**/

#define list_prev_1(ptr)						\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);                                      \
	list_head_t *prev = __list_prev((list_head_t *)__ptr);          \
	list_entry(prev, typeof(*__ptr));                                \
})

#define list_prev_2(ptr, member)					\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);                                      \
	list_head_t *prev = __list_prev(&__ptr->member);    	        \
	list_entry(prev, typeof(*__ptr), member);                        \
})

#define list_prev(...) LCALL(list_prev, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_next_1, if you have
 * not understanded it yet.
**/

#define list_next_1(ptr)						\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);                                      \
	list_head_t *next = __list_next((list_head_t *)__ptr);          \
	list_entry(next, typeof(*__ptr));                               \
})

#define list_next_2(ptr, member)					\
({                                                                      \
 	typeof(ptr) __ptr = (ptr);                                      \
	list_head_t *next = __list_next(&__ptr->member);    	        \
	list_entry(next, typeof(*__ptr), member);                       \
})

#define list_next(...) LCALL(list_next, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_for_each_2, if you have
 * not understanded it yet.
**/

#define list_for_each_2(itt, head)					\
	for (itt = list_begin(head, typeof(*itt));                      \
			itt != list_end(head, typeof(*itt));            \
			itt = list_next(itt))

#define list_for_each_3(itt, head, member)				\
	for (itt = list_begin(head, typeof(*itt), member);              \
			itt != list_end(head, typeof(*itt), member);    \
			itt = list_next(itt))

#define list_for_each(...) LCALL(list_for_each, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_for_each_reverse_2, if you have
 * not understanded it yet.
**/

#define list_for_each_reverse_2(itt, head)	       			 \
	for (itt = list_rbegin(head, typeof(*itt));                      \
			itt != list_rend(head, typeof(*itt));            \
			itt = list_prev(itt))

#define list_for_each_reverse_3(itt, head, member)		       	 \
	for (itt = list_rbegin(head, typeof(*itt), member);              \
			itt != list_rend(head, typeof(*itt), member);    \
			itt = list_prev(itt))

#define list_for_each_reverse(...)					\
	LCALL(list_for_each_reverse, __VA_ARGS__)(__VA_ARGS__)

/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_for_each_safe_3, if you have
 * not understanded it yet.
**/

#define list_for_each_safe_3(itt, tmp, head)				\
	for (itt = list_begin(head, typeof(*itt));                      \
			itt != list_end(head, typeof(*itt)) &&		\
			(tmp = list_next(itt)),				\
			itt != list_end(head, typeof(*itt));            \
			itt = tmp)

#define list_for_each_safe_4(itt, tmp, head, member)			\
	for (itt = list_begin(head, typeof(*itt), member);              \
			itt != list_end(head, typeof(*itt), member) &&  \
			(tmp = list_next(itt, member)),			\
			itt != list_end(head, typeof(*itt), member);    \
			itt = tmp)

#define list_for_each_safe(...)						\
	LCALL(list_for_each_safe, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_for_each_safe_reverse_3, 
 * if you have not understanded it yet.
**/

#define list_for_each_safe_reverse_3(itt, tmp, head)			\
	for (itt = list_rbegin(head, typeof(*itt));                     \
			itt != list_rend(head, typeof(*itt)) &&		\
			(tmp = list_prev(itt)),				\
			itt != list_rend(head, typeof(*itt));           \
			itt = tmp)

#define list_for_each_safe_reverse_4(itt, tmp, head, member)		\
	for (itt = list_rbegin(head, typeof(*itt), member);             \
			itt != list_rend(head, typeof(*itt), member) && \
			(tmp = list_prev(itt, member)),			\
			itt != list_rend(head, typeof(*itt), member);   \
			itt = tmp)

#define list_for_each_safe_reverse(...)					\
	LCALL(list_for_each_safe_reverse, __VA_ARGS__)(__VA_ARGS__)

#define list_for_each_reverse_safe(...)					\
	list_for_each_safe_reverse(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_destroy_2, 
 * if you have not understanded it yet.
**/

#define list_destroy_2(head, type)					\
do {                                                                    \
	while (!list_empty(head)) {                                     \
		type * first = list_begin(head, type);                  \
		list_remove(first);                                     \
		free(first);                                            \
	}                                                               \
} while (0)

#define list_destroy_3(head, type, member)				\
do {                                                                    \
	while (!list_empty(head)) {                                     \
		type * first = list_begin(head, type, member);          \
		list_remove(first);                                     \
		free(first);                                            \
	}                                                               \
} while (0)

#define list_destroy(...) LCALL(list_destroy, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_destroy_2, 
 * if you have not understanded it yet.
**/

#define list_copy_2(head, type)						\
({                                                                      \
 	list_head_t *rethead = new(list_head_t);                        \
	list_head_init(rethead);                                        \
	type *new_node, *itt;                                           \
	list_for_each (itt, head) {                                     \
		new_node = new(type);                                   \
		if (!new_node) {			         	\
 			list_destroy(rethead, type);                    \
			break;                                          \
		}                                                       \
		memcpy(new_node, itt, sizeof(type));                    \
		list_head_init(new_node);                               \
		list_add_tail(new_node, rethead);                       \
	}                                                               \
	rethead;                                                        \
})

#define list_copy_3(head, type, member)					\
({                                                                      \
 	list_head_t *rethead = new(list_head_t);                        \
	list_head_init(rethead);                                        \
	type *new_node, *itt;                                           \
	list_for_each (itt, head) {                                     \
		new_node = new(type);                                   \
		if (!new_node) {					\
 			list_destroy(rethead, type);                    \
			break;                                          \
		}                                                       \
		memcpy(new_node, itt, sizeof(type));                    \
		list_head_init(new_node, member);                       \
		list_add_tail(new_node, member, rethead);               \
	}                                                               \
	rethead;                                                        \
})

#define list_copy(...) LCALL(list_copy, __VA_ARGS__)(__VA_ARGS__)


/**
 * the linker should act as the first member of the containing structure
 * We strongly recommand you NOT to use list_split_2, 
 * if you have not understanded it yet.
**/

#define list_split_2(pos, head)						\
({                                                                      \
 	list_head_t *rethead = new(list_head_t);                        \
	list_head_init(rethead);                                        \
                                                                        \
	list_head_t *cur = (list_head_t *)pos;                          \
	list_head_t *prev = __list_prev(cur);                           \
	list_head_t *last = 						\
 		(list_head_t *)list_last(head, typeof(*pos));		\
	__list_concatenate(prev, head);                                 \
	__list_concatenate(rethead, cur);                               \
	__list_concatenate(last, rethead);                              \
	rethead;                                                        \
})

#define list_split_3(pos, member, head)					\
({                                                                      \
 	list_head_t * rethead = new(list_head_t);                       \
	list_head_init(rethead);                                        \
	                                                                \
	list_head_t *cur = &pos->member;                                \
	list_head_t *prev = __list_prev(cur);                           \
	list_head_t *last =						\
 		&list_last(head, typeof(*pos))->member;                 \
	__list_concatenate(prev, head);                                 \
	__list_concatenate(rethead, cur);                               \
	__list_concatenate(last, rethead);                              \
	rethead;                                                        \
})

#define list_split(...) LCALL(list_split, __VA_ARGS__)(__VA_ARGS__)


#endif /*_LIST_H_*/
