#ifndef _USART_HEADER_
#define _USART_HEADER_

/*==========  Includes  ==========*/
#include "avr/io.h"
#include "util/delay.h"

/*==========  Types  ==========*/
enum usartChannel {USART0 = 0, USART1 = 1, USART2 = 2, USART3 = 3, NOP = -1};

/*==========  Defines  ==========*/
// USART
#define FOSC 16000000L // Clock Speed (16MHZ)
#define BAUD 115200
#define MYUBRR FOSC/16/(unsigned long int)BAUD-1

// Serial
#define TIMEOUT 100

/*==========  Prototypes  ==========*/
// For the USART
void USART_Init();
void USART_Transmit(unsigned char data);
unsigned char USART_Receive(void);

/*=========================================
=            Class Declaration            =
=========================================*/

class Usart
{
public:
    Usart(usartChannel channel);
    ~Usart();
    void send(unsigned char c);
    void send(char* s);
    usartChannel getChannel() const;

private:
    void configure();
    usartChannel _associatedChannel;
    static bool _usedChannel[4];

};

/*-----  End of Class Declaration  ------*/

#endif // _USART_HEADER_