#ifndef _LLIST_PRIVATE_H_
#define _LLIST_PRIVATE_H_
#include <container-head.h>

typedef struct container_head_base LList_headInfo_t;

static inline void LList_headInfoInit(LList_headInfo_t *headInfo)
{
	container_head_base_init(headInfo);
}

static inline void LList_head_increaseSize(LList_headInfo_t *headInfo)
{
	headInfo->size++;
}

static inline void LList_head_decreaseSize(LList_headInfo_t *headInfo)
{
	headInfo->size--;
}

#endif /*_LLIST_PRIVATE_H_*/
