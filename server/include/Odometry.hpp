#ifndef _ODOMETRY_HEADER_
#define _ODOMETRY_HEADER_

/*==========  Includes  ==========*/
#include "Encoder.hpp"

/*==========  Types  ==========*/
typedef struct
{
    unsigned int x,y;
    float phi;
}position;

/*=========================================
=            Class Declaration            =
=========================================*/

class Odometry
{
public:
    Odometry();
    ~Odometry();

private:
    Encoder encMesD;
    Encoder encMesG;
    Encoder encMotD;
    Encoder encMotG;
    position _pos;    
};

/*-----  End of Class Declaration  ------*/

#endif // _ODOMETRY_HEADER_