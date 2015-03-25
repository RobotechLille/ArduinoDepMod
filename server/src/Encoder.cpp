/*==========  Inlcudes  ==========*/
#include "Encoder.hpp"


ISR(PCINT2_vect)
{
	encMesR.computeEdge();
	encMesL.computeEdge();
	encMotR.computeEdge();
	encMotL.computeEdge();
}

/*========================================
=            Class Definition            =
========================================*/

    Encoder::Encoder(unsigned short int pinA, unsigned short int pinB, bool pullup)
    : _count(0)
    , _pinA(pinA)
    , _pinB(pinB)
    , _pinA_mask(1<<pinA)
    , _pinB_mask(1<<pinB)
    , _cptRisingA(0)
    , _cptFallingA(0)
    , _cptRisingB(0)
    , _cptFallingB(0)
    , _tot(0)
    {
    	// Init pins as input
    	DDRK &= ~(_pinA_mask|_pinB_mask);
    	// With pullup if needed
    	if(pullup) {
    		PORTK |= _pinA_mask|_pinB_mask;
    	}
    	else {
    		PORTK &= ~(_pinA_mask|_pinB_mask);
    	}

    	// Enable interrupts on PCINT2.pinA and PCINT2.pinB
    	PCMSK2 |= _pinA_mask|_pinB_mask;
    	// Enable interrupts on PCINT2 globally
    	PCICR |= 1 << PCIE2;

    	// Get first values
    	_precA = _A = getA();
    	_precB = _B = getB();
    }

    Encoder::~Encoder()
    {
    }

    void Encoder::computeEdge()
    {    	
    	_A = getA();
    	_B = getB();

    	// If we have an edge to compute
    	if(_A!=_precA || _B!=_precB)
    	{

            // Count edges
            if(_A==1 && _precA == 0)
                _cptRisingA++;
            else if(_A==0 && _precA == 1)
                _cptFallingA++;
            else if(_B==1 && _precB == 0)
                _cptRisingB++;
            else if(_B==0 && _precB == 1)
                _cptFallingB++;

    		// If we need to count
    		if(_A ^ _B ^ _precA ^ _precB) {
                _tot++;

    			// If we need to count down
    			if(_A ^ _precB) {
    				_count--;
    			}
                // Else, we need to count up
    			else {
    				_count++;
    			}
    		} 

    		// Save values
    		_precA = _A;
    		_precB = _B;
    	}
    }

    unsigned char Encoder::getA()
    {
    	return ((PINK&_pinA_mask) >> _pinA);
    }

    unsigned char Encoder::getB()
    {
    	return ((PINK&_pinB_mask) >> _pinB);
    }

    void Encoder::reset()
    {
    	_count = 0;
    }

    signed long int Encoder::getCount()
    {
    	return _count;
    }

/*-----  End of Class Definition  ------*/


// Preinstantiate Objects //////////////////////////////////////////////////////
Encoder encMesL(0, 1, true);
Encoder encMesR(2, 3, true);
Encoder encMotL(5, 4, false);
Encoder encMotR(7, 6, false);