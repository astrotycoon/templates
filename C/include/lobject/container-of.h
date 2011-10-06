#ifndef CONTAINER_OF_H
#define CONTAINER_OF_H
#include <lobject/multi-args.h>
#define offsetof(type, member) ((size_t) &((type *)0)->member)

#define container_of_3(ptr, type, member) \
({ \
	const typeof(((type *)0)->member) *__mptr = (ptr); \
	(type *) ((char *) __mptr - offsetof(type, member)); \
})

#define container_of_2(ptr, type) \
({                                      \
 	(type *) ptr;                   \
})

#define container_of(...) LCALL(container_of, __VA_ARGS__)(__VA_ARGS__)

#endif /*CONTAINER_OF_H*/
