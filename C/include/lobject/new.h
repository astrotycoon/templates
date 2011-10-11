#ifndef _NEW_H_
#define _NEW_H_
#include <lobject/multi-args.h>
#include <stdlib.h>
#define _new_2(type, size) malloc(sizeof(type) * (size))

#define _new_1(type) _new_2(type, 1)

#define _new(...) LCALL(_new, __VA_ARGS__)(__VA_ARGS__)
#endif /*_NEW_H_*/
