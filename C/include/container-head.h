#ifndef _CONTAINER_HEAD_H_
#define _CONTAINER_HEAD_H_

struct container_head_base {
	size_t size;
};

static inline void
container_head_base_init(struct container_head_base *headInfo)
{
	headInfo->size = 0;
}
#endif /*_CONTAINER_HEAD_H_*/
