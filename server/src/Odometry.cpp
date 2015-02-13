/*==========  Includes  ==========*/
#include "Odometry.hpp"

/*========================================
=            Class Definition            =
========================================*/

    Odometry::Odometry()
    : encMesD(), encMesG(), encMotD(), encMotG()
    {
        _pos.x = 0;
        _pos.y = 0;
        _pos.phi = 0.0;
    }

    Odometry::~Odometry()
    {
    }

/*-----  End of Class Definition  ------*/
