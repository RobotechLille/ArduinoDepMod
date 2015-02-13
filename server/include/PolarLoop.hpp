#ifndef _POLAR_LOOP_HEADER_
#define _POLAR_LOOP_HEADER_

/*==========  Includes  ==========*/
#include "Odometry.hpp"
#include "VelocityLoop.hpp"
#include "Pid.hpp"

/*=========================================
=            Class Declaration            =
=========================================*/

class PolarLoop
{
public:
    PolarLoop();
    ~PolarLoop();
    void routine();

private:
    Odometry _odo;
    VelocityLoop _vLoopD, _vLoopG;
    Pid _pidDist, _pidAngle;    
};

/*-----  End of Class Declaration  ------*/

#endif // _POLAR_LOOP_HEADER_