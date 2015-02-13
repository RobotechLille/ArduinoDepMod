#ifndef _PWM_HEADER_
#define _PWM_HEADER_

/*==========  Includes  ==========*/
#include "avr/io.h"

/*==========  Types  ==========*/
enum pwmChannel {A = 0, B = 1, NONE = -1};

/*=========================================
=            Class Declaration            =
=========================================*/

class Pwm
{
public:
    Pwm(pwmChannel channel);
    ~Pwm();
    float setDutyCycle(float dutyCycle);
    float getDutyCycle() const;
    pwmChannel getChannel() const;

private:
    float _dutyCycle;
    pwmChannel _associatedChannel;
    static bool _channelUsed[2];
    
};

/*-----  End of Class Declaration  ------*/

#endif // _PWM_HEADER_