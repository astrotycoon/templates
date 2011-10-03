#ifndef _LIST_H_
#define _LIST_H_
#include <list-private.h>
typedef struct __double_list list_head_t;
static inline void list_head_init(list_head_t *list)
{
	__list_init(list);
}

#endif /*_LIST_H_*/
