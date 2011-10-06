#ifndef _QUEUE_H_
#define _QUEUE_H_
#include <list.h>
typedef list_head_t queue_head_t;
#define queue_head_init(...) list_head_init(__VA_ARGS__)

#define DECLARE_QUEUE(name)						\
	queue_head_t name[1];                                           \
	queue_head_init(name)

#define queue_empty(...) list_empty(__VA_ARGS__)

#define enqueue(...) list_add_front(__VA_ARGS__)

#define dequeue(...) list_del_tail(__VA_ARGS__)

#define queue_destroy(...) list_destroy(__VA_ARGS__)

#define queue_copy(...) list_copy(__VA_ARGS__)

#endif /*_QUEUE_H_*/
