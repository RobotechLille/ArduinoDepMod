#ifndef _TIMER_HEADER_
#define _TIMER_HEADER_

/*==========  Includes  ==========*/
#include "avr/io.h"
#include "avr/interrupt.h"

/*=========================================
=            Class Declaration            =
=========================================*/

class Timer
{
public:
    Timer();
    ~Timer();
    void reset();
    unsigned long ms() const;
    Timer& operator++();    // prefix
    Timer& operator++(int);  // postfix
    void configure();

private:
    static bool _used;

public:
    unsigned long _ms;
    
};

/*-----  End of Class Declaration  ------*/

/*==========  Global Object  ==========*/
extern Timer time;

#endif // _TIMER_HEADER_