#ifndef _PID_HEADER_
#define _PID_HEADER_

/*==========  Includes  ==========*/

/*==========  Defines  ==========*/
// PID Coeffs
    // Dist PID
    #define     Kp_dist     1
    #define     Ki_dist     0
    #define     Kd_dist     0
    // Angle PID
    #define     Kp_phi      1
    #define     Ki_phi      0
    #define     Kd_phi      0
    // Velocity D PID
    #define     Kp_VD       1
    #define     Ki_VD       0
    #define     Kd_VD       0
    // VelocityG PID
    #define     Kp_VG       1
    #define     Ki_VG       0
    #define     Kd_VG       0

/*=========================================
=            Class Declaration            =
=========================================*/

class Pid
{
public:
    Pid(float Kp, float Ki, float Kd);
    ~Pid();
    signed int compute(signed int ecart);
    void reset();
    void setPrecEcart(signed int prec);
    signed int getPrecEcart() const;
    signed int getSommeEcart() const;
    
private:
    signed int _precEcart;
    signed long _sommeEcart;
    float _Kp, _Ki, _Kd;
    // Time precTime;
};

/*-----  End of Class Declaration  ------*/

#endif // _PID_HEADER_