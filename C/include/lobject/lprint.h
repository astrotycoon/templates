#ifndef _LPRINT_H_
#define _LPRINT_H_

#ifndef _KERNEL_MODE_
#include <stdio.h>
#define lprint(...) printf(__VA_ARGS__)
#else
#define lprint(...) printk(__VA_ARGS__)
#endif /*_KERNEL_MODE_*/

#endif /*_LPRINT_H_*/
