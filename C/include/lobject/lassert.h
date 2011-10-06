#ifndef __ASSERT_H
#define __ASSERT_H
#include <lobject/multi-args.h>
#include <lobject/lprint.h>
#include <string.h>
#define _SAFETY_DOOR_
#ifdef _SAFETY_DOOR_
#define SDOOR(test)							 \
do {                                                                     \
	if (!(test)) {                                                   \
		lprint("%s:%d: Assertion ("             		 \
			#test ") failed in function %s\n", __FILE__,   	 \
			__LINE__, __FUNCTION__);                         \
	}                                                                \
} while(0)
#else
#define SDOOR(test) do {} while(0)
#endif/*SAFETY_DOOR*/


#define GATE(...) FOR_EACH(SDOOR, __VA_ARGS__)

#ifdef _SAFETY_DOOR_
#define DOOR(...) GATE(__VA_ARGS__)
#else
#define DOOR(...) do {} while(0)
#endif

#endif/*__ASSERT_H*/
