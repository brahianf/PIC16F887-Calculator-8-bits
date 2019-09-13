/*
 * 
 * ;************
 *   Calculator add and subtract of 8 bits with number selection dip switch 8 
 * 
 *       RE0 - Push Button 1
 *		 RE1 - Push Button 2
 *		 RE2 - Push Button 3
 *       RC7 - Push Button 4
 *
 *		 PORTB - INPUT 8 bits  
 * 
 *       PORTA - Display 1  (hundreds)
 *       PORTC - Display 2  (tens), 
 *       PORTD - Display 3  (units)
;		 RD7   - Display 4  (negative sign).
;
; Autor:	 Brahian Felipe Hurtado Erazo  TMS  
;		    
;
; Version: 1.0
;
 * File:   Calculator-8-bits.c

 * Created on 6 de marzo de 2019, 05:47 PM
 */

#include <stdio.h>
#include <xc.h>
#include <pic16f887.h>
#include "config.h"


void show_number(int num);
int table_display(int c);


void main() {
    
        int num1;                                       //var 1 number
        int num2;                                       //var 2 number
        
        ANSEL=0;        
        ANSELH=0;                                       //INPUT  digital
        
        TRISA=0;                                         //PORTA output (hundreds)
        TRISC=0b10000000;                                //PORTC output (tens)),  RC7 Push Button new operation
        TRISD=0;                                         //PORTD output ((units))
        
        TRISB=0b11111111;                               //PORTB input dip switch 8    
        TRISE=0b00001111;                                //RE0,RE1,RE2 Push Button 1,2,3.
                    
        PORTA= 0x7E;                                     // Displays started "0".
        PORTC= 0x7E;
        PORTD= 0x7E;
        
}

void show_number(int num){                          //Implementation function show_number
    
    int un,dec,cen;                                 //Declare var un, dec, cen
      
    cen=(int)((num/100));                           //Split digits number
        PORTA=table_display(cen);
    
    dec=(int)((num-(cen*100))/10);
        PORTC=table_display(dec);
        
    un=(int)(num%10);
        PORTD=table_display(un);
}

int table_display(int c){                           //Implementation function 
                                                    //this function returns the number to turn on the segments of each number for show un Deco BCD

    int number;                                     
    
    switch(c){
        
        case 0:                   
            number=0x7E;            // OUTPUT for number "0".
            break;
        case 1:                 
            number= 0x30;          // OUTPUT for number "1".
            break;
        case 2:          
            number= 0x6D;          //  OUTPUT for number "2".
            break;
        case 3:               
            number=0x79;          // OUTPUT for number "3".
            break;
        case 4:                
            number=0x33;         //  OUTPUT for number "4".
            break;
        case 5:                
            number=0x5B;         // OUTPUT for number "5".
            break;
        case 6:                
            number=0x5F;         // OUTPUT for number "6".
            break;
        case 7:                  
            number=0x70;         //  OUTPUT for number "7".
            break;
        case 8:               
            number=0x7F;			// OUTPUT for number "8".
            break;
        case 9:                  
            number=0x73;         //  OUTPUT for number "9". 
            break;  
    }
    return number;
  
}
