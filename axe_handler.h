#pragma once


/*                             ====================
                                       NOTE
  =======================================================================================
  Scenes are initiated on this page, as ini_scenes is populated from this page.
  so are the presets initiated on this page and ini_preset is populated from this page.
  ======================================================================================= */


/*===========================================   -  Include library's  -  ================================================*/
#include <Timer.h>
#include <AxeFxControl.h>


#include "Screenstyle.h"
#include "preset_range.h"
/*=======================================================================================================================*/



/*=======================================================================================================================================*/
//       All scenes initialize
/*---------------------------------------------------------------------------------------------------------------------------------------*/

//Struct to hold information about each scene
struct SceneInfo 
{
  SceneNumber number = -1;
  const char *name;
};

//A list of all of the scenes for this preset
SceneInfo scenes[NUM_SCENES];

//Reset the scene list for the new preset
void onPresetChanging(const PresetNumber number) 
{
  for (byte i = 0; i < NUM_SCENES; i++) {
    scenes[i].number = -1;
  }
}

  void setupHOLDSWITCH()
  {
    debug("\n"); debug("\n"); debug(" * function setupHOLDSWITCH() started on axe_handler.h");
    switch (sceneNumber)
    {
     case 1: previousHOLDSWITCH = SWITCH1; break; 
     case 2: previousHOLDSWITCH = SWITCH2; break; 
     case 3: previousHOLDSWITCH = SWITCH3; break; 
     case 4: previousHOLDSWITCH = SWITCH4; break; 
     case 5: previousHOLDSWITCH = SWITCH6; break; 
     case 6: previousHOLDSWITCH = SWITCH7; break; 
     case 7: previousHOLDSWITCH = SWITCH8; break; 
     case 8: previousHOLDSWITCH = SWITCH9; break;  
      }
     debug("\n"); debug(" previousHOLDSWITCH is set to: "); debug(previousHOLDSWITCH);
    }


/*=======================================================================================================================================*/
//        This is for the TAP flashlight
/*---------------------------------------------------------------------------------------------------------------------------------------*/


void turnOffFlashingLed()
{  
  {tapTempo_flash_OFF();}  //flashing screen 14
}

void flashLed(int flashDelay)
{ 
  {tapTempo_flash_ON();}   //flashing screen 14
  timer.after(flashDelay, turnOffFlashingLed);
}

void onTapTempo()
{
  switch (tempo_Counter)
  {
    case 0: tempo_Counter = 1; break;
    case 1: tempo_Counter = 2; break;  
    case 2: tempo_Counter = 3; break;
    case 3: tempo_Counter = 4; break;
    case 4: tempo_Counter = 1; break;
  }
    tapTempo_sprite();
    flashLed(TAP_TEMPO_LED_DURATION);
}



/*=======================================================================================================================================*/
//        Display the current tempo at the TFT
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void onSystemChange() 
{
  debugln(); debugln(); debug(" * function onSystemChange started on axe_handler.h");
    Axe.fetchEffects(true);
  
   // here we set the taptempo on the screen
   if (auditionMode != true)  //On auditionmode we dont need the tapTempo_screen,. we are allready using a diffrent screen
   {
    CS14L;
    tft.drawRect(0, 80, 160, 128, TFT_BLACK);
    tft.fillRect(0, 80, 160, 128, TFT_BLACK);
    tft.setTextColor(tapTempo_screen_txt2_color, tapTempo_screen_txt2_BGcolor);
    tft.setTextSize(4); tft.setCursor(53, 90);
    tft.println(Axe.getTempo());  
    CS14H;
    }
}



//*=======================================================================================================================================*/
//       Set active presetname in screen 13
/* ---------------------------------------------------------------------------------------------------------------------------------------*/
void presetName_setting(AxePreset preset)   //Set active presetname in screen 13
{
  debugln();  debugln();  debug(" * function presetName_setting started on axe_handler.h");


  PresetNumb = CurPreset;  //active_Preset;
  strcpy(active_PresetName, (preset.getPresetName()));
  PresetName_helper();

  tft.setTextWrap(false); // we dont need this anymore

  if (preset.getPresetNumber() < 10)
  { Cursor = 65;  }
  else if ((preset.getPresetNumber() >= 10) && (preset.getPresetNumber() < 100))
  { Cursor = 50;  }
  else if ((preset.getPresetNumber() >= 100) && (preset.getPresetNumber() < 1000))
  { Cursor = 29;  }


  if (P13 == 0)
  {
    //Init screen 13
    CS13L;
    screen13Style();
    tft.println(preset.getPresetNumber());
    CS13H;

    if (strcmp(page, "scene") == 0) // On scenepage
    {
    debugln(); debug(" variable CurPreset = "); debug(CurPreset); 
    previousPreset = (CurPreset - 1);
    debugln(); debug(" variable CurPreset - 1 =  "); debug(CurPreset - 1); 
    if (CurPreset - 1 < 0){previousPreset = 511;}
    nextPreset = (CurPreset + 1);
    debugln(); debug(" variable CurPreset + 1 =  "); debug(CurPreset + 1);
    if (CurPreset + 1 > 511){nextPreset = 0;}
    debugln(); debug(" variable active_Preset = "); debug(active_Preset); 
    debugln(); debug(" variable previousPreset = "); debug(previousPreset); 
    debugln(); debug(" variable nextPreset = "); debug(nextPreset);
    }

    CS13L;
    //row 1
    if (P11 > 10)
    {  tft.setCursor(1, 60); }
    else
    {  tft.setCursor((80 - ((P11 * 9) - 6)), 60); }
       tft.setTextSize(3);
       tft.setTextColor(screen13Style_txt2_color);
       tft.println(PRE11);

    //row 2

    if (P12 > 10)
    { tft.setCursor(1, 90); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 90); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE12);
    CS13H;
  }
  else {
    //Init screen 13
    CS13L;
    screen13Style();
    tft.println(preset.getPresetNumber());
    CS13H;
 
    if (strcmp(page, "scene") == 0) // On scenepage
    {
    debugln(); debug(" variable CurPreset = "); debug(CurPreset);   
    previousPreset = (CurPreset - 1);
    debugln(); debug(" variable CurPreset - 1 =  "); debug(CurPreset - 1);
    if (CurPreset -1 < 0){previousPreset = 511;}
    nextPreset = (CurPreset + 1);
    debugln(); debug(" variable CurPreset + 1 =  "); debug(CurPreset + 1);
    if (CurPreset + 1 > 511){nextPreset = 0;}
    debugln(); debug(" variable active_Preset = "); debug(active_Preset); 
    debugln(); debug(" variable previousPreset = "); debug(previousPreset); 
    debugln(); debug(" variable nextPreset = "); debug(nextPreset);
    }

    CS13L;
    //row 1
    if (P11 > 10)
    {  tft.setCursor(1, 49); }
    else
    { tft.setCursor((80 - ((P11 * 9) - 6)), 49);    }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE11);

    //row 2

    if (P12 > 10)
    { tft.setCursor(1, 78); }
    else
    { tft.setCursor((80 - ((P12 * 9) - 6)), 78); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE12);

    //row 3
    if (P13 > 10)
    { tft.setCursor(1, 107); }    
    else
    { tft.setCursor((80 - ((P13 * 9) - 6)), 107); }
      tft.setTextSize(3);
      tft.setTextColor(screen13Style_txt2_color);
      tft.println(PRE13);
  }
  CS13H;
  presetUpDownscreens();
}


/*=======================================================================================================================================*/
//       IS LOOPER OR WAH AVAILABLE?
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void wah_looper()
{
  if (strcmp(page,"AMP_effect") !=0)
  {
    if (wahActive != true) {
      debugln(); debug(" -> WAH not active");
      CS11L; NOWAH_screen(); CS11H; }
    else {
      debugln(); debug(" -> WAH is active");
      CS11L; YESWAH_screen(); CS11H; }

    if (looperActive != true) {
      debugln(); debug(" -> LOOPER not active");
      CS12L; NOLOOPER_screen(); CS12H; }
    else {
      debugln(); debug(" -> Looper is active");
      CS12L; YESLOOPER_screen(); CS12H;}


      // restoring looper and wah pointer to false.  The code from the effect function will change it to true if so...
      looperActive = false; /*NOLOOPER_screen();*/
      debugln(""); debug(" -> starting effects lookup | looperActive is reset to:  false");
      wahActive = false; /*NOWAH_screen();*/
      debugln(""); debug(" -> starting effects lookup | wahActive is reset to:  false");
  }
}

/*=======================================================================================================================================*/
//       INI SCENES build-up SCREENS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void ini_scenes()  //setup scene screens
{
  debugln();  debugln();  debug(" * function ini_scenes started on axe_handler.h");  
  
     debug("\n"); debug(" -> Active scenenumber = "); debug(sceneNumber);
     scene_LCD_text();
    
    /* =============== printing scenes on the screens ==============*/

    AxePreset preset = (Axe.getCurrentPreset());

    if (getScenes == true)
    {
      if (auditionMode != true)  // ON auditionmode we dont need scenes, only the wah and looper function at the end 
      {
      CS1L, CS2L, CS3L, CS4L,
      CS6L, CS7L, CS8L, CS9L;
      sceneStyle0();
      CS1H, CS2H, CS3H, CS4H,
      CS6H, CS7H, CS8H, CS9H;

      CS1L;
      if (sceneNumber == 1)
      {scene_ACTIVEbezel();}
      
      if (L11 >= 9)
      { sceneStyle2(); tft.println(SCE11); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L11 * 9) - 5), 6); tft.println(SCE11); }
      tft.setCursor(80 - ((L12 * 9) - 5), 36);
      tft.println(SCE12);
      tft.setCursor(80 - ((L13 * 9) - 5), 66);
      tft.println(SCE13);
      CS1H;



      //2
      CS2L;
      if (sceneNumber == 2)
      {scene_ACTIVEbezel();}
     
      if (L21 >= 9)
      { sceneStyle2(); tft.println(SCE21); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L21 * 9) - 5), 6); tft.println(SCE21); }
      tft.setCursor(80 - ((L22 * 9) - 5), 36);
      tft.println(SCE22);
      tft.setCursor(80 - ((L23 * 9) - 5), 66);
      tft.println(SCE23);
      CS2H;


      //3
      CS3L;
      if (sceneNumber == 3)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE31); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L31 * 9) - 5), 6); tft.println(SCE31); }

      tft.setCursor(80 - ((L32 * 9) - 5), 36);
      tft.println(SCE32);
      tft.setCursor(80 - ((L33 * 9) - 5), 66);
      tft.println(SCE33);
      CS3H;


      //4
      CS4L;
      if (sceneNumber == 4)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE41); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L41 * 9) - 5), 6); tft.println(SCE41); }

      tft.setCursor(80 - ((L42 * 9) - 5), 36);
      tft.println(SCE42);
      tft.setCursor(80 - ((L43 * 9) - 5), 66);
      tft.println(SCE43);
      CS4H;


      //5
      CS6L;
      if (sceneNumber == 5)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE51); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L51 * 9) - 5), 6); tft.println(SCE51); }

      tft.setCursor(80 - ((L52 * 9) - 5), 36);
      tft.println(SCE52);
      tft.setCursor(80 - ((L53 * 9) - 5), 66);
      tft.println(SCE53);
      CS6H;


      //6
      CS7L;
      if (sceneNumber == 6)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE61);}
      else
      { sceneStyle3(); tft.setCursor(80 - ((L61 * 9) - 5), 6); tft.println(SCE61); }

      tft.setCursor(80 - ((L62 * 9) - 5), 36);
      tft.println(SCE62);
      tft.setCursor(80 - ((L63 * 9) - 5), 66);
      tft.println(SCE63);
      CS7H;


      //7
      CS8L;
      if (sceneNumber == 7)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE71); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L71 * 9) - 5), 6); tft.println(SCE71); }

      tft.setCursor(80 - ((L72 * 9) - 5), 36);
      tft.println(SCE72);
      tft.setCursor(80 - ((L73 * 9) - 5), 66);
      tft.println(SCE73);
      CS8H;


      //8
      CS9L;
      if (sceneNumber == 8)
      {scene_ACTIVEbezel();}
      
      if (L31 >= 9)
      { sceneStyle2(); tft.println(SCE81); }
      else
      { sceneStyle3(); tft.setCursor(80 - ((L81 * 9) - 5), 6); tft.println(SCE81); }

      tft.setCursor(80 - ((L82 * 9) - 5), 36);
      tft.println(SCE82);
      tft.setCursor(80 - ((L83 * 9) - 5), 66);
      tft.println(SCE83);
      CS9H;
      }
    }
      presetName_setting(preset);  //Fill screen 13 with active preset name and number
      wah_looper();
      if (auditionMode != true)
      {tapTempo_screen();}  //On auditionmode we dont need the tapTempo_screen,. we are allready using a diffrent screen
      
      //restoring settings to false
      getScenes = false;  // scenes are allready printed
      debugln(); debug(" -> getScenes set to: "); debug(getScenes);
      debugln(); debug(" -> End scene page buildup");

}

/*=======================================================================================================================================*/
//       RESET EFFECTS VARIABLES  (set to zero)
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void effectvariable_reset()
{
 effect0 = 0; effect1 = 0; effect2= 0;  effect3= 0;  effect4= 0;  effect5= 0;  effect6= 0;  effect7= 0;  effect8= 0;  effect9= 0; 
 effect10= 0; effect11= 0; effect12= 0; effect13= 0; effect14= 0; effect15= 0; effect16= 0; effect17= 0; effect18= 0; effect19 = 0; 
  debug("\n"); debug(" effectvariable_reset() is started on axe_handler.h  and restored effect to ZERO");
  
  setupHOLDSWITCH();
}


/*=======================================================================================================================================*/
//       Fetch all scenes 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void onSceneName(const SceneNumber number, const char* name, const byte length)
{

  if (getScenes == 1)
  {
    /*=============================================================
       ======  ONLY operate if needed.  LIKE getScenes = true  ====*/

    debugln(); debug(" Scene "); debug(number); debug(": "); debug(name);


    /*======================================
      =       SCENE names And SCREENS      =
      =             SCENE names            =
      ======================================*/
    switch (number) {

      case 1: SceneName_helper(name); L11 = str1.length(); L12 = str2.length(); L13 = str3.length(); str1.toCharArray(SCE11, L11 + 1); str2.toCharArray(SCE12, L12 + 1); str3.toCharArray(SCE13, L13 + 1); break;
      case 2: SceneName_helper(name); L21 = str1.length(); L22 = str2.length(); L23 = str3.length(); str1.toCharArray(SCE21, L21 + 1); str2.toCharArray(SCE22, L22 + 1); str3.toCharArray(SCE23, L23 + 1); break;
      case 3: SceneName_helper(name); L31 = str1.length(); L32 = str2.length(); L33 = str3.length(); str1.toCharArray(SCE31, L31 + 1); str2.toCharArray(SCE32, L32 + 1); str3.toCharArray(SCE33, L33 + 1); break;
      case 4: SceneName_helper(name); L41 = str1.length(); L42 = str2.length(); L43 = str3.length(); str1.toCharArray(SCE41, L41 + 1); str2.toCharArray(SCE42, L42 + 1); str3.toCharArray(SCE43, L43 + 1); break;
      case 5: SceneName_helper(name); L51 = str1.length(); L52 = str2.length(); L53 = str3.length(); str1.toCharArray(SCE51, L51 + 1); str2.toCharArray(SCE52, L52 + 1); str3.toCharArray(SCE53, L53 + 1); break;
      case 6: SceneName_helper(name); L61 = str1.length(); L62 = str2.length(); L63 = str3.length(); str1.toCharArray(SCE61, L61 + 1); str2.toCharArray(SCE62, L62 + 1); str3.toCharArray(SCE63, L63 + 1); break;
      case 7: SceneName_helper(name); L71 = str1.length(); L72 = str2.length(); L73 = str3.length(); str1.toCharArray(SCE71, L71 + 1); str2.toCharArray(SCE72, L72 + 1); str3.toCharArray(SCE73, L73 + 1); break;
      case 8: SceneName_helper(name); L81 = str1.length(); L82 = str2.length(); L83 = str3.length(); str1.toCharArray(SCE81, L81 + 1); str2.toCharArray(SCE82, L82 + 1); str3.toCharArray(SCE83, L83 + 1); break;
    }

    /*===========================================
      =======   SCENE names from Axe-Fx    ======
      ===========================================*/

    //  //Record current scene in the list
    scenes[number - 1].number = number;
    scenes[number - 1].name = name;


    //----------This is the active scene number---------------

    //Request the first scene that we don't have yet.
    // Only request one at a time to avoid filling up RX buffer
    for (byte i = 0; i < NUM_SCENES; i++) {
      if (scenes[i].number == -1) {
        Axe.requestSceneName(i + 1);
        break;
      }
      if (i == 7) {

        debugln(); debugln();   debug(" * function ini_scenes called from function onscenename() on axe_handler.h");
        ini_scenes();  // build the scene page on the screens
        debugln(); debugln();   debug(" * function onscenename succesfully loaded on axe_handler.h");
      }
    }
  }
}


/*=======================================================================================================================================*/
//       EFFECT FILTER and LOOPER SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

bool onEffectFilter(const PresetNumber number, AxeEffect effect) {


  if  (strcmp(page, "AMP_effect") == 0) 
  {
    return effect.isCab() || effect.isDistort();
  }
  else
  {
    return  effect.isDelay() || effect.isPhaser() || effect.isMulticomp() || effect.isChorus() || effect.isDrive() || effect.isPitch() || 
            effect.isReverb() || effect.isPlex() || effect.isCompressor() || effect.isFlanger() || effect.isMultitap() || effect.isMegatap() ||
            effect.isMulticomp() || effect.isLooper() ||  effect.isWah() || effect.isGrapheqEQ() || effect.isParaEQ() /*|| effect.isDistort()*/;
  }
 }


/*=======================================================================================================================================*/
//       SHOW EFFECTS ON SCREEN
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void onEffectsReceived(PresetNumber number, AxePreset preset)
{
  debugln();  debugln();  debug(" * function onEffectsReceived started on axe_handler.h");

  const size_t tagSz = 10;
  char tag[tagSz];
  const size_t sz = 25;
  char buf[sz];


  // The effect is started by the callback functions... I only need it to run once to keep the programspeed going
  if (effectCycle == true)
  {
    effectCycle = false;
    debug("\n"); debug(" -> effectcycle is true and now set to:  false");
    snprintf(buf, sz, "Effects[%d]: ", preset.getEffectCount());


    for (effectindex = 0; effectindex < preset.getEffectCount(); effectindex++) {
      AxeEffect effect = preset.getEffectAt(effectindex);
      effect.copyEffectTag(tag, tagSz);

      char engaged = effect.isBypassed() ? ' ' : 'X';
      snprintf(buf, sz, "%s(ch:%c) [%c]", tag, effect.getChannelChar(), engaged);
      debug("\n"); debug(buf);

      effect.getEffectId();
      debug("\n"); debug(" Effect: "); debug(tag); debug(" | effectId = "); debug(effect.getEffectId()); debug(" | Channel: "); debug(effect.getChannelChar());
      EffectId effectId = effectindex;
      effect.isBypassed();

    
     

//==============================================================================================================
//================    IF ENABLED, RESET EFFECT BYPASS STATE WHEN GOING BACK TO SCENEPAGE    ====================
//---------->>>>>>>>>>>>>>>>>>>>>>>    @KARLMINOX ----->>>>>>  THIS IS YOUR SOLUTION    <<<<<<<<<<<<<<----------
//================      EDIT:  THE HOLD FUNCTION ALSO USES THIS CODE TO RESTORE EFFECTS     ====================
//==============================================================================================================
       
        if (reset_effectbypass_state == true)  //setting available in SD_ini.h
        {
           switch (effectindex) 
            {
              
        case 0: effectbypass = effect0_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 
                
        case 1: effectbypass = effect1_bypass;  
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break;  

        case 2: effectbypass = effect2_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 

        case 3: effectbypass = effect3_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 
 
        case 4: effectbypass = effect4_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 

        case 5: effectbypass = effect5_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 

        case 6: effectbypass = effect6_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break;     

        case 7: effectbypass = effect7_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 

        case 8: effectbypass = effect8_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 

        case 9: effectbypass = effect9_bypass; 
                debug("\n"); debug(" Effect bypassed value?: "); debug(effect.isBypassed());
                debug("\n"); debug(" Origional Effect_bypass value?: "); debug(effectbypass);
                
                if (effect.isBypassed() != effectbypass) 
                {effect.toggle(); 
                
                debug("\n"); debug(" Effect is toggled and is now set to: "); debug(effect.isBypassed());}
                debug("\n");
                break; 
            }

          }
/*=======================================================================================================================================*/
//  SHOW EFFECTS PER SCENE IN SCENE TFT SCREEN 
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


      //---------------------------------------------------------------------
      //  Load effects to each scene is reselected  (sceneReselected == false)
      //---------------------------------------------------------------------

    if (strcmp(page,"scene") == 0) // Only if page is scene,  than get the effects to print on screen.
      {
        tft.setTextWrap(0);
        switch (effectindex)
        {
    case 0:
      effect0 = (effect.getEffectId());
      CS1L;
      if (effect.isBypassed()) 
      {effect0_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect0_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS1H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect0_bypass);
      debug("\n");
      break;
 
    case 1:
      effect1 = (effect.getEffectId());
      CS2L;
      if (effect.isBypassed()) 
      {effect1_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect1_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS2H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect1_bypass);
      debug("\n");
      break;

    case 2:
      effect2 = (effect.getEffectId());
      CS3L;
      if (effect.isBypassed()) 
      {effect2_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect2_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS3H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect2_bypass);
      debug("\n");
      break;


    case 3:
      effect3 = (effect.getEffectId());
      CS4L;
      if (effect.isBypassed()) 
      {effect3_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect3_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS4H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect3_bypass);
      debug("\n");
      break;


    case 4:
      effect4 = (effect.getEffectId());
      CS5L;
      if (effect.isBypassed()) 
      {effect4_bypass = true; effectOnPageUpDownBypass(); effect.printEffectName(tft);}
      else 
      {effect4_bypass = false; effectOnPageUpDownActive(); effect.printEffectName(tft);}
      CS5H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect4_bypass);
      debug("\n");
      break;

    case 5:
      effect5 = (effect.getEffectId());
      CS6L;
      if (effect.isBypassed()) 
      {effect5_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect5_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS6H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect5_bypass);
      debug("\n");
      break;

    case 6:
      effect6 = (effect.getEffectId());
      CS7L;
      if (effect.isBypassed()) 
      {effect6_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect6_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS7H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect6_bypass);
      debug("\n");
      break;

    case 7:
      effect7 = (effect.getEffectId());
      CS8L;
      if (effect.isBypassed()) 
      {effect7_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect7_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS8H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect7_bypass);
      debug("\n");
      break;

    case 8:
      effect8 = (effect.getEffectId());
      CS9L;
      if (effect.isBypassed()) 
      {effect8_bypass = true; effectOnSceneBypass(); effect.printEffectName(tft); }
      else 
      {effect8_bypass = false; effectOnSceneActive(); effect.printEffectName(tft); }
      CS9H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect8_bypass);
      debug("\n");
      break;

    case 9:
      effect9 = (effect.getEffectId());
      CS10L;
      if (effect.isBypassed()) 
      {effect9_bypass = true; effectOnPageUpDownBypass(); effect.printEffectName(tft); }
      else 
      {effect9_bypass = false; effectOnPageUpDownActive(); effect.printEffectName(tft); }
      CS10H;
      debug("\n"); debug(" Effect status: it is set to: "); debug(effect9_bypass);
      debug("\n");
      break;
    
        }
      printSceneNumbers();
     }




/*=======================================================================================================================================*/
//  EFFECTPAGE BUILDUP
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


      if (strcmp(page, "effect") == 0)  //Only if page is effect,  than get the effects to print on screen.
      {
        tft.setTextWrap(0);
        switch (effectindex)
        {
      case 0:
            effect0 = (effect.getEffectId());
            CS1L;
            if (effect.isBypassed()) 
            {effect0_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect0_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS1H;
            break;
       
       case 1:
            effect1 = (effect.getEffectId());
            CS2L;
            if (effect.isBypassed()) 
            {effect1_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect1_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS2H;
            break;

          case 2:
            effect2 = (effect.getEffectId());
            CS3L;
            if (effect.isBypassed()) 
            {effect2_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect2_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS3H;
            break;


          case 3:
            effect3 = (effect.getEffectId());
            CS4L;
            if (effect.isBypassed()) 
            {effect3_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect3_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS4H;
            break;


          case 4:
            effect4 = (effect.getEffectId());
            CS5L;
            if (effect.isBypassed()) 
            {effect4_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect4_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS5H;
            break;

          case 5:
            effect5 = (effect.getEffectId());
            CS6L;
            if (effect.isBypassed()) 
            {effect5_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect5_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS6H;
            break;

          case 6:
            effect6 = (effect.getEffectId());
            CS7L;
            if (effect.isBypassed()) 
            {effect6_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect6_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS7H;
            break;

          case 7:
            effect7 = (effect.getEffectId());
            CS8L;
            if (effect.isBypassed()) 
            {effect7_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect7_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS8H;
            break;

          case 8:
            effect8 = (effect.getEffectId());
            CS9L;
            if (effect.isBypassed()) 
            {effect8_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect8_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS9H;
            break;

          case 9:
            effect9 = (effect.getEffectId());
            CS10L;
            if (effect.isBypassed()) 
            {effect9_bypass = true; effectStyle1();effect.printEffectName(tft);}
            else 
            {effect9_bypass = false; effectStyle2();effect.printEffectName(tft);}
            CS10H;
            break;
        }
      }

           /*                                  WAH or LOOPER AVAILABLE?
===============================================================================================================
               Setting the parameters for screen 11 and 12:  is Wah or Looper available?
               if looper = true:  here we check if looper is available and print in screen 12 (id = 166)
               if wah = true:     here we check if wah is available and print in screen 11 (id = 94)
===============================================================================================================*/

        switch (effectindex)
        {
          case 1:
            effect1 = (effect.getEffectId());
            if (effect1 == 94)
            {debugln();debug(" 01: YES tag is wah");wahActive = true;}
            else if (effect1 == 166)
            { debugln(); debug(" 01: YES tag is looper"); looperActive = true;}
            break;

          case 2:
            effect2 = (effect.getEffectId());
            if (effect2 == 94)
            {debugln(); debug(" 02: YES tag is wah");wahActive = true;}
            else if (effect2 == 166)
            {debugln(); debug(" 02: YES tag is looper");looperActive = true;}
            break;

          case 3:
            effect3 = (effect.getEffectId());
            if (effect3 == 94)
            {debugln(); debug(" 03: YES tag is wah");wahActive = true;}
            else if (effect3 == 166)
            {debugln(); debug(" 03: YES tag is looper");looperActive = true;}
            break;


          case 4:
            effect4 = (effect.getEffectId());
            if (effect4 == 94)
            {debugln(); debug(" 04: YES tag is wah"); wahActive = true;}
            else if (effect4 == 166)
            {debugln(); debug(" 04: YES tag is looper");looperActive = true;}
            break;

          case 5:
            effect5 = (effect.getEffectId());
            if (effect5 == 94)
            {debugln(); debug(" 05: YES tag is wah");wahActive = true;}
            else if (effect5 == 166)
            {debugln(); debug(" 05: YES tag is looper");looperActive = true;}
            break;

          case 6:
            effect6 = (effect.getEffectId());
            if (effect6 == 94)
            {debugln(); debug(" 06: YES tag is wah");wahActive = true;}
            else if (effect6 == 166)
            {debugln(); debug(" 06: YES tag is looper");looperActive = true;}
            break;

          case 7:
            effect7 = (effect.getEffectId());
            if (effect7 == 94)
            {debugln(); debug(" 07: YES tag is wah");wahActive = true;}
            else if (effect7 == 166)
            {debugln(); debug(" 07: YES tag is looper");looperActive = true;}
            break;

          case 8:
            effect8 = (effect.getEffectId());
            if (effect8 == 94)
            {debugln(); debug(" 08: YES tag is wah");wahActive = true;}
            else if (effect8 == 166)
            {debugln(); debug(" 08: YES tag is looper");looperActive = true;}
            break;

          case 9:
            effect9 = (effect.getEffectId());
            if (effect9 == 94)
            {debugln(); debug(" 09: YES tag is wah");wahActive = true;}
            else if (effect9 == 166)
            {debugln(); debug(" 09: YES tag is looper");looperActive = true;}
            break;

          case 10:
            effect10 = (effect.getEffectId());
            if (effect10 == 94)
            {debugln(); debug(" 10: YES tag is wah");wahActive = true;}
            else if (effect10 == 166)
            {debugln(); debug(" 10: YES tag is looper");looperActive = true;}
            break;

          case 11:
            effect11 = (effect.getEffectId());
            if (effect11 == 94)
            {debugln(); debug(" 11: YES tag is wah");wahActive = true;}
            else if (effect11 == 166)
            {debugln(); debug(" 11: YES tag is looper");looperActive = true;}
            break;

          case 12:
            effect12 = (effect.getEffectId());
            if (effect12 == 94)
            {debugln(); debug(" 12: YES tag is wah");wahActive = true;}
            else if (effect12 == 166)
            {debugln(); debug(" 12: YES tag is looper");looperActive = true;}
            break;

          case 13:
            effect13 = (effect.getEffectId());
            if (effect13 == 94)
            {debugln(); debug(" 13: YES tag is wah");wahActive = true;}
            else if (effect13 == 166)
            {debugln(); debug(" 13: YES tag is looper");looperActive = true;}
            break;

          case 14:
            effect14 = (effect.getEffectId());
            if (effect14 == 94)
            {debugln(); debug(" 14: YES tag is wah");wahActive = true;}
            else if (effect14 == 166)
            {debugln(); debug(" 14: YES tag is looper");looperActive = true;}
            break;

          case 15:
            effect15 = (effect.getEffectId());
            if (effect15 == 94)
            {debugln(); debug(" 15: YES tag is wah");wahActive = true;}
            else if (effect15 == 166)
            {debugln(); debug(" 15: YES tag is looper");looperActive = true;}
            break;
        }
      }

        if (getScenes != 1) 
          { 
            debugln(); debugln();   debug(" * function wah_looper is started from onEffectsReceived() on axe_handler.h");
            wah_looper();
            }

  }

}


/*=======================================================================================================================================*/
//       PRESET VIEW SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void presetBank_settings()
{
  presetBank = 1;  // setting the number to 1 so it can finnish the job and in the end go to zero (0)
  debugln();debugln();  debug(" * presetBank is set to: "); debug(presetBank);
  
  debugln();debugln();  debug(" * function presetBank_settings started on axe_handler.h");
  
  CS1L, CS2L, CS3L, CS4L, CS5L, CS6L, CS7L, CS8L, CS9L, CS10L;

  tft.fillScreen(presetNumberStyle1_fillscreen);
  tft.setTextWrap(false); // we dont need this anymore

  CS1H, CS2H, CS3H, CS4H, CS5H, CS6H, CS7H, CS8H, CS9H, CS10H;


  if (auditionMode == true)
  {
    PresetNumb = CurPreset;
    presetRange();
    }


  if (PresetNumb < 10)
  {
    PNtxtWidth = 135;
  }
  else if (PresetNumb < 100)
  {
    PNtxtWidth = 123;
  }
  else if (PresetNumb < 1000)
  {
    PNtxtWidth = 105;
  }


  CS6L;
  strcpy(active_PresetName, PresetName0);
  PresetName_helper();
  if (PresetNumb != (active_Preset))
  {
    presetNames_buildup();
    presetNumberStyle1(); tft.println(PresetNumb);
  }
  else 
  {
    presetNumberStyle2_fillscreen;
    active_presetNames_buildup();
    presetNumberStyle2(); tft.println(PresetNumb);
  }
  CS6H;

    CS7L;
    strcpy(active_PresetName, PresetName1);
    PresetName_helper();
    if ((PresetNumb + 1) != (active_Preset))
    {
      presetNames_buildup();
      presetNumberStyle1(); tft.println(PresetNumb + 1);
    }
    else 
    {
      presetNumberStyle2_fillscreen;
      active_presetNames_buildup();
      presetNumberStyle2(); tft.println(PresetNumb + 1);
    }
    CS7H;

      CS8L;
      strcpy(active_PresetName, PresetName2);
      PresetName_helper();
      if ((PresetNumb + 2) != (active_Preset))
      {
        presetNames_buildup();
        presetNumberStyle1(); tft.println(PresetNumb + 2);
      }
      else 
      {
        presetNumberStyle2_fillscreen;
        active_presetNames_buildup();
        presetNumberStyle2(); tft.println(PresetNumb + 2);
      }
      CS8H;
    
        CS9L;
        strcpy(active_PresetName, PresetName3);
        PresetName_helper();
        if ((PresetNumb + 3) != (active_Preset))
        {
          presetNames_buildup();
          presetNumberStyle1(); tft.println(PresetNumb + 3);
        }
        else 
        {
          presetNumberStyle2_fillscreen;
          active_presetNames_buildup();
          presetNumberStyle2(); tft.println(PresetNumb + 3);
        }
        CS9H;
    
          CS10L;
          strcpy(active_PresetName, PresetName4);
          PresetName_helper();
          if ((PresetNumb + 4) != (active_Preset))
          {
            presetNames_buildup();
            presetNumberStyle1(); tft.println(PresetNumb + 4);
          }
          else 
          {
            presetNumberStyle2_fillscreen;
            active_presetNames_buildup();
            presetNumberStyle2(); tft.println(PresetNumb + 4);
          }
          CS10H;
    
            CS1L;
            strcpy(active_PresetName, PresetName5);
            PresetName_helper();
            if ((PresetNumb + 5) != (active_Preset))
            {
              presetNames_buildup();
              presetNumberStyle1(); tft.println(PresetNumb + 5);
            }
            else 
            {
              presetNumberStyle2_fillscreen;
              active_presetNames_buildup();
              presetNumberStyle2(); tft.println(PresetNumb + 5);
            }
            CS1H;
    
              CS2L;
              strcpy(active_PresetName, PresetName6);
              PresetName_helper();
              if ((PresetNumb + 6) != (active_Preset))
              {
                presetNames_buildup();
                presetNumberStyle1(); tft.println(PresetNumb + 6);
              }
              else 
              {
                presetNumberStyle2_fillscreen;
                active_presetNames_buildup();
                presetNumberStyle2(); tft.println(PresetNumb + 6);
              }
              CS2H;
    
                CS3L;
                strcpy(active_PresetName, PresetName7);
                PresetName_helper();
                if ((PresetNumb + 7) != (active_Preset))
                {
                  presetNames_buildup();
                  presetNumberStyle1(); tft.println(PresetNumb + 7);
                }
                else 
                {
                  presetNumberStyle2_fillscreen;
                  active_presetNames_buildup();
                  presetNumberStyle2(); tft.println(PresetNumb + 7);
                }
                CS3H;
    
                  CS4L;
                  strcpy(active_PresetName, PresetName8);
                  PresetName_helper();
                  if ((PresetNumb + 8) != (active_Preset))
                  {
                    presetNames_buildup();
                    presetNumberStyle1(); tft.println(PresetNumb + 8);
                  }
                  else 
                  {
                    presetNumberStyle2_fillscreen;
                    active_presetNames_buildup();
                    presetNumberStyle2(); tft.println(PresetNumb + 8);
                  }
                  CS4H;
    
                    CS5L;
                    strcpy(active_PresetName, PresetName9);
                    PresetName_helper();
                    if ((PresetNumb + 9) != (active_Preset))
                    {
                      presetNames_buildup();
                      presetNumberStyle1(); tft.println(PresetNumb + 9);
                    }
                    else 
                    {
                      presetNumberStyle2_fillscreen;
                      active_presetNames_buildup();
                      presetNumberStyle2(); tft.println(PresetNumb + 9);
                    }
                    CS5H;

      presetBank = 0;
      debugln();debugln();  debug(" * presetBank is set to: "); debug(presetBank);
      delay(50);
}

/*=======================================================================================================================================*/
//       AUDITIONMODE SETTINGS
/* ---------------------------------------------------------------------------------------------------------------------------------------*/


void Auditionmode_settings()
{
 
  debugln();debugln();  debug(" * function Auditionmode_settings started on axe_handler.h");
  
    PresetNumb = CurPreset;
    presetRange();

    CS6L;
    if (PresetNumb != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb);}
    CS6H;

    CS7L;
    if ((PresetNumb + 1) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 1);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 1);}
    CS7H;

    CS8L;
    if ((PresetNumb + 2) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 2);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 2);}
    CS8H;
  
    CS9L;
    if ((PresetNumb + 3) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 3);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 3);}
    CS9H;

    CS10L;
    if ((PresetNumb + 4) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 4);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 4);}
    CS10H;

    CS1L;
    if ((PresetNumb + 5) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 5);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 5);}
    CS1H;

    CS2L;
    if ((PresetNumb + 6) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 6);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 6);}
    CS2H;

    CS3L;
    if ((PresetNumb + 7) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 7);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 7);}
    CS3H;

    CS4L;
    if ((PresetNumb + 8) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 8);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 8);}
    CS4H;

    CS5L;
    if ((PresetNumb + 9) != (active_Preset))
    {presetNumberStyle1(); tft.println(PresetNumb + 9);}
    else 
    {presetNumberStyle2(); tft.println(PresetNumb + 9);}
    CS5H;
      presetBank = 0;
      debugln();debugln();  debug(" * presetBank is set to: "); debug(presetBank);
      delay(50);
}

/*=======================================================================================================================================*/
//       PRESET CHANGE
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void onPresetChange(AxePreset preset)
{
  debugln(); debugln();   debug(" * function onPresetChange started on axe_handler.h");
  
  const size_t sz = 150;
  char buf[sz];

  //AxeSystem has notified that all requested information has arrived!
  debugln(); debug(" Preset number: "); debug(preset.getPresetNumber());

  //You can print directly to a Print object
  strcpy(active_PresetName, (preset.getPresetName()));
  debugln(); debug(" Preset name: "); debug(active_PresetName);

  //================================
  // fill Presets for use in screens
  //================================

  /* setting the active sceneNumber and active_Preset for other functions */
  active_Preset =  (preset.getPresetNumber()); //setting the AxeFX active presetnumber
  sceneNumber   =  (preset.getSceneNumber()); //setting the active scenenumber
  CurPreset = active_Preset;
  debugln(); debug(" variable active_sceneNumber = "); debug(sceneNumber);
  debugln(); debug(" variable active_Preset = "); debug(active_Preset);
  debugln(); debug(" variable CurPreset = "); debug(CurPreset);

  if (auditionMode == true)
  {
  PresetNumb = CurPreset;   //setting the Current preset like presetnumb
  debugln(); debug(" variable PresetNumb on auditionmode = "); debug(PresetNumb);
  Auditionmode_settings();  // build up presetscreens and stay on preset screen
  debugln(); debugln();   debug(" * function onSceneName started on axe_handler.h");
  }
  else
    {
    PresetNumb = CurPreset; //setting the Current preset like presetnumb
    debugln(); debug(" variable PresetNumb = "); debug(PresetNumb);
    }
}


/*=======================================================================================================================================*/
/*Axelman8*/
