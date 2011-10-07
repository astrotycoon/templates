#ifndef _LDECLARE_H_
#define _LDECLARE_H_

#define LDECLARE(type, name, initFunc, ...)				\
	type name;                                                      \
	initFunc(name, __VA_ARGS__)

#endif /*_LDECLARE_H_*/
