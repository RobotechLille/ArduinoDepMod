#ifndef _CPP_WRAPPER_HEADER_
#define _CPP_WRAPPER_HEADER_

/*==========  Includes  ==========*/
extern "C" {
#include <stddef.h>
#include <stdlib.h>
}

/*==================================
=            Declarations            =
==================================*/

void *operator
new(size_t sz) throw();

void operator
delete(void *p);

/*-----  End of Declarations  ------*/

#endif // _CPP_WRAPPER_HEADER_