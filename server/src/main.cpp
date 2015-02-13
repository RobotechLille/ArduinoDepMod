/*==========  Includes  ==========*/
#include "main.hpp"

int main (void)
{ 

    /*==========  LED en direct sur Pin 52  ==========*/   // OK
    
    // DDRB |= 1 << PB7;       // PB7 LED L output
    // DDRB &= ~(1 << PB1);    // PB1 Digital Pin 52 input

    // while(true)
    // {
    //     PORTB &= ~(1 << PB7);
    //     PORTB |= ((PINB >> PB1) & 1) << PB7;

    //     _delay_ms(10);
    // }

    /*==========  Allumage LED toutes les 3s  ==========*/  // OK
    
    // unsigned int lastSwitching = time.ms();

    // DDRB |= 1 << PB7;       // PB7 LED L output

    // while(true)
    // {
    //     if (time.ms() - lastSwitching > 3000 || 1)   // 3 secondes se sont écoulees
    //     {
    //         PORTB = PINB^(1<<PB7);      // Toggle Led value

    //         lastSwitching = time.ms();
    //     }

    //     _delay_ms(3000);
    // }
    
    /*==========  Rampe de Clignotements ==========*/   // OK

    // unsigned char inc = 0;
    // bool up = true;

    // DDRB |= 1 << PB7;       // PB7 LED L output

    // while(true)
    // {
    //     if(up){
    //         if(++inc == 255)
    //             up = false;
    //     }
    //     else{
    //         if(--inc == 0)
    //             up = true;
    //     }


    //     PORTB = PINB^(1<<PB7);      // Toggle Led value

    //     switch(inc/20)
    //     {
    //         case 0:
    //             _delay_ms(0);
    //         break;
    //         case 1:
    //             _delay_ms(10);
    //         break;
    //         case 2:
    //             _delay_ms(20);
    //         break;
    //         case 3:
    //             _delay_ms(30);
    //         break;
    //         case 4:
    //             _delay_ms(40);
    //         break;
    //         case 5:
    //             _delay_ms(50);
    //         break;
    //         case 6:
    //             _delay_ms(60);
    //         break;
    //         case 7:
    //             _delay_ms(70);
    //         break;
    //         case 8:
    //             _delay_ms(80);
    //         break;
    //         case 9:
    //             _delay_ms(90);
    //         break;
    //         case 10:
    //             _delay_ms(100);
    //         break;
    //         case 11:
    //             _delay_ms(110);
    //         break;
    //         case 12:
    //             _delay_ms(120);
    //         break;
    //     }
    // }

    /*==========  Rampe de PWM sur LED ==========*/     // OK

    // Pwm pwmA(A);
    // unsigned int inc = 0;
    // bool up = true;

    // DDRB |= 1 << PB7;       // PB7 LED L output
    // DDRB &= ~(1 << PB1);    // PB1 Digital Pin 52 input

    // while(true)
    // {
    //     if(up){
    //         if(++inc == 255*100)
    //             up = false;
    //     }
    //     else{
    //         if(--inc == 0)
    //             up = true;
    //     }

    //     // Changement de DutyCycle
    //     pwmA.setDutyCycle(inc/255.0);

    //     // Recopie de la pin 52 sur LED
    //     PORTB &= ~(1 << PB7);
    //     PORTB |= ((PINB >> PB1) & 1) << PB7;

    //     // Delai
    // }

    /*==========  Test du timer  ==========*/           // OK
    /*DDRB |= 1 << PB7;       // PB7 LED L output

    // Phase attente (3s ON, 1s OFF)
    PORTB |= (1 << PB7);
    _delay_ms(3000);
    PORTB &= ~(1 << PB7);
    _delay_ms(1000);

    // Triple clignotement
    PORTB |= (1 << PB7);
    _delay_ms(100);
    PORTB &= ~(1 << PB7);
    _delay_ms(100);


    PORTB |= (1 << PB7);
    _delay_ms(100);
    PORTB &= ~(1 << PB7);
    _delay_ms(100);


    PORTB |= (1 << PB7);
    _delay_ms(100);
    PORTB &= ~(1 << PB7);
    _delay_ms(100);

    // RAZ temps
    time.reset();

    // Allumage après 5 min         // OK
    while(true)
    {
        if (time.ms() > 300000)
        {
            PORTB |= (1 << PB7);
        }
        else
        {
            PORTB &= ~(1 << PB7);
        }

        _delay_ms(1);
    }

    // Ou changement toutes les 5s  // OK 
    while(true)
    {
        if (time.ms()%10000 > 5000)
        {
            PORTB |= (1 << PB7);
        }
        else
        {
            PORTB &= ~(1 << PB7);
        }

        _delay_ms(1);
    }*/

    /*==========  Test USART  ==========*/

    USART_Init();
    DDRB |= (1 << PB7);

    while(true)
    {
        // Serial transmission
        PORTB |= (1 << PB7);
        USART_Transmit(0x27);
        PORTB &= ~(1 << PB7);
 //       unsigned char result = USART_Receive();
        _delay_ms(1000);        
    }
    

  return 1;
}