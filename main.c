#include <xc.h>
#include "config.h"
#define _XTAL_FREQ 32000000

void main(void) {
    int r;
    //OSCILADOR 
    OSCFRQbits.HFFRQ=0b110; //A 32MHz
    //TIERRAS
   
    //PUERTOS
    PORTC=0;
    ANSELC=0;
    TRISC=0;
    
    //PUERTOS PWM
    PORTB=0;
    ANSELB=0;
    TRISB=255;
    
    //PPS
    RC0PPS=0X09;
    
    //TIMER2
    PR2=255; //SEÑAL PWM DE 8.81KHz 
    T2CLKCON=0b0001; //CS FOSC/4
    T2CONbits.CKPS=0b010; //PRESCALER 1:4
    T2CONbits.OUTPS=0; //POSTSCALER 1:1
    T2CONbits.ON=1; //ENCIENDE EL TIMER 2
    
    //CCP1
    CCP1CONbits.EN=1; //HABILITA CCP
    CCP1CONbits.FMT=0; //JUSTIFICADO A LA DERECHA
    CCP1CONbits.MODE=0b1111; //MODO PWM
    CCPTMRS0bits.C1TSEL=0b01; //TIMER2--->CCP1
    TRISC=0; //PUERTO B COMO SALIDA
    
    while(1){
      //VA AUMENTANDO EL CICLO DE TRABAJO
       
        
        //*******CONDICIONES PARA MANTENER AL SEGUIDOR EN LA PISTA*******
        if(PORTBbits.RB0==1 & PORTBbits.RB1==1){
            LATC2=0;
            LATC3=0;
             CCPR1=850;
        }
        
        if(PORTBbits.RB0==1 & PORTBbits.RB1==0){
            r=1;
            LATC2=0;
            LATC3=1;
             CCPR1=700;
        }
        
        if(PORTBbits.RB0==0 & PORTBbits.RB1==1){
            r=2;
            LATC2=1;
            LATC3=0;
             CCPR1=700;
        }
        
        if(PORTBbits.RB0==0 & PORTBbits.RB1==0 & r==2){
            LATC2=1;
            LATC3=0;
             CCPR1=700;
            
        }
        
        if(PORTBbits.RB0==0 & PORTBbits.RB1==0 & r==1){
            LATC2=0;
            LATC3=1;
             CCPR1=700;
        }
        /////////////////////////////////////////////////////
          if(PORTBbits.RB2==0 & PORTBbits.RB3==0){
            LATC2=0;
            LATC3=0;
             CCPR1=850;
        }
        
        if(PORTBbits.RB2==1 & PORTBbits.RB3==0){
            r=1;
            LATC2=0;
            LATC3=1;
             CCPR1=700;
        }
        
        if(PORTBbits.RB2==0 & PORTBbits.RB3==1){
            r=2;
            LATC2=1;
            LATC3=0;
             CCPR1=700;
        }
        
        if(PORTBbits.RB2==0 & PORTBbits.RB3==0 & r==2){
            LATC2=1;
            LATC3=0;
             CCPR1=700;
        }
        
        if(PORTBbits.RB2==0 & PORTBbits.RB3==0 & r==1){
            LATC2=0;
            LATC3=1;
             CCPR1=700;
        }
        ////////////////////////////////////////////////////////////////////
        
     if(PORTBbits.RB4==0 & PORTBbits.RB5==0){
            LATC2=0;
            LATC3=0;
             CCPR1=850;
        }
        
        if(PORTBbits.RB4==1 & PORTBbits.RB5==0){
            r=1;
            LATC2=0;
            LATC3=1;
             CCPR1=700;
        }
        
        if(PORTBbits.RB4==0 & PORTBbits.RB5==1){
            r=2;
            LATC2=1;
            LATC3=0;
             CCPR1=700;
        }
        
        if(PORTBbits.RB4==0 & PORTBbits.RB5==0 & r==2){
            LATC2=1;
            LATC3=0;
             CCPR1=700;
        }
        
        if(PORTBbits.RB4==0 & PORTBbits.RB5==0 & r==1){
            LATC2=0;
            LATC3=1;
             CCPR1=7090;
        }
    }
    return;
}

