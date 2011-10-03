#ifndef CONTAINER_OF_H
#define CONTAINER_OF_H
#define offsetof(type, member) \
	((size_t) &((type *)NULL)->member)
#ifndef FAST_UPCAST
#define container_of(ptr, type, member) \
({ \
	const typeof(((type *)NULL)->member) *__mptr = (ptr); \
	(type *) ((char *) __mptr - offsetof(type, member)); \
 })
#else
#define container_of(ptr, type, member) \
({                                      \
 	(type *) ptr;                   \
})
#endif /*FAST_UPCAST*/
#endif /*CONTAINER_OF_H*/
