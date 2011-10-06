#ifndef _STACK_H_
#define _STACK_H_
#include <list.h>

typedef list_head_t stack_head_t;
typedef list_head_t stack_node_t;

#define stack_head_init(...) list_head_init(__VA_ARGS__)
#define stack_node_init(...) list_head_init(__VA_ARGS__)

#define DECLARE_STACK(name)						\
	stack_head_t name[1];                                           \
	stack_head_init(name)

#define stack_empty(...) list_empty(__VA_ARGS__)

#define push(...) list_add_front(__VA_ARGS__)

#define pop(...) list_del_front(__VA_ARGS__)

#define stack_destroy(...) list_destroy(__VA_ARGS__)

#define stack_copy(...) list_copy(__VA_ARGS__)

#endif /*_STATCK_H_*/
