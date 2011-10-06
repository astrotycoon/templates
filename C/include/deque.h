#ifndef _DEQUE_H_
#define _DEQUE_H_
#include <queue.h>
typedef list_head_t deque_head_t;
typedef list_head_t deque_node_t;
#define deque_head_init(...) list_head_init(__VA_ARGS__)
#define deque_node_init(...) list_head_init(__VA_ARGS__)

#define DECLARE_DEQUE(name)						\
	deque_head_t name[1];                                           \
	deque_head_init(name);

#define enqueue_front(...) list_add_front(__VA_ARGS__)

#define enqueue_tail(...) list_add_tail(__VA_ARGS__)

#define enqueue(...) list_add_tail(__VA_ARGS__)

#define dequeue_front(...) list_del_front(__VA_ARGS__)

#define dequeue_tail(...) list_del_tail(__VA_ARGS__)

#define dequeue(...) list_del_front(__VA_ARGS__)

#define deque_destroy(...) list_destroy(__VA_ARGS__)

#define deque_copy(...) list_copy(__VA_ARGS__)

#endif /*_DEQUE_H_*/
