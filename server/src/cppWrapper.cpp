/*==========  Includes  ==========*/
#include "cppWrapper.hpp"

/*===================================
=            Definitions            =
===================================*/

void *operator
new(size_t sz) throw()
{
  return malloc(sz);
}

void operator
delete(void *p)
{
    free(p);
}

// The line below make an error, don't no why but unnecessary for now
// extern "C" __cxa_pure_virtual();

// void __cxa_pure_virtual()
// {
//    abort();
// }

/*-----  End of Definitions  ------*/