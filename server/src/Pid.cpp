/*==========  Includes  ==========*/
#include "Pid.hpp"

/*========================================
=            Class Definition            =
========================================*/

    Pid::Pid(float Kp, float Ki, float Kd)
    : _precEcart(0), _sommeEcart(0), _Kp(Kp), _Ki(Ki), _Kd(Kd)
    {
    }

    Pid::~Pid()
    {
    }

    signed int Pid::compute(signed int ecart)
    {
        /**
        
            TODO:
            - GESTION DU TEMPS
        
        **/
        

        // Environnement
        signed int commande = 0;
            // Time deltaTime = time - _precTime;

        // Algo
            // _precTime = time;
        _sommeEcart += ecart;

        commande = (signed int)(_Kp * ecart 
                + _Ki * _sommeEcart 
                + _Kd * (float)((ecart - _precEcart)/*/deltaTime*/));

        _precEcart = ecart;

        return  commande;
    }

    void Pid::reset()
    {
        _precEcart = 0;
        _sommeEcart = 0;
    }

    void Pid::setPrecEcart(signed int prec)
    {
        _precEcart = prec;
    }

    signed int Pid::getPrecEcart() const
    {
        return _precEcart;
    }

    signed int Pid::getSommeEcart() const
    {
        return _sommeEcart;
    }


/*-----  End of Class Definition  ------*/