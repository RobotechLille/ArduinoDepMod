/*==========  Inlcudes  ==========*/
#include "Pwm.hpp"

/*========================================
=            Class Definition            =
=========================================*/

    Pwm::Pwm(pwmChannel channel)
    {
    // Working on Timer2 because of its independent prescaler
        // PWM Configuration (only on first object construction)
        if (!_channelUsed[A] && !_channelUsed[B])
        {
            // Timer/Counter Configuration Register
            // A
                // - COM2A1:0: Compare Match Output A Mode
                // - COM2B1:0: Compare Match Output B Mode
                // - Res: Reserved Bits
                // - WGM21:0: Waveform Generation Mode
                unsigned char   com2A1_0 = 2,   // Non-inverting mode
                                com2B1_0 = 2,   // Non-inverting mode
                                wgm21_0 = 3;    // Fast PWM
                TCCR2A = (com2A1_0&3) << COM2A0
                        | (com2B1_0&3) << COM2B0
                        | (wgm21_0&3) << WGM20;

            // B
                // - FOC2A: Force Output Compare A
                // - FOC2B: Force Output Compare B
                // - WGM22: Waveform Generation Mode
                // - CS22:0: Clock Select
                unsigned char   foc2A = 0,      // Unused
                                foc2B = 0,      // Unused
                                wgm22 = 0,      // Fast PWM reset on TOP
                                cs22_0 = 1;     // Clk w/o prescaler
                TCCR2B = (foc2A&1) << FOC2A 
                        | (foc2B&1) << FOC2B 
                        | (wgm22&1) << WGM22 
                        | (cs22_0&7) << CS20;
            
                // Count in TCNT2 register

            // For an IRQ on OC2A pin, Output Compare Register A
                OCR2A = 0;      // DutyCycle equal 0% at start
            // For an IRQ on OC2B pin, Output Compare Register B
                OCR2B = 0;      // DutyCycle equal 0% at start

            // Interrupts
                // - OCIE2A: Output Compare Match A Interrupt Enable
                // - OCIE2B: Output Compare Match B Interrupt Enable
                // - TOIE2: Timer Overflow Interupt Enable
                unsigned char   ocie2A = 0,     // No interrupt needed
                                ocie2B = 0,     // No interrupt needed
                                toie2 = 0;      // No interrupt needed
                TIMSK2 = (ocie2A&1) << OCIE2A
                        | (ocie2B&1) << OCIE2B
                        | (toie2&1) << TOIE2;     

            // Interrupts Flags are in TIFR2 register
                // - OCF2A: Output Compare Match A Flag
                // - OCF2B: Output Compare Match B Flag
                // - TOV2: Timer Overflow Flag

        }

        // Channel use protection ()           
        if(!_channelUsed[channel])
        {
            _associatedChannel = channel;
            _channelUsed[channel] = true;

            // Associated pin in output
            switch(_associatedChannel)
            {
                case A:
                    DDRB |= 1 << PB4;   // Digital pin 10 (PWM)
                break;

                case B:
                    DDRH |= 1 << PH6;   // Digital pin 9 (PWM)
                break;

                case NONE:
                default:
                break;
            }
        }
        else
        {
            _associatedChannel = NONE;
        }

        _dutyCycle = 0;
    }

    Pwm::~Pwm()
    {
        _channelUsed[_associatedChannel] = false;
    }

    float Pwm::setDutyCycle(float dutyCycle)
    {
        // Max value is 100
        _dutyCycle = ((dutyCycle > 100)?100:((dutyCycle<0)?0:dutyCycle));
            
        switch(_associatedChannel)
        {
            case A:
                OCR2A = (unsigned char)((int)(_dutyCycle * 255) / 100);
            break;

            case B:
                OCR2B = (unsigned char)((int)(_dutyCycle * 255) / 100);
            break;

            case NONE:
            default:
                _dutyCycle = 0;
                return -2;
            break;
        }

        return _dutyCycle;
    }

    float Pwm::getDutyCycle() const
    {
        return _dutyCycle;
    }

    pwmChannel Pwm::getChannel() const
    {
        return _associatedChannel;
    }

    bool Pwm::_channelUsed[2] = {false,false};

/*-----  End of Class Definition  ------*/