#pragma once

/*=======================================================================================================================================*/
/*

 _______   ______      .__   __.   ______   .___________.     ______  __    __       ___      .__   __.   _______  _______ 
|       \ /  __  \     |  \ |  |  /  __  \  |           |    /      ||  |  |  |     /   \     |  \ |  |  /  _____||   ____|
|  .--.  |  |  |  |    |   \|  | |  |  |  | `---|  |----`   |  ,----'|  |__|  |    /  ^  \    |   \|  | |  |  __  |  |__   
|  |  |  |  |  |  |    |  . `  | |  |  |  |     |  |        |  |     |   __   |   /  /_\  \   |  . `  | |  | |_ | |   __|  
|  '--'  |  `--'  |    |  |\   | |  `--'  |     |  |        |  `----.|  |  |  |  /  _____  \  |  |\   | |  |__| | |  |____ 
|_______/ \______/     |__| \__|  \______/      |__|         \______||__|  |__| /__/     \__\ |__| \__|  \______| |_______|
                                                                                                                           



 =========================   -  Include library's  -  ==============================*/
#include <MIDI.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h> // include i/o class header
#include <TFT_eSPI.h>
#include <SPI.h>
#include <DS3231.h>
#include <SD_ini.h>
#include <PIN_ini.h>


#define midichannelSet 1
#define serial Serial1


/*===================================================================================*/

//MIDI_CREATE_INSTANCE(Type, SerialPort, Name)
 MIDI_CREATE_INSTANCE(HardwareSerial, serial, MIDI);

/*===================================================================================*/


/* -- Time clock -- */
  
DS3231  rtc(70, 71);
Time t;

/* -- TFT setting -- */
TFT_eSPI tft = TFT_eSPI(); 

/* -- 16*2 lcd -- */
hd44780_I2Cexp lcd; 

char page[] = "Axelman8";
char HOLDpage[] = "Axelman8";

AxeSystem Axe;
Tempo tempo;
Timer timer;


/*========================================================================================================================================*/
//    SYSTEM SETTINGS
/*========================================================================================================================================*/

#define MIDICHAN 1 
#define TAP_TEMPO_LED_DURATION 100
#define SceneSelect_CC 34
#define NUM_SCENES 8
#define NUM_PRESET 10


/*========================================================================================================================================*/
//     RAM usage shown in the serial monitor
/*========================================================================================================================================*/

unsigned long previousMillisStatePrint;
const unsigned long WaitingTimeStatePrint = 1000;
uint32_t MaxUsedHeapRAM;
uint32_t MaxUsedStackRAM;
uint32_t MaxUsedStaticRAM;
uint32_t MinfreeRAM;
extern char _end;
extern "C" char* sbrk(int i);
char* ramstart = (char*)0x20070000;
char* ramend = (char*)0x20088000;


/*========================================================================================================================================*/
//     VARIABLES
/*========================================================================================================================================*/

char active_PresetName[33],Preset_Name[33],previousPresetName[33],nextPresetName[33], PresetName0[33], PresetName1[33], PresetName2[33], 
     PresetName3[33], PresetName4[33], PresetName5[33], PresetName6[33], PresetName7[33], PresetName8[33], PresetName9[33];
char Preset_name[] = "Axelman8";
char tuner_type[] = " CIRCLE ";


//=====  Scene name alignment management  ========
//scenenames per row on tft-screen
char 
SCE11[16],SCE12[16],SCE13[16],
SCE21[16],SCE22[16],SCE23[16],
SCE31[16],SCE32[16],SCE33[16],
SCE41[16],SCE42[16],SCE43[16],
SCE51[16],SCE52[16],SCE53[16],
SCE61[16],SCE62[16],SCE63[16],
SCE71[16],SCE72[16],SCE73[16],
SCE81[16],SCE82[16],SCE83[16],
PRE11[32],PRE12[32],PRE13[32];

char 
amp11[50],amp12[50],amp13[50],
amp21[50],amp22[50],amp23[50],
amp31[50],amp32[50],amp33[50],
amp41[50],amp42[50],amp43[50];

char 
Amp[50],
AMP1_A[50],AMP1_B[50],AMP1_C[50],AMP1_D[50],
AMP2_A[50],AMP2_B[50],AMP2_C[50],AMP2_D[50];


bool select_AMP_1 = false; 
bool select_AMP_2 = false; 
bool select_AMP_start = false;


//Length of scenenames per row per scene
String stringScene;
String stringPreset;
String stringAmp;


byte 
L11,L12,L13,
L21,L22,L23,
L31,L32,L33,
L41,L42,L43,
L51,L52,L53,
L61,L62,L63,
L71,L72,L73,
L81,L82,L83;

byte  //amp
A_11,A_12,A_13,
A_21,A_22,A_23,
A_31,A_32,A_33,
A_41,A_42,A_43;

byte P11,P12,P13;
byte Cursor;
byte PNtxtWidth = 0;
byte PNtxtHeight = 100;

//extracted word from the string max 4 words
String str1,str2,str3;
String pre1,pre2,pre3;
String amp_1,amp_2,amp_3;
String CAB;
String sceneNumbers;

//extracted rows from the string | 1 row per word.
byte row1,row2,row3;
byte prow1,prow2,prow3;
byte Arow1,Arow2,Arow3;
byte AMPnumber;


/*===================================================================================*/

int counter;
int PresetNumb;     // Initial preset number for preset selection (first one of the ten)
int Preset_Number; // This is presetnumber conversion for all 10 presetnumbers
int CurPreset;      // current preset that is selected from preset up/down or bank up/down
int active_Preset;  // setting the AxeFX active presetnumber
int selectedSwitch;

int previousPreset;
int previousPresetnr;
int nextPreset;
int nextPresetnr;


//numbers selection for choosing your preset with a number:
byte stringLength;
byte inputNumber;
byte n1;
byte n2;
int  n3;  // > 255, byte is not possible
int  n4;  // > 255, byte is not possible
byte Counter;
byte sceneNumber;
byte loopPreset;

byte  effect17, effect18, effect19,     // effects 17-19 used for "AMP CAB abcd" settings
      thisEffect, effect0, effect1, effect2, effect3, effect4, effect5, effect6, effect7,effect8, effect9, effect10, //effect 1-10 used for effect settings on screen 1-10
      effect11, effect12, effect13, effect14,effect15, effect16;   // effects 1-10 and 11-16 are used for the LOOPER and WAH available function
      
byte active_Scene;  // active scene number
byte effectindex;
byte currentSwitch = 0;
byte currentEffect = 0;
byte changeCurrentEffect = 0;

// TAP-TEMPO
byte tapTempo;   // Used for setting tap tempo with numbers
byte flashhight_tempo_Text; // 
byte tempo_Counter = 0; // For the "4 balls" tempo sprite
byte buttonPin;  // input pin for HOLD button function
byte holdAction = 0;


bool tapSwitch;
bool getScenes;
bool effectCycle;
bool effect0_bypass = false; bool effect1_bypass = false; bool effect2_bypass = false; bool effect3_bypass = false; bool effect4_bypass = false; bool effect5_bypass = false;
bool effect6_bypass = false; bool effect7_bypass = false; bool effect8_bypass = false; bool effect9_bypass = false; bool effect10_bypass = false;
bool effectbypass;
bool reset_effectbypass_state = false;
bool auditionMode = false;
bool looperActive;
bool wahActive;
bool sceneReselected = false;
bool upDown = false;
bool HOLDfunction = false;
boolean modeVal1 = false;    // state of Mode 1 (Tune / Mem)
boolean modeVal2 = false;    // state of Mode 2 (Mem mode=Store Mem / Tune mode = ignore)


String channel = "X";

unsigned long lastMillis;             //for digital clock
byte presetBank;
 
/* ================================================================================================================================= */
/*Axelman8*/
