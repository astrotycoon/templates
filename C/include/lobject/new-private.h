#ifndef _NEW_PRIVATE_H_
#define _NEW_PRIVATE_H_
#include <trickes/multi-args.h>
#include <stdlib.h>
#define new_2(type, size) malloc(sizeof(type) * (size))
#define new_1(type) new_2(type, 1)
#endif /*_NEW_PRIVATE_H_*/
