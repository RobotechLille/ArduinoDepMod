/*==========  Includes  ==========*/
#include "main.hpp"
#include "HardwareSerial.h"
#include "Encoder.hpp"

void printValue(signed long int value);

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

    // // Allumage après 5 min         // OK
    // while(true)
    // {
    //     if (time.ms() > 300000)
    //     {
    //         PORTB |= (1 << PB7);
    //     }
    //     else
    //     {
    //         PORTB &= ~(1 << PB7);
    //     }

    //     _delay_ms(1);
    // }

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

    /*==========  Test USART 01 ==========*/          // Bugguy with higher level bits

 //    USART_Init();
 //    DDRB |= (1 << PB7);

 //    int cpt = 0;
 //    while(true)
 //    {
 //        // Serial transmission
 //        PORTB |= (1 << PB7);
 //        _delay_ms(100);   
 //        USART_Transmit(cpt);
 //        if(cpt++ > 0xFF)
 //            cpt=0;  
 //        // USART_Transmit(0x00);
 //        // USART_Transmit(0x01);
 //        // USART_Transmit(0x02);
 //        // USART_Transmit(0x03);  
 //        // USART_Transmit(0x04);
 //        // USART_Transmit(0x05);
 //        // USART_Transmit(0x06);
 //        // USART_Transmit(0x07);
 //        // USART_Transmit(0x08);
 //        // USART_Transmit(0x09);
 //        // USART_Transmit(0x0A);
 //        // USART_Transmit(0x0B);
 //        // USART_Transmit(0x0C);
 //        // USART_Transmit(0x0D);  
 //        // USART_Transmit(0x0E);
 //        // USART_Transmit(0x0F);
 //        // USART_Transmit(0x27);
 //        // USART_Transmit('H');
 //        // USART_Transmit('E');
 //        // USART_Transmit('L');
 //        // USART_Transmit('L');
 //        // USART_Transmit('O');
 //        // USART_Transmit(' ');
 //        // USART_Transmit('W');
 //        // USART_Transmit('O');
 //        // USART_Transmit('R');
 //        // USART_Transmit('L');
 //        // USART_Transmit('D');
 //        PORTB &= ~(1 << PB7);
 // //       unsigned char result = USART_Receive();
 //        _delay_ms(200);        
 //    }

    /*==========  Test USART 02 ==========*/        // Always bugguy for values upper than 0x1F

    // USART_Init();
    // DDRB |= (1 << PB7);

    // unsigned char value = 0;
    // while(true)
    // {
    //     // Serial transmission
    //     PORTB |= (1 << PB7);
    //     _delay_ms(300);   
    //     USART_Transmit(value);
    //     PORTB &= ~(1 << PB7);
    //     value = USART_Receive();
    //     _delay_ms(700);        
    // }    

    /*==========  Test USART 03 ==========*/        // It fucking works!

    // Serial.begin(115200);
    // DDRB |= (1 << PB7);

    // unsigned char value = 0;
    // while(true)
    // { 
    //    if(value++ > 0xFF)
    //     value=0;  
    //     // Serial transmission
    //     PORTB |= (1 << PB7);
    //     _delay_ms(300);   
    //     Serial.write('H');
    //     Serial.write('e');
    //     Serial.write('l');
    //     Serial.write('l');
    //     Serial.write('o');
    //     Serial.write(' ');
    //     Serial.write('w');
    //     Serial.write('o');
    //     Serial.write('r');
    //     Serial.write('l');
    //     Serial.write('d');
    //     Serial.write('!');
    //     Serial.write('\n');
    //     Serial.write('\r');
    //     PORTB &= ~(1 << PB7);
    //     _delay_ms(700);        
    // }

    /*==========  Test USART 03 ==========*/        // It fucking works!

    Serial.begin(115200);
    DDRB |= (1 << PB7);

    unsigned char cpt = 0;
    while(true)
    { 
        if(cpt++ > 0xFF)
            cpt=0;  
        // Serial transmission
        PORTB |= (1 << PB7);
        _delay_ms(100);   

        signed long int value;
        // switch(cpt%4) {
        //     case 0:
        //         value = encMesL.getCount();
        //         break;    
        //     case 1:
        //         value = encMesR.getCount();
        //         break;   
        //     case 2:
        //         value = encMotL.getCount();
        //         break;   
        //     case 3:
        //         value = encMotR.getCount();
        //         break;       
        // }
        value = encMesL.getCount();

        // Serial.write((cpt%4)+'0');
        // Serial.write(':');
        // Serial.write(' ');
        printValue(value);
        Serial.write('\n');
        Serial.write('\r');
        printValue(encMesL._cptRisingA);
        Serial.write('\n');
        Serial.write('\r');
        printValue(encMesL._cptFallingA);
        Serial.write('\n');
        Serial.write('\r');
        printValue(encMesL._cptRisingB);
        Serial.write('\n');
        Serial.write('\r');
        printValue(encMesL._cptFallingB);
        Serial.write('\n');
        Serial.write('\r');
        printValue(encMesL._tot);
        Serial.write('\n');
        Serial.write('\r');
        Serial.write('-');
        Serial.write('-');
        Serial.write('-');
        Serial.write('-');
        Serial.write('\n');
        Serial.write('\r');

        // Serial.write('\n');
        Serial.write('\r');
        PORTB &= ~(1 << PB7);
        _delay_ms(300);        
    }

  return 1;
}

void printValue(signed long int value)
{
        Serial.write(((value/100000000000)%10)+'0');
        Serial.write(((value/10000000000)%10)+'0');
        Serial.write(((value/1000000000)%10)+'0');
        Serial.write(' ');
        Serial.write(((value/100000000)%10)+'0');
        Serial.write(((value/10000000)%10)+'0');
        Serial.write(((value/1000000)%10)+'0');
        Serial.write(' ');
        Serial.write(((value/100000)%10)+'0');
        Serial.write(((value/10000)%10)+'0');
        Serial.write(((value/1000)%10)+'0');
        Serial.write(' ');
        Serial.write(((value/100)%10)+'0');
        Serial.write(((value/10)%10)+'0');
        Serial.write(((value/1)%10)+'0');    
}