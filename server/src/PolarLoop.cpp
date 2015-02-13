/*==========  Includes  ==========*/
#include "PolarLoop.hpp"

/*========================================
=            Class Definition            =
========================================*/

    PolarLoop::PolarLoop()
    : _odo(), _vLoopD(&_odo), _vLoopG(&_odo), _pidDist(Kp_dist, Ki_dist, Kd_dist), _pidAngle(Kp_phi, Ki_phi, Kd_phi)
    {
    }

    PolarLoop::~PolarLoop()
    {
    }

    void PolarLoop::routine()
    {
        /**
        
            TODO:
            - Maj Odo
            - Compute PIDs
            - Set Velocities Loops (UpDate)
            - Compute Velocities Loops
        
        **/
        
    }

/*-----  End of Class Definition  ------*/