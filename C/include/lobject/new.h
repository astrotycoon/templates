#ifndef _NEW_H_
#define _NEW_H_
#include <lobject/multi-args.h>
#include <stdlib.h>
#define new_2(type, size) malloc(sizeof(type) * (size))

#define new_1(type) new_2(type, 1)

#define new(...) LCALL(new, __VA_ARGS__)(__VA_ARGS__)
#endif /*_NEW_H_*/
