/*==========  Inlcudes  ==========*/
#include "Timer.hpp"

/*========================================
=            Class Definition            =
========================================*/

    Timer::Timer()
    {
        if(!_used)
        {
            _used = true;

            // Configure
            configure();

            // Reset for clean start
            reset();
        }
    }

    Timer::~Timer()
    {
    }

    void Timer::reset()
    {
        cli();
        _ms = 0;
        TCNT1L = TCNT1H = 0;
        sei();      
    }

    unsigned long Timer::ms() const
    {
        return _ms;
    }

    bool Timer::_used = false;

    void Timer::configure()
    {
        // Timer Configuration
        // A
            // – COM1A1:0: Compare Output Mode for Channel A
            // – COM1B1:0: Compare Output Mode for Channel B
            // – COM1C1:0: Compare Output Mode for Channel C
            // – WGM11:0: Waveform Generation Mode
        unsigned char   com1A1_0 = 0,   // Unused
                        com1B1_0 = 0,   // Unused
                        com1C1_0 = 0,   // Unused
                        wgm11_0 = 0;    // Mode CTC on OC1A
        TCCR1A  = (com1A1_0&3)  << COM1A0
                | (com1B1_0&3)  << COM1B0
                | (com1C1_0&3)  << COM1C0
                | (wgm11_0&3)   << WGM10;

        // B
            // – ICNC1: Input Capture Noise Canceler
            // – ICES1: Input Capture Edge Select
            // – WGM13:2: Waveform Generation Mode
            // – CS12:0: Clock Select
        unsigned char   icnc1 = 0,      // Unused
                        ices1 = 0,      // Unused
                        wgm13_2 = 1,    // Mode CTC on OC1A
                        cs12_0 = 1;     // No Prescaler (T = 62ns)
        TCCR1B  = (icnc1&1)     << ICNC1
                | (ices1&1)     << ICES1
                | (wgm13_2&3)   << WGM12
                | (cs12_0&7)    << CS10;

        // Match Register Configuration
            // T = 62ns, so 1ms equals to 16000 ticks (0x3E80)
        OCR1AH = 0x3E;
        OCR1AL = 0x80;

        // Interrupts Configuration
            // – ICIE1: Input Capture Interrupt Enable
            // – OCIE1C: Output Compare C Match Interrupt Enable
            // – OCIE1B: Output Compare B Match Interrupt Enable
            // – OCIE1A: Output Compare A Match Interrupt Enable
            // – TOIE1: Overflow Interrupt Enable
        unsigned char   ocie1a = 1;
        TIMSK1 = (ocie1a&1)     << OCIE1A;
    }

/*==========  Operator Overload  ==========*/
Timer& Timer::operator++()      // prefix
{
    ++_ms;
    return *this;
}
 
Timer& Timer::operator++(int)   // postfix (Same behavior as prefix)
{
    return ++(*this);
}

/*-----  End of Class Definition  ------*/

/*==========  Global Object  ==========*/
Timer time;

/*==========  Interrupt Sub Routine  ==========*/

ISR(TIMER1_COMPA_vect)
{
    ++time;
}