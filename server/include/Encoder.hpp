#ifndef _ENCODER_HEADER_
#define _ENCODER_HEADER_

/*==========  Includes  ==========*/
#include <avr/io.h>
#include <avr/interrupt.h>
// PCINT0_vect

/*=========================================
=            Class Declaration            =
=========================================*/

class Encoder
{
public:
    Encoder(unsigned short int pinA, unsigned short int pinB, bool pullup);
    ~Encoder();
    void computeEdge();
    unsigned char getA();
    unsigned char getB();    
    void reset();
    signed long int getCount();

private:
    signed long int _count;
    unsigned char _precA, _precB, _A, _B;
    bool _inverted;
    unsigned short int _pinA, _pinB;
    unsigned short int _pinA_mask, _pinB_mask;

public:
    unsigned long int _cptRisingA;
    unsigned long int _cptFallingA;
    unsigned long int _cptRisingB;
    unsigned long int _cptFallingB;
    unsigned long int _tot;
};

/*-----  End of Class Declaration  ------*/

extern Encoder encMesR;
extern Encoder encMesL;
extern Encoder encMotR;
extern Encoder encMotL;

#endif // _ENCODER_HEADER_