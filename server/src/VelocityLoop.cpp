/*==========  Includes  ==========*/
#include "VelocityLoop.hpp"

/*========================================
=            Class Definition            =
========================================*/

    VelocityLoop::VelocityLoop()
    : _odo(0), _motD(), _motG(), _pidD(Kp_VD, Ki_VD, Kd_VD), _pidG(Kp_VG, Ki_VG, Kd_VG)
    {
    }

    VelocityLoop::VelocityLoop(Odometry *odo)
    : _odo(odo), _motD(), _motG(), _pidD(Kp_VD, Ki_VD, Kd_VD), _pidG(Kp_VG, Ki_VG, Kd_VG)
    {
    }

    VelocityLoop::~VelocityLoop()
    {
    }

    void VelocityLoop::compute()
    {
        /**
        
            TODO:
            - Read Odo
            - Compute PIDs
            - Set Motors
        
        **/
        
    }

/*-----  End of Class Definition  ------*/