#pragma once

#include <Arduino.h>
#include <Timer.h>
#include <DS3231.h>

/*=======================================================================================================================================*/

byte SWITCH;  //universal name that gets assigned with a SWITCH in a loop
byte CS;      //universal name that gets assigned with a CS*NUMBER* in a loop

/*=======================================================================================================================================*/

/* ===========================================================================================================================
//  SCREEN and PIN BUILT UP | SETTINGS        
// ===========================================================================================================================

                  controller buildup  buttons and screens
          
                                     - TOP -              
               -------------------------------------------              
               PIN screen     48 | 47 | 44 | 45 | 41 | lcd
              *switch nr      11 | 12 | 13 | 14 | 15 | 18        
               PIN switch     27 | 26 | 23 | 24 | 22 | 32
               ------------------+----+----+----+----+----       
               PIN screen     43 | 37 | 35 | 33 | 49 | 
              *switch nr      06 | 07 | 08 | 09 | 10 | 17        
               PIN switch     9  | 11 | 12 | 13 | 28 | 31
               ------------------+----+----+----+----+----       
               PIN screen     34 | 36 | 40 | 42 | 46 | 
              *switch nr      01 | 02 | 03 | 04 | 05 | 16        
               PIN switch     3  | 5  | 6  | 7  | 25 | 30
               -------------------------------------------       
                                   - BOTTOM -                    

             
               16 x 2 lcd =    SDA  pin -> 20
                               SCL  pin -> 21
               led =                pin -> 29
               DS3231:         SDA1 pin -> 70
                               SCL1 pin -> 71

================================================================================================================================= */

#define M_SIZE 1
#define SWITCH1 3
#define SWITCH2 5
#define SWITCH3 6
#define SWITCH4 7
#define SWITCH5 25
#define SWITCH6 9
#define SWITCH7 11
#define SWITCH8 12
#define SWITCH9 13
#define SWITCH10 28
#define SWITCH11 27
#define SWITCH12 26
#define SWITCH13 23
#define SWITCH14 24
#define SWITCH15 22
#define SWITCH16 30
#define SWITCH17 31
#define SWITCH18 32

 
//Screens pinnumbers with CS number:
#define CS1 34
#define CS2 36
#define CS3 40
#define CS4 42
#define CS5 46
#define CS6 43
#define CS7 37
#define CS8 35
#define CS9 33
#define CS10 49
#define CS11 48
#define CS12 47
#define CS13 44
#define CS14 45
#define CS15 41 




//===  test GPIO ports for the screen buildup  ===
#define CS1L (REG_PIOC_CODR = 0x1 << 2)
#define CS2L (REG_PIOC_CODR = 0x1 << 4)
#define CS3L (REG_PIOC_CODR = 0x1 << 8)
#define CS4L (REG_PIOA_CODR = 0x1 << 19)
#define CS5L (REG_PIOC_CODR = 0x1 << 17)
#define CS6L (REG_PIOA_CODR = 0x1 << 20)
#define CS7L (REG_PIOC_CODR = 0x1 << 5)
#define CS8L (REG_PIOC_CODR = 0x1 << 3)
#define CS9L (REG_PIOC_CODR = 0x1 << 1)
#define CS10L (REG_PIOC_CODR = 0x1 << 14)
#define CS11L (REG_PIOC_CODR = 0x1 << 15)
#define CS12L (REG_PIOC_CODR = 0x1 << 16)
#define CS13L (REG_PIOC_CODR = 0x1 << 19)
#define CS14L (REG_PIOC_CODR = 0x1 << 18)
#define CS15L (REG_PIOC_CODR = 0x1 << 9)

#define CS1H (REG_PIOC_SODR = 0x1 << 2)
#define CS2H (REG_PIOC_SODR = 0x1 << 4)
#define CS3H (REG_PIOC_SODR = 0x1 << 8)
#define CS4H (REG_PIOA_SODR = 0x1 << 19)
#define CS5H (REG_PIOC_SODR = 0x1 << 17)
#define CS6H (REG_PIOA_SODR = 0x1 << 20)
#define CS7H (REG_PIOC_SODR = 0x1 << 5)
#define CS8H (REG_PIOC_SODR = 0x1 << 3)
#define CS9H (REG_PIOC_SODR = 0x1 << 1)
#define CS10H (REG_PIOC_SODR = 0x1 << 14)
#define CS11H (REG_PIOC_SODR = 0x1 << 15)
#define CS12H (REG_PIOC_SODR = 0x1 << 16)
#define CS13H (REG_PIOC_SODR = 0x1 << 19)
#define CS14H (REG_PIOC_SODR = 0x1 << 18)
#define CS15H (REG_PIOC_SODR = 0x1 << 9)


//===  test GPIO ports for the SWITCHES  ===
/*
#define SWITCH1 (REG_PIOC_SODR = 0x1 << 28)
#define SWITCH2 (REG_PIOC_SODR = 0x1 << 25)
#define SWITCH3 (REG_PIOC_SODR = 0x1 << 24)
#define SWITCH4 (REG_PIOC_SODR = 0x1 << 23)
#define SWITCH5 (REG_PIOD_SODR = 0x1 << 0)
#define SWITCH6 (REG_PIOC_SODR = 0x1 << 21)
#define SWITCH7 (REG_PIOD_SODR = 0x1 << 7)
#define SWITCH8 (REG_PIOD_SODR = 0x1 << 8)
#define SWITCH9 (REG_PIOB_SODR = 0x1 << 27)
#define SWITCH10 (REG_PIOD_SODR = 0x1 << 3)
#define SWITCH11 (REG_PIOD_SODR = 0x1 << 2)
#define SWITCH12 (REG_PIOD_SODR = 0x1 << 1)
#define SWITCH13 (REG_PIOA_SODR = 0x1 << 14)
#define SWITCH14 (REG_PIOA_SODR = 0x1 << 15)
#define SWITCH15 (REG_PIOB_SODR = 0x1 << 26)
#define SWITCH16 (REG_PIOD_SODR = 0x1 << 9)
#define SWITCH17 (REG_PIOA_SODR = 0x1 << 7)
#define SWITCH18 (REG_PIOD_SODR = 0x1 << 10)*/


/* #define SWITCH1 (REG_PIOC_CODR = 0x1 << 28)
#define SWITCH2 (REG_PIOC_CODR = 0x1 << 25)
#define SWITCH3 (REG_PIOC_CODR = 0x1 << 24)
#define SWITCH4 (REG_PIOC_CODR = 0x1 << 23)
#define SWITCH5 (REG_PIOD_CODR = 0x1 << 0)
#define SWITCH6 (REG_PIOC_CODR = 0x1 << 21)
#define SWITCH7 (REG_PIOD_CODR = 0x1 << 7)
#define SWITCH8 (REG_PIOD_CODR = 0x1 << 8)
#define SWITCH9 (REG_PIOB_CODR = 0x1 << 27)
#define SWITCH10 (REG_PIOD_CODR = 0x1 << 3)
#define SWITCH11 (REG_PIOD_CODR = 0x1 << 2)
#define SWITCH12 (REG_PIOD_CODR = 0x1 << 1)
#define SWITCH13 (REG_PIOA_CODR = 0x1 << 14)
#define SWITCH14 (REG_PIOA_CODR = 0x1 << 15)
#define SWITCH15 (REG_PIOB_CODR = 0x1 << 26)
#define SWITCH16 (REG_PIOD_CODR = 0x1 << 9)
#define SWITCH17 (REG_PIOA_CODR = 0x1 << 7)
#define SWITCH18 (REG_PIOD_CODR = 0x1 << 10) */




/*=======================================================================================================================================*/
//    PEDDLEBOARD CONFIG WITH 15 OR 18 BUTTONS 
/*=======================================================================================================================================*/
byte HOLDSWITCH;
byte previousHOLDSWITCH;

byte switches[18] = { SWITCH1, SWITCH2, SWITCH3, SWITCH4, SWITCH5, SWITCH6, SWITCH7, SWITCH8, SWITCH9,  
                      SWITCH10,SWITCH11, SWITCH12, SWITCH13, SWITCH14, SWITCH15, SWITCH16, SWITCH17, SWITCH18};
byte switchState[18] = {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH};

/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*Axelman8*/  
