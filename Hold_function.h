#pragma once
/*========================================================================================================================*/

  // USE the tabs
  #include "variables.h"
  #include "switch_PageSettings.h"
  #include "screenSetup.h"
  #include "Tuner.h"
  #include "Screenstyle.h"
  #include "switchSelect.h"

/*---------------------------------------------------------------------------------------------------------------------------------------*/

  void holdSceneEffect()
  {
    debug("\n"); debug(" RUN scene_effectSelection()");
    scene_effectSelection(); 
    strcpy(page, "stillHOLD");
    HOLDfunction = true; 
    debug("\n"); debug(" page set to = "); debug(page);
  }

//---------------------------------------------------------------------------------------------------------------------------
   
  void holdLooperEffect()
  {
    debug("\n"); debug(" RUN looperPage_selection()");
    looperPage_selection();
    strcpy(page, "stillHOLD");
    HOLDfunction = true; 
    debug("\n"); debug(" page set to = "); debug(page);
  }

//---------------------------------------------------------------------------------------------------------------------------

  void holdEffectEffect()
  {
    debug("\n"); debug(" RUN effectSelection()");
    effectSelection();
    strcpy(page, "stillHOLD");
    HOLDfunction = true; 
    debug("\n"); debug(" page set to = "); debug(page);
  }


void holdAuditionEffect()
  {
    debug("\n"); debug(" RUN auditionMode Selection()");
    sceneswitch_13;  //PresetPage layout
    presetswitch_13; //AuditionMode layout
    strcpy(page, "stillHOLD");
    HOLDfunction = true; 
    debug("\n"); debug(" page set to = "); debug(page);
    }

//---------------------------------------------------------------------------------------------------------------------------
   
    void sceneReselect()
      {
        debug("\n"); debug(" previousHOLDSWITCH value = "); debug(previousHOLDSWITCH);
        debug("\n"); debug(" HOLDSWITCH value = "); debug(HOLDSWITCH);
        if (previousHOLDSWITCH == HOLDSWITCH)  //See if selected switch allready is equal to previousholdswitch
          {
            sceneReselected = true;
            debug("\n"); debug(" Okay, sceneReselected value = true "); 
            debug("\n"); debug(" Scene reselected and started function sceneSelection();");
            reset_effectbypass_state = true; 
            debug("\n"); debug(" reset_effectbypass_state is set to: "); debug(reset_effectbypass_state);
            sceneSelection();
          }
              else
              {
              sceneReselected = false;
              debug("\n"); debug(" Okay, sceneReselected value = false ");
              debug("\n"); debug(" started function sceneSelection();");
              effectvariable_reset();
              sceneSelection();
              }
      }

  
/*=======================================================================================================================================*/
//   HOLD FUNCTION
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void checkButton()  
{     
    holdTimeResult = (millis() - timeStart);
    debug("\n"); debug(" millis - timestart = "); debug(holdTimeResult);
    
    if (holdTimeResult >= holdTime) // HOLD press
    {
    debug("\n"); debug(" Active page = "); debug(page);
    debug("\n"); debug(" holdAction value = "); debug(holdAction);            

  
    switch (holdAction)
     {
      case 1: debug("\n"); debug(" started function holdSceneEffect();"); holdSceneEffect(); break; 
      case 2: debug("\n"); debug(" started function holdSceneEffect();"); holdSceneEffect(); break;
      case 3: debug("\n"); debug(" started function holdSceneEffect();"); holdSceneEffect(); break;              
      case 4: debug("\n"); debug(" started function holdLooperEffect();"); holdLooperEffect(); break;  
      case 5: debug("\n"); debug(" started function holdEffectEffect();"); holdEffectEffect(); break; 
      case 6: debug("\n"); debug(" started function holdAuditionEffect();"); holdAuditionEffect(); break;
      }
    }
       
           
  if (digitalRead(HOLDSWITCH) == HIGH)  // short press
  {
    if ((holdTimeResult >= 119) && (holdTimeResult < holdTime))
    {
     reset_effectbypass_state = false;
     timeStart = 0;
     debug("\n"); debug(" timeStart set to 0 >> SHORT press "); 
     debug("\n"); debug(" holdAction value = "); debug(holdAction);
     switch (holdAction)
     {
     case 1: debug("\n"); debug(" started function sceneReselect()to check if Re-select = true;"); sceneReselect(); break;
     case 2: debug("\n"); debug(" started function sceneswitch_5;"); sceneswitch_5;   break; 
     case 3: debug("\n"); debug(" started function sceneswitch_10;"); sceneswitch_10; break;                
     case 4: debug("\n"); debug(" started function ampabcdPage_selection();"); holdLooperEffect(); break; 
     case 5: debug("\n"); debug(" started function holdEffectEffect();"); holdEffectEffect(); break;
     case 6: debug("\n"); debug(" started function holdEffectEffect();"); sceneswitch_13; break;
     }
    }
  }
}

//---------------------------------------------------------------------------------------------------------------------------


// This code runs from the loop() when button is still pressed after execution of the function ^^ above ^^
void checkStillHoldButton()
{
    holdTimeResult = (millis() - timeStart);
        if ((digitalRead(HOLDSWITCH) == LOW) && (HOLDfunction == true))
        {
          debug("\n"); debug(" STILL HOLDING THE BUTTON DOWN");
          HOLDfunction = false;
          }
          else if (digitalRead(HOLDSWITCH) == HIGH) 
           {
          debug("\n"); debug(" BUTTON HAS BEEN RELEASED ");
          timeStart = 0;
          strcpy(page,HOLDpage);
          sceneReselected = false;
          debug("\n"); debug(" page set to: "); debug(page); 
          delay(100); 
           }
}   
