#ifndef TEMPLATE_HACK
#define TEMPLATE_HACK
#define offsetof(type, member) \
	((size_t) &((type *)NULL)->member)

#define container_of(ptr, type, member) ({\
	const typeof(((type *)NULL)->member) *__mptr = (ptr); \
	(type *) ((char *) __mptr - offsetof(type, member)); })
#endif
