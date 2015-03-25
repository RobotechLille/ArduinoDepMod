/*==========  Inlcudes  ==========*/
#include "Usart.hpp"

/*========================================
=            Class Definition            =
========================================*/

    Usart::Usart(usartChannel channel)
    {
        if(!_usedChannel[channel])
        {
            _usedChannel[channel] = true;
            _associatedChannel = channel;
        
            configure();
        }
        else
        {
            _associatedChannel = NOP;
        }
    }

    Usart::~Usart()
    {
        _usedChannel[_associatedChannel] = false;
    }

    void Usart::send(unsigned char c)
    {

    }

    void Usart::send(char* s)
    {

    }

    usartChannel Usart::getChannel() const
    {
        return _associatedChannel;
    }

    void Usart::configure()
    {

    }


    bool Usart::_usedChannel[4] = {false, false, false, false};
/*-----  End of Class Definition  ------*/


// For the USART
void USART_Init()
{
unsigned int ubrr = MYUBRR;

// Set baud rate
UBRR0H = (unsigned char)(ubrr>>8);
UBRR0L = (unsigned char)ubrr;

// Enable receiver and transmitter
UCSR0B = (1<<RXEN0)|(1<<TXEN0);

// Set frame format: 8data, 1stop bit, even parity
UCSR0C = (3<<UCSZ00)|(0<<USBS0)|(0<<UPM00);
}

// void USART_Init()
// {
// unsigned int ubrr = MYUBRR;

// // Set baud rate
// UBRR0H = (unsigned char)(ubrr>>8);
// UBRR0L = (unsigned char)ubrr;

// // Enable receiver and transmitter
// UCSR0B = (1<<RXEN0)|(1<<TXEN0);

// // Set frame format: 8data, 1stop bit
// UCSR0C = (3<<UCSZ00);
// }

void USART_Transmit(unsigned char data)
{
// Wait for empty transmit buffer
while ( !( UCSR0A & (1<<UDRE0)) );
// Put data into buffer, sends the data
UDR0 = data;
}

unsigned char USART_Receive(void)
{
unsigned int i = 0;

// Wait for data to be received
while ( !(UCSR0A & (1<<RXC0)) && i<TIMEOUT){i++;_delay_ms(1);}

if (i == TIMEOUT)
return 1;

// Get and return received data from buffer
return UDR0;
}