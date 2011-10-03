#ifndef _NEW_H_
#define _NEW_H_
#include <trickes/new-private.h>
#define new(...) LCALL(new, __VA_ARGS__)
#endif /*_NEW_H_*/
