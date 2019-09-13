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
 *       PORTA - Display 1  (units), 
 *       PORTC - Display 2  (tens), 
 *       PORTD - Display 3  (hundreds).
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
