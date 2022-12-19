  /* 
  =======================================================================================================================================
  ======================================================================================================================================= 
   
                                                ██████╗░░█████╗░██████╗░██╗
                                                ██╔══██╗██╔══██╗██╔══██╗██║
                                                ██████╔╝███████║██████╔╝██║
                                                ██╔═══╝░██╔══██║██╔══██╗██║
                                                ██║░░░░░██║░░██║██║░░██║██║
                                                ╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝
                                                                    परी
                                                                                                                               
                                                                                                                             
  
                                                    Axe-FXIII midi sysex foot controller
  
  
                                                  Axelman8 |  - Rotterdam -  | Netherlands
                                                     
  
  =======================================================================================================================================
  !! using AxeFxControl libriary from @tysonIT -> Without this libriary, this project would be just a bunch of useless code.
  !! Started from scratch with help of the shared programming of: @prongs_386 | @tysonIT | @Piing from the Fractal audio forum.
  =======================================================================================================================================
  
  (on SD_ini.h)
  @@@  DEBUGGING the program:  
    -> DEBUG (serial) code OFF = 0  | DEBUG output is very usefull to see the flow of the program code 
    -> Set to DEBUG and flash to Arduino to see program output in the Serial monitor  
    -> The Serial.begin = baudrate...   make sure that the serial monitor has the same baudrate as the uncommented baudrate.
       For best serial and program use,  9600 or 115200 is advized.
    
    NOTE to the reader:   
    -> See y_changeLog.h for any changes in this or previous versions

  =======================================================================================================================================
      INCLUDE LIBRIARY'S
  =======================================================================================================================================*/

  // USE the libriary
  #include <Timer.h>
  #include <Arduino.h>
  #include <AxeFxControl.h>
  #include <Wire.h>
  #include <malloc.h>
  #include <SD_ini.h>
  #include <PIN_ini.h>
  
  //RAM usage shown in the serial monitor
  #include <MemoryFree.h>
  
  // USE the tabs
  #include "Hold_function.h"
  #include "variables.h"
  #include "switch_PageSettings.h"
  #include "screenSetup.h"
  #include "Tuner.h"
  #include "Screenstyle.h"


/*=======================================================================================================================================*/
//    SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void setup() 
{

/*=======================================================================================================================================*/
//    SERIAL DEBUGGER and SERIAL BAUD
/*---------------------------------------------------------------------------------------------------------------------------------------*/

//Set SERIAL baud rate:
  while (!Serial);
  //Serial.begin(9600);   // Works good with the Serial.  Not very quick screen refresh on the peddleboard but it works good.
  Serial.begin(115200); // Works good with the Serial.  Some quicker screen refresh on the peddleboard. Looks very nice i like it.
  //Serial.begin(230400); // Does not work good with the Serial. Good screen refresh rates on the peddleboard :) 
  //Serial.begin(500000); // Forget the Serial, but screen refresh rate.  #TESTED:  It will work good for at least 3 hours straight!
  //Serial.begin(1000000);  // Screen refresh rate is awesome, my favor-it. #NOT TESTED: I dont know if it will hold up for 3 hours straight!
  Serial.flush();


/*=======================================================================================================================================*/
//    SETUP MEMORY INFO
/*---------------------------------------------------------------------------------------------------------------------------------------*/
 char* heapend = sbrk(0);
 register char* stack_ptr asm("sp");
 struct mallinfo mi = mallinfo();
 if (MaxUsedStaticRAM < &_end - ramstart)
 { MaxUsedStaticRAM = &_end - ramstart; }
 
 if (MaxUsedHeapRAM < mi.uordblks)
 { MaxUsedHeapRAM = mi.uordblks; }
 
 if (MaxUsedStackRAM < ramend - stack_ptr)
 { MaxUsedStackRAM = ramend - stack_ptr; }
 
 if (MinfreeRAM > stack_ptr - heapend + mi.fordblks || MinfreeRAM == 0)
 { MinfreeRAM = stack_ptr - heapend + mi.fordblks; }

 Serial.println();
 Serial.println(" =====  * AXELMAN8 *  =====");
 Serial.println(" PARI Axe FX III controller");
 Serial.println(" ==============================");
 Serial.println(" MEMORY INFORMATION ON START-UP");
 Serial.print  (" ==============================");
 Serial.println(); Serial.print(" Max Used RAM STATIC: ");
 Serial.println(MaxUsedStaticRAM);
 Serial.print(" HEAP: ");
 Serial.println(MaxUsedHeapRAM);
 Serial.print(" STACK: ");
 Serial.println(MaxUsedStackRAM);
 Serial.print(" Min FREE RAM: ");
 Serial.println(MinfreeRAM);
 Serial.println(" ==============================");
 Serial.println();


/*=======================================================================================================================================*/
//    CLOCK SETTINGS
/*---------------------------------------------------------------------------------------------------------------------------------------*/
//
/* -- Time clock settings -- See axe_handler.h for code how its working */
  rtc.begin();
  
// 1st time use: set the hh:mm:ss like (13,13,13) (24hr format) before uploading. 
// Uncomment it, and after upload, comment this line and upload again. The unit has your time in memory. */
 // rtc.setTime(16, 10, 00);
  t = rtc.getTime();
  
/*=======================================================================================================================================*/
//    MIDI SETUP
/*---------------------------------------------------------------------------------------------------------------------------------------*/
  
/* -- MIDI settings  (Also see variables_ini.h) --*/
  byte MidiChannel = midichannelSet;
  MIDI.begin(0);
  MIDI.turnThruOff();

/*=======================================================================================================================================*/
//    CALL-BACK's
/*---------------------------------------------------------------------------------------------------------------------------------------*/

/* AxeController settings -- */
  Axe.begin(serial);
  Axe.requestPresetDetails();
  Axe.registerSystemChangeCallback(onSystemChange);  // tab tempo
  Axe.registerPresetChangingCallback(onPresetChanging); // New preset with all scenenames, effects
  Axe.registerPresetChangeCallback(onPresetChange);  // New preset selection:  update info new presetname, active scenename, effects
  Axe.registerSceneNameCallback(onSceneName); // run after onPresetChanging.  get all scenenames
  Axe.registerEffectsReceivedCallback(onEffectsReceived);
  Axe.registerEffectFilterCallback(onEffectFilter);
  Axe.registerTapTempoCallback(onTapTempo);
  Axe.registerTunerStatusCallback(onTunerStatus);
  Axe.registerTunerDataCallback(onTunerData);


/*=======================================================================================================================================*/
//    SETUP 16*2 LCD 
/*---------------------------------------------------------------------------------------------------------------------------------------*/

 /* -- 16*2 LCD startup Message: -- */
  lcd.clear();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Music In Control");
  lcd.setCursor(0, 1);
  lcd.print("|- AXE-FX-III -|");


/*=======================================================================================================================================*/
//    SETUP SWITCHES
/*---------------------------------------------------------------------------------------------------------------------------------------*/

  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ )
  {
    pinMode( switches[currentSwitch], INPUT_PULLUP);    // Set all pins for switch
    digitalWrite( switches[currentSwitch], HIGH );      // Turn on all pins with internal pullup HIGH
  }


/* Startup with the scenepage..this is crusial for the program to work correctly */
  strcpy(page, "scene");  //This will set the active page to scenes (and we want that)


// setup all the screens on 1st boot:
   bootscreen_setup();  //screenSetup.h  Showing bootscreen with red white bleu Axe FX III information



  //Initializing 1st setup:
  ini_screens(); // setting_switches.h building up the screens and initializing for scene information
  auditionMode = false; // Auditionmode is a option on the preset page. Fist time initializing it is allways off.
  tapSwitch = false;  // axe_handler.h setting the TAPtempo info from the AxeFXIII on the screen.
  getScenes = true;   // axe_handler.h first time getting scenes from the AxeFXIII to show on the display's.
  effectCycle = true; // axe_handler.h first time getting effects from the AxeFXIII for Wah and Looper information.
  presetRange(); // setting_switches.h filling the presetnames of active bank (active preset)
  serialprint_memory_info();
}

/*=======================================================================================================================================*/
//    LOOP
/*---------------------------------------------------------------------------------------------------------------------------------------*/


void loop() 
{
  Axe.update();
  timer.update();
  
 
 if (Axe.isTunerEngaged() == false)  // TUNER is NOT active
  { 
    /*======================================*/
    //   This code is for HOLD button push  
    /*======================================*/
      if (strcmp(page, "HOLD") == 0)
      {digitalClockDisplay(); checkButton();}
    
      else if (strcmp(page, "stillHOLD") == 0)
      {digitalClockDisplay(); checkStillHoldButton();}
    /*======================================*/
    
    
    
    /*===== LOOKUP the active screen in Setup.h and use setting_switches.h for buttons and screen updates of looper  ===========*/
      else if (strcmp(page, "scene") == 0)
      { digitalClockDisplay(); scenes_settings();}
    
      else if (strcmp(page, "preset") == 0)
      { digitalClockDisplay(); preset_settings();}
      
      else if (strcmp(page, "effect") == 0)
      { digitalClockDisplay(); effect_settings();}
      
      else if (strcmp(page, "looper") == 0)
      { digitalClockDisplay(); looper_settings();}
      
      else if (strcmp(page, "numbers") == 0)
      { digitalClockDisplay(); numbers_settings();}
  }
  else 
  { onlyTuner();}  // this shuts all off just for the tuner ... it works really good ... see Tuner.h
}



/*=======================================================================================================================================*/
/*Axelman8*/
