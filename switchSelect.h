#pragma once


/*===========================================   -  Include library's  -  ================================================*/

#include <AxeFxControl.h>


#include "Screenstyle.h"
#include "axe_handler.h"
#include "Preset_range.h"
#include "screenSetup.h"


/*=======================================================================================================================================*/
/*   +++++    SCREEN SELECT      +++++     DO NOT EDIT THESE CODES   +++++     
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void scenePage_selection()
{
  if (holdAction == 0)
  {
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function scenePage_selection started on switchSelect.h");

  if (auditionMode == true)
  {exit_auditionmodeTopscreens();}
  
  auditionMode = false;
  debugln();debug(" -> auditionmode set to: ");debug(auditionMode);
  currentEffect = 0;
  Counter = 0;
  getScenes = true;
  effectCycle = true;
  debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
  debugln(); debug(" -> getScenes set to: "); debug(getScenes);  
  if (strcmp(page, "effect") == 0)
  {
    if (RESET_EFFECT == true)  // when going to scenepage, reset effects true or false? 
    {
      reset_effectbypass_state = true;
      }
  }
  Axe.refresh(); 
  sceneTopscreens();
  scenepageRebuild();
  ini_scenes();
  }
}


/*==================   OR  ========================*/
void presetPage_selection()
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function presetPage_selection started on switchSelect.h");

  strcpy(page, "preset"); 
  debugln(); debug(" * PAGE is set to: "); debug(page);   

  auditionMode = false;
  getScenes = false;
  effectCycle = true;
  presetRange();
  ini_preset();
  presetTopscreens();

  debugln(); debug (" -> auditionmode set to: ");  debug(auditionMode);
  debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
  debugln(); debug(" -> getScenes set to: ");   debug(getScenes); 
}


/*==================   OR  ========================*/
void looperPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debug(" * function looperPage_selection started on switchSelect.h"); 

  strcpy(page, "looper");
  debugln(); debug(" * PAGE is set to: ");debug(page);
  ini_looper();
  looperTopscreens();
}

/*==================   OR  ========================*/
void numberPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln();debugln();  debug(" * function numberPage_selection started on switchSelect.h");   

  strcpy(page, "numbers");
  debugln(); debug(" * PAGE is set to: "); debug(page);

  if (auditionMode != true)
  {numberTopscreens();} 
  Counter = 0;
  ini_numbers();
 }

/*==================   OR  ========================*/
void effectPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln(); debugln(); debug(" * function effectPage_selection started on switchSelect.h");

  if (auditionMode == 0)  // On auditionMode leave topscreens as is....
  {
  strcpy(page, "effect");
  debugln(); debug(" * PAGE is set to: ");debug(page);
  }
  reset_effectbypass_state = false;
  auditionMode = false;
  getScenes = false;
  effectCycle = true;
  Axe.refresh();
  ini_effect();
  effectTopscreens();
  
  debugln(); debug(" -> auditionmode set to: ");debug(auditionMode);
  debugln(); debug(" -> getScenes set to: "); debug(getScenes);
  debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
}

/*==================   OR  ========================*/
void taptempoPage_selection() 
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);  
  debugln(); debugln(); debugln(" * function taptempoPage_selection started on switchSelect.h");   

 
 if (auditionMode != true)
 {
  if (tapSwitch == false) 
  {
    tempoflash_bar == false;
    Axe.sendTap();
    tapSwitch = true;
    tapTempo_selectionScreen();
  }
  else
  {
    Axe.sendTap();
    tapSwitch = false;
    CS14L; tft.fillScreen(tapTempo_screen_fillscreen); CS14H;    // cosmetics for tapscreen.
    tapTempo_screen();
    tempoflash_bar == true;
  }
    }
      if (auditionMode == true)
    {
  if (tempoflash_bar == false)
    {
    tempoflash_bar = true;
    }
      else
      {
      tempoflash_bar = false;
      }
  tempoflash.deleteSprite();
  tapTempo_flash_selection_screen();
  }
}


/*==================   OR  ========================*/

void tunerPage_selection()
{
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); 
  debugln(); debugln(); debug(" * function tunerPage_selection started on switchSelect.h");
  debugln(); debug(" -> TUNER started");

  if (tunerScreen8 == true)
  {
    tuner_startScreens();
  }
  Axe.toggleTuner();
}

/*=======================================================================================================================================*/
/*   Build-up SCENE selection Screen  
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void sceneSelection()
{
  //rebuild all scene TFT to default
    debugln(); debugln(); debug(" * function sceneSelection() started on switchSelect.h");
      
      CS1L, CS2L, CS3L, CS4L,CS6L, CS7L, CS8L, CS9L;
      sceneStyle0();
      CS1H, CS2H, CS3H, CS4H,CS6H, CS7H, CS8H, CS9H;

      printSceneNumbers();
  
      switch (HOLDSWITCH) 
      {
      case SWITCH1: CS = CS1; sceneNumber = 1; break;
      case SWITCH2: CS = CS2; sceneNumber = 2; break;
      case SWITCH3: CS = CS3; sceneNumber = 3; break;
      case SWITCH4: CS = CS4; sceneNumber = 4; break;
      case SWITCH6: CS = CS6; sceneNumber = 5; break;
      case SWITCH7: CS = CS7; sceneNumber = 6; break;
      case SWITCH8: CS = CS8; sceneNumber = 7; break;
      case SWITCH9: CS = CS9; sceneNumber = 8; break;
      }
      
   strcpy(page, "scene");
   effectCycle = true;
   Axe.fetchEffects(true);
   setupHOLDSWITCH();
   Axe.refresh();

 
  Axe.sendSceneChange(sceneNumber);
  debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1); debug(" | Buttonpin = "); debug(SWITCH);
  debugln(); debug(" -> Screenpin = "); debug(CS);
  debugln(); debug(" -> Active sceneNumber = "); debug(sceneNumber);

  digitalWrite (CS, LOW);
  activesceneStyle1();
  tft.println(sceneNumber);
  scene_ACTIVEbezel();
  digitalWrite (CS, HIGH);
}

/*=======================================================================================================================================*/
/*   Build-up PRESET selection Screens  
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void auditionmodeEnd_Selection()
  {
    debugln(); debugln(); debug(" * function auditionmodeEnd_Selection started on switchSelect.h");
    CS14L;tft.fillScreen(tapTempo_screen_fillscreen); CS14H;    // cosmetics for tapscreen.
    Axe.refresh();
    sceneTopscreens();
    scenepageRebuild();
    getScenes = true;
    effectCycle = true;
    debugln(); debug(" -> getScenes set to: "); debug(getScenes);
    debugln(); debug(" -> effectcycle set to:"); debug(effectCycle);
    CurPreset = (active_Preset);
    ini_scenes();            
    debugln(); debug(" Auditionmode OFF CurPreset = "); debug(CurPreset);            
    debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
  }


void presetSelection()
{
      debugln(); debugln(); debug(" * function presetSelection started on switchSelect.h");
      if (auditionMode == true)
          {
          presetRange();  
          CurPreset = (PresetNumb + selectedSwitch);
          if (CurPreset > 511) 
            {
              CurPreset = 0;
              PresetNumb = 0;
            debugln(); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
            debugln(); debug(" While Auditionmode ON PresetNumb = "); debug(PresetNumb);
            presetRange();
            }
          debugln(); debug(" While Auditionmode ON CurPreset = "); debug(CurPreset);
          debugln(); debug(" While Auditionmode ON PresetNumb = "); debug(PresetNumb);  
          effectCycle = true;
          getScenes = true;
        /*====== Here is if you reselect the preset, it will exit audionMode =======*/
          if (CurPreset == active_Preset)
          {
            auditionMode = false;
            auditionmodeEnd_Selection();
            }
            else
            {
            Axe.sendPresetChange(CurPreset);
            debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
            debugln(); debug(" -> getScenes set to: "); debug(getScenes);        
            debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
            }
          }

 //NOT AUDITIONMODE           
            else
              {
              CurPreset = (PresetNumb + currentSwitch);
              if (CurPreset > 511)
                {
                CurPreset = (PresetNumb + selectedSwitch);
                debugln(); debug(" PresetSelection CurPreset = "); debug(CurPreset);
                debugln(); debug(" PresetSelection PresetNumb = "); debug(PresetNumb);    
                  } 
              debugln(); debug(" PresetSelection CurPreset = "); debug(CurPreset);
              debugln(); debug(" PresetSelection PresetNumb = "); debug(PresetNumb);             
              getScenes = true;
              effectCycle = true;

        
        /*====== Here is if you reselect the preset, it will exit to scenepage =======*/
          if (CurPreset == active_Preset)
          {
            scenePage_selection();
            }
            else
            {              
              Axe.sendPresetChange(CurPreset);
              scenepageRebuild();
              sceneTopscreens();
              debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
              debugln(); debug(" -> getScenes set to: "); debug(getScenes);
              debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
              }
          }
}

/*=======================================================================================================================================*/
/*   Build-up EFFECT selection Screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void effectSelection()
{
  switch (HOLDSWITCH) {
    case SWITCH1: CS = CS1; thisEffect = effect0; break;
    case SWITCH2: CS = CS2; thisEffect = effect1; break;
    case SWITCH3: CS = CS3; thisEffect = effect2; break;
    case SWITCH4: CS = CS4; thisEffect = effect3; break;
    case SWITCH5: CS = CS5; thisEffect = effect4; break;
    case SWITCH6: CS = CS6; thisEffect = effect5; break;    
    case SWITCH7: CS = CS7; thisEffect = effect6; break;
    case SWITCH8: CS = CS8; thisEffect = effect7; break;
    case SWITCH9: CS = CS9; thisEffect = effect8; break;
    case SWITCH10: CS = CS10; thisEffect = effect9; break;
    }


    debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
    AxeEffect *effect = Axe.getCurrentPreset().getEffectById(thisEffect);
    if (thisEffect > 0)
    {
    effect->toggle();
    digitalWrite (CS, LOW);
      if (effect->isBypassed()) {
          effectStyle1();     //on Screenstyle.h
          effect->printEffectName(tft);
          }
           else {
              effectStyle2(); //on Screenstyle.h
              effect->printEffectName(tft);
               }
    digitalWrite (CS, HIGH);
    }
}

/*=======================================================================================================================================*/
/*   Build-up EFFECT selection Screens 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void scene_effectSelection()
{
    switch (HOLDSWITCH) {
    case SWITCH1: CS = CS1;   thisEffect = effect0; upDown = false;  sceneNumber = 1; break;
    case SWITCH2: CS = CS2;   thisEffect = effect1; upDown = false;  sceneNumber = 2; break;
    case SWITCH3: CS = CS3;   thisEffect = effect2; upDown = false;  sceneNumber = 3; break;
    case SWITCH4: CS = CS4;   thisEffect = effect3; upDown = false;  sceneNumber = 4; break;
    case SWITCH5: CS = CS5;   thisEffect = effect4; upDown = true;   sceneNumbers = ""; break;
    case SWITCH6: CS = CS6;   thisEffect = effect5; upDown = false;  sceneNumber = 5; break;    
    case SWITCH7: CS = CS7;   thisEffect = effect6; upDown = false;  sceneNumber = 6; break;
    case SWITCH8: CS = CS8;   thisEffect = effect7; upDown = false;  sceneNumber = 7; break;
    case SWITCH9: CS = CS9;   thisEffect = effect8; upDown = false;  sceneNumber = 8; break;
    case SWITCH10: CS = CS10; thisEffect = effect9; upDown = true;   sceneNumbers = ""; break;
    }
         
    debugln(); debug(" -> Pressed Switch = "); debug(sceneNumber);
    debugln(); debug(" -> Pressed Switch button number = "); debug(HOLDSWITCH);
    AxeEffect *effect = Axe.getCurrentPreset().getEffectById(thisEffect);
    debugln(); debug(" -> Effect = "); debug(thisEffect);

       if (thisEffect != 0)
        {
        debugln(); debug(" Effect BEFORE toggle value is: "); debug(effect->isBypassed());
        effect->toggle();
        debugln(); debug(" Effect AFTER toggle value is now: "); debug(effect->isBypassed());
        
        digitalWrite (CS, LOW);
          if (effect->isBypassed()) 
          {
           if (upDown != false) // screen 5 and 10 for preset up/down
            {
              effectOnPageUpDownBypass();     
              effect->printEffectName(tft);
              sceneStyle1(); tft.println(sceneNumbers);
              }
              else
              {
              effectOnSceneBypass();     
              effect->printEffectName(tft);
              sceneStyle1(); tft.println(sceneNumber);
              }
          }          
               else  
               {
                 if (upDown != false) // screen 5 and 10 for preset up/down
                  {
                   effectOnPageUpDownActive(); 
                   effect->printEffectName(tft);
                   sceneStyle1(); tft.println(sceneNumbers);
                   }
               else
                    {
                    effectOnSceneActive(); 
                    effect->printEffectName(tft);
                    sceneStyle1(); tft.println(sceneNumber);
                    }
                }  
        digitalWrite (CS, HIGH);
        debugln(); debug(" -> END scene_effectSelection() "); 
        }
        thisEffect = 0;
}

//*=======================================================================================================================================*/
/*   +++++++     END SCREEN SELECT     +++++++++        
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void bankDown_selection()
{ 
  if (presetBank != 1)
  {
  if (strcmp(page, "preset") != 0)  // -->>  NOT on presetpage
        { 
          PresetNumb = (PresetNumb - 10);
          debugln(); debug(" presetNumb - 10 = "); debugln(PresetNumb); 
          if (PresetNumb < 0) 
          {
            PresetNumb = (PresetNumb + 520);  // 520 is first passible number in the next bank, but doesnt exist
            if (PresetNumb > 511) {PresetNumb = (PresetNumb - 10);}  // 511 is last passible number}
            } 
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          bankDown_LCD_text();
          getScenes = true;
          effectCycle = true;
          scenepageRebuild();
          Axe.sendPresetChange(CurPreset);
          
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch - 10);  
        }
          else // -->> ON presetpage
        {  
         { 
           PresetNumb = (PresetNumb - 10);
          debugln(); debug(" presetNumb - 10 = "); debugln(PresetNumb); 
          if (PresetNumb < 0) 
          {
          PresetNumb = (PresetNumb + 520);  // 520 is first passible number in the next bank, but doesnt exist
          if (PresetNumb > 511) {PresetNumb = (PresetNumb - 10);}  // 511 is last passible number}
           } 
           if (auditionMode == true)
          {
          CurPreset = PresetNumb;          
          debugln(); debug(" auditionmode preset bankDown CurPreset = "); debug(CurPreset);   
          auditionmode_LCD_text();
          }
          else
            {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankDown CurPreset = "); debug(CurPreset);          
          bankDown_LCD_text();
          debugln(); debugln(" Switch-6");
          presetRange();
            }
          ini_preset();
      
        }
     }    
   }
    delay(200); 
}  
/*==================   OR  ========================*/   //  +10 

void bankUp_selection()
{
    if (presetBank != 1)
        {        
         if (strcmp(page, "preset") != 0) // NOT on presetpage
          {
            PresetNumb = (PresetNumb + 10);  
          if (PresetNumb >= 520) 
          {
            PresetNumb = (0 + (PresetNumb - 520)); // 520 is first passible number in the next bank, but doesnt exist
            } 
            else if (PresetNumb > 511) 
          {
            PresetNumb = (0 + (PresetNumb - 510)); // 520 is first passible number in the next bank, but doesnt exist
            }      
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          bankUp_LCD_text();
          getScenes = true;
          effectCycle = true;
          scenepageRebuild();
          Axe.sendPresetChange(CurPreset);
          
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          debugln(); debug(" -> effectcycle set to: ");  debug(effectCycle);
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 10);
          }
          else  // ON presetpage
          {
            PresetNumb = (PresetNumb + 10);  
          if (PresetNumb >= 520) 
          {
            PresetNumb = (0 + (PresetNumb - 520)); // 520 is first passible number in the next bank, but doesnt exist
            } 
            else if (PresetNumb > 510) 
          {
            PresetNumb = (0 + (PresetNumb - 510)); // 520 is first passible number in the next bank, but doesnt exist
            }            
          if (auditionMode == true)
          {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset);  
          auditionmode_LCD_text();
            }
          else
          {
          CurPreset = PresetNumb;
          debugln(); debug(" preset bankUp CurPreset = "); debug(CurPreset); 
          bankUp_LCD_text();
          debugln(); debug(" Switch-12 ");
          presetRange();
            }
          ini_preset();

          }
    }
          delay(200); 
}

/*==================   OR  ========================*/   //  -1
void presetDown_selection()
{
          getScenes = true;
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
          scene_LCD_text();
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
          scenepageRebuild();
          Axe.sendPresetDecrement();

}

/*==================   OR  ========================*/   //  +1
void presetUp_selection()
{
          getScenes = true;
          debugln(); debug(" -> getScenes set to: "); debug(getScenes);
          effectCycle = true;
          auditionMode = false;
          debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);
          scene_LCD_text();
          debugln(); debug(" -> Pressed Switch = "); debug(currentSwitch + 1);
          scenepageRebuild();
          Axe.sendPresetIncrement();
      
}

void auditionmodePage_selection()
{
  if (auditionMode == false)
          {
            auditionMode = true;
            debugln(); debug (" -> auditionmode set to: "); debug(auditionMode);
            auditionmode_LCD_text();
            effectCycle = true;
            debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);            
            auditionMode_ON_screen();
            auditionmodeTopscreens();
          }
                    else
          {
           auditionMode = false;
           auditionmodeEnd_Selection();
          }
}

void auditionmodePage_tuner_OFF_selection()
          {
            debugln(); debug (" -> auditionmode set to: ");debug(auditionMode);
            auditionmodeTopscreens();
            ini_preset();
            auditionmode_LCD_text();
            effectCycle = true;
            debugln(); debug(" -> effectcycle set to: "); debug(effectCycle);            
            auditionMode_ON_screen();
          }

/*=======================================================================================================================================*/
/*Axelman8*/
