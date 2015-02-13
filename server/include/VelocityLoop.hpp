#ifndef _VELOCITY_LOOP_HEADER
#define _VELOCITY_LOOP_HEADER

/*==========  Includes  ==========*/
#include "Odometry.hpp"
#include "Motor.hpp"
#include "Pid.hpp"

/*========================================
=            Class Definition            =
========================================*/

class VelocityLoop
{
public:
    VelocityLoop();
    VelocityLoop(Odometry *odo);
    ~VelocityLoop();
    void compute();

private:
    Odometry *_odo;
    Motor _motD, _motG;
    Pid _pidD, _pidG;
};

/*-----  End of Class Definition  ------*/


#endif // _VELOCITY_LOOP_HEADER