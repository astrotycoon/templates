#ifndef __ASSERT_H
#define __ASSERT_H
#include "pp_narg.h"
#define _SAFETY_DOOR_

#ifdef _SAFETY_DOOR_
#define SDOOR(test) \
{ \
	if (unlikely(!(test))) { \
		printk(KERN_NOTICE "%s:%d:In function %s: Assertion (" \
				#test \
				") fail!\n", strrchr(__FILE__, '/') + 1, \
				__LINE__, __FUNCTION__); \
	} \
}
#else
#define SDOOR(test)
#endif/*SAFETY_DOOR*/


#define GATE(...) FOR_EACH(SDOOR, __VA_ARGS__)

#ifdef _SAFETY_DOOR_
#define DOOR(...) GATE(__VA_ARGS__)
#else
#define DOOR(...)
#endif

#endif/*__ASSERT_H*/
