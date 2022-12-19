/*  
                                   _____ _                            _                 
                                  / ____| |                          | |                
                                 | |    | |__   __ _ _ __   __ _  ___| |     ___   __ _ 
                                 | |    | '_ \ / _` | '_ \ / _` |/ _ \ |    / _ \ / _` |
                                 | |____| | | | (_| | | | | (_| |  __/ |___| (_) | (_| |
                                  \_____|_| |_|\__,_|_| |_|\__, |\___|______\___/ \__, |
                                                            __/ |                  __/ |
                                                           |___/                  |___/ 


=======================================================================================================================================
* Origional version: Finished on 18-03-2021 
* 
* 
* Version: V1  01-03-2021   - show Available of wah(11) and looper(12) on screens:                            -> WORKING 
* 
* Version: V2  23-03-2021   - Tuner characters change + Tuner ON all other functions are OFF:                 -> WORKING
* 
* Version: V3  24-03-2021   - Change bootscreen logo axe fx III color to red white and blue:                  -> LOOKS NICE
*                           - overclock spi 44000000  Edit 01-04-2021 <- this is reversed back to 40000000    -> WORKING
*                           - opt out the BOUNCEDELAY and enabled per switch delay:                           -> WORKS BETTER
*                           
* Version: V4  09-04-2021   - Add number button control for taptempo:                                         -> WORKING
*                           - Had some trouble with the effect state showing the Wah and Looper available.    -> FIXED
*                           - Tuner OFF: Fetch active scene:                                                  -> WORKING
*                           
* Version: V4.1 09-04-2021  - Edit some issues with effects.                                                  -> WORKING
*              10-04-2021   - Try to make channels work with AMP and CAB, but got into complications with 
*                             the libriary. Asked TysonIT for help.                                           -> WAITING ON EDIT FOR AMP1
*                             
* Version: V4.2 11-04-2021  - Create new page with AMP AND CAB block settings for channel ABCD setting        -> DONE
*              11-04-2021   - Create ABCD settings and selecting per AMP-CAB                                  -> DONE
*              12-04-2021   - Set the correct AMP-CAB channel on screen refresh                               -> DONE
*                           - Activate AMP/CAB on selection if bypassed + setting to currentEffect.           -> DONE
*                           - Set to currentEffect is AMP-CAB = active                                        -> DONE
*                           - Bypass if AMP-CAB = currentEffect.  Set currentEffect = 0.                      -> DONE
*              16-04-2021   - Set channel A B C D GREEN border instead of RED as selected / active.           -> DONE
*              10-05-2021   - Test AMP name return with channel  ABCD  (sysex_Test)                           -> FAILED
*              11-05-2021   - Import @Piing V8.2 sysex code in sysexTest.h                                    -> Under construction  
*              11-05-2021   - Change bautrate to 250000. In my case this is speeding up a lot for testing     -> DONE
*              11-05-2021   - Change bautrate to 1000000. Speeding up TFT refresh a lot                       -> DONE
*              11-05-2021   - Add multiple options for Baudrate. outline those who not needed                 -> DONE
*              
* Version: V4.3 17-05-2021  - Change and rearange the Wah and Looper Active feature. Not allways working      -> DONE             
*              15-06-2021   - Add a RTC_DS3231 rtc digital clock  (instead of other crap)                     -> DONE
*                             NOTE:  Clock has to be set with 1st upload on the Pari_V*.* page
*                                    After setting the clock you can upload again with clock commented out
*                             Library is here: http://www.rinkydinkelectronics.com/download.php?f=DS3231.zip
*              26-06-2021   - Code cleanup,  Fix lcd toprow text with number settings                         -> DONE                             
*              11-07-2021   - Code cleanup,  Sysextest is of no use anymore                                   -> DONE
*                           - Preset page selecting preset is not showing the correct active scene            -> DONE
*              30-08-2021   - Again work on the wah and looper function.  Somehow the program changes                
*                             the order of functionality use and then the Available info 
*                             is not correctly shown.                                                         -> DONE
*                             
* Version: V5.0 31-08-2021  - Update to version V5.0                                                          -> DONE              
*              31-08-2021   - Add tab z_readme.h  for program information                                     -> DONE
*              03-09-2021   - Code adjustments on the setting_switches.h tab. Recreation of screens and button 
*                             build-up with Build-up styles.                                                  -> DONE and Working                
*              06-09-2021   - More code adjustments with styles on the screensetup.h and axe_handler.h 
*                             Code is better readable and adjustable for future editing software. Not even 
*                             close to editing with software, but i'm learning how to create a .cpp file 
*                             and use a .h file. If its usefull for the editing software i dont know yet      -> CODE IS DONE   
*              07-09-2021   - Optimize the Serial output to see proces flow                                   -> DONE               
*              08-09-2021   - Publish V5.0 on GitHub                                                          -> IN PROGRESS to be DONE
*              09-09-2021   - Optimize "void presetBank_settings()" on Axe_handler.h with presetStyle2 and
*                             a looptrough.  First time using loop. Does make a little diffrence in 
*                             screen buildup its somewhat slower i think, but very very minor                 -> DONE
*              16-09-2021   - change "void presetbank_settings()" on axe_handler.h                             
*                             This function is crashing the function "void AMP_effect_settings()" on 
*                             setting_switches.h  .   Did not find any solution to fix this.                   
*                             presetbank_settings reverted back to previous code                              -> DONE
*              16-09-2021   - Fixe effect issue with the last screen beeing a false screen that crashes       -> DONE               
*                           - Create new tab Screenstyle.h to place all screenstyles                          -> DONE
*                             Screen build-up styles are places on Screenstyle.h                              -> DONE
*                           - CODE optimization with more use off screen build-up style.                      -> DONE
*                             Screen build-up styles are places on screenSetup.h                              -> DONE
*                           - Create new tab preset_range.h                                                   -> DONE
*                           - Move the void presetrange() from setting_switches.h to this tab                 -> DONE            
*                           - Add #include "preset_range.h" to several tabs                                   -> DONE
* 
* Version: V5.1 01-10-2021  - New tab sd_program.h  for testing the #define variables                         -> DONE
*                           - Changed layout of the switches.  switch 1 - 15 are same as CS1-15               -> DONE     
*                           - Embed the #define values for switches in setting_switches                       -> DONE 
* 
* Version: V5.2 04-10-2021  - rearrange tabs:  tab SD_program.h moved foreward so the .ini first declared     -> DONE             
*                           - first time setting up screens with new variable buildup.  bootscreen first      -> DONE
*              12-10-2021   - Many code cleanup                                                               -> DONE
*              19-10-2021   - TAP function. Dedicated to screen 14. change TAP = TEMPO in output screen       -> DONE              
*              20-10-2021   - Add debugging to the serial. Option to turn DEBUG on and off                    -> DONE
*                             debug & debugln are now debug & debugln                                         -> DONE
*              01-11-2021   - Add CIRCLE Tuner from @PRONGS_368 to screen 8  (centre screen)                  -> DONE                 
*                           - Add TRIANGLE to the Tuner instead of CIRCLE                                     -> DONE
*                           - Add option to select CIRCLE or TRIANGLE tuner for screen 8                      -> DONE
*                           - Add option to select Tuner for screen 8                                         -> DONE
*                           - Add new screens layout (all screens) if Tuner screen 8 is true.                 -> DONE             
* 
* Version: V6.0 01-11-2021  - Add new version to GITHUB                                                       -> DONE                           
*               06-11-2021  - Change preset UP/DOWN screens. DISPLAY previous next preset number and name     -> DONE                
*               07-11-2021  - Preset names replaces on SD_program TAB.                                        -> DONE
*                           - Remove Preset_names.h                                                           -> DONE
*               09-11-2021  - Add MKII support.  presetrange = 1024                                           -> DONE
*               10-11-2021  - MKII support fully integraded. BUGFIX all errors                                -> DONE
*               12-01-2022  - V6.0_MKI created for personal use. No MKII needed                               -> DONE 
*               13-02-2022  - Edit   some settings to completely make this version MK1                        -> DONE
*               22-02-2022  - Add a flash to screen 14 for TAP TEMPO                                          -> DONE 
*                           - Selection for flash on pin 29 or screen 14 by true / false option on 
*                             SD_program.h                                                                    -> DONE
*               23-02-2022  - Add a second flash to screen 14 for TAP TEMPO                                   -> DONE                             
*               25-02-2022  - Add "on the fly" flash selection on screen 14 (audition mode ON)                -> DONE
*               01-03-2022  - Add "on the fly" TUNER selection on screen 12 (audition mode ON)                -> DONE                                     
*               01-03-2022  - CHANGE CLOCK on row 1 and MEMORY on row 2 in 16 x 2 LCD                         -> DONE
*               06-03-2022  - Bugfix bool tunerScreen8_Circle. removed from setup()                           -> DONE 
*                           - Bugfix bool tempoflash_bar. removed from setup()                                -> DONE               
*                           - Bugfix select an empty effectscreen makes the unit freeze.                      -> DONE  
*                             NOTE! I have no solution to clear the effectindex. Only good thing:
*                             the programme doesnt freeze anymore!
* Version: V7.0 07-03-2022  - Fixed the effect1 - effect19 by resetting the effect variable value to ZERO 
*                             on every new preset selection.                                                  -> DONE               
*               13-3-2022   - Rearange program files:  add them as libriary files:                
*                             1: Create SD_ini.h file for the personal screen definitions                     -> DONE                            
*                             2: Create variables_ini.h for the variables                                     -> DONE
*                             3: Create preset_ini.h for the user presets                                     -> DONE
                              NOTE:     Libriary files must be placed here:
                              C:\Users\[user]\Documents\Arduino\libraries\PARI_INI
*                           - Remove variables.h and SD_program.h from the .ino file                          -> DONE
*                           - FIX  In AUDIONMODE going to the tuner and back gave screen build-up problems    -> DONE 
*               23-3-2022   - FIX previous preset not showing correct presetname if preset = 9,19,29,39,etc   -> DONE              
*               27-3-2022   - Pre work for the GUI.  More flexibility for screen buildup coloring             -> DONE
*                           - Re-arrange looper options on the screens. Group functions in 2 rows             -> DONE
*                           - Create topcreens_ini Ability for user configuration settings in SD_ini.h        -> DONE
*                           - Move screenpin and switchpin layout -> SD_ini.h for user to edit layout         -> DONE
*                           
* Version: V7.1 01-04-2022  - ADD AMP names to AMP1 and AMP2 on "AMP/CAB ABCD" screen                         -> DONE                           
*                           - AMP names centre screen                                                         -> DONE
*               03-04-2022  - Bugfix:  On auditionmode -> software kept asking the fractal for preset info    -> FIXED            
*                           - re-install Tab variables.h into the .ino file.  Some variables not working      -> DONE
*                           - Remove variables_ini.h from the libriary                                        -> DONE
*                           - ADD millis timer BANKUP/BANKDOWN:  button fucntion freeze after quick push      -> DONE
*                           - ADD presetBank value 0 or 1 for beeing sure the button wont freeze up           -> DONE
*               18-05-2022  - FIX activescene not showing correctly in SCENE PAGE after TUNER MODE            -> DONE            
*                           - ADD preset active bezel with color changing ability                             -> DONE
*                           - ADD preset active bezel AUDITIONMODE with color changing ability                -> DONE

!!!!!!!!!!!!!!!!!!!!!!!!!!  - IMPORTANT!!!   USER NEEDS TO overwrite SD_ini.h   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
*                           - CHANGE preset names on the TFT. Now all presetnames are centered                -> DONE 
*                           - CHANGE preset_range.h  ->  now using switch statement instead of IF()  
*                             This speeds up the program                                                      -> DONE
*               19-05-2022  - FIX presetname on screen 13 when coming from TUNER                              -> DONE  
*               20-05-2022  - ADD RESET EFFECT boolean to SD_ini.h                                            -> DONE
*                           - ADD RESET EFFECT to default when going to SCENEPAGE from EFFECTPAGE             -> DONE 
*               24-04-2022  - REBUILD Screen port addressing.  Now using the Arduino DUE REG_PIO
*                             Screen refresh rate is faster.                                                  -> DONE            
*               25-04-2022  - NEW lib file.  PIN_ini.h for pinsettings.  Deleted from SD_ini.h                -> DONE              
*               19-06-2022  - Fix AMP1 not showing on tft1                                                    -> DONE             
*               14-9-2022   - Implement HOLD function.  For now easy acces to the LOOPER page                 -> DONE
*             
* 
* 
* Version: V8   11-12-2022            
!!!!!!!!!!!!!!!!!!!!!!!!!!  - IMPORTANT!!!   USER NEEDS TO overwrite SD_ini.h   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 
*                           - Fix holding the effects in effect screen. No more jumping on and off            -> DONE    
*                           - Fix effects not able to bypass or enable 1st initial start on new preset        -> DONE
*                           - Fix auditionmode sceen updating all presets on new selection. No more updating  -> DONE
*                           - ADD hold function for auditionMode                                              -> DONE
*                           - ADD reselect preset on the presetpage. Reselect exit presetpage goto scenepage  -> DONE
*                           - ADD reselect preset on auditionMode.Reselect exit auditionMode goto scenepage   -> DONE
*                           
* 
* Version: V8.1 19-12-2022                           
!!!!!!!!!!!!!!!!!!!!!!!!!!  - IMPORTANT!!!   USER NEEDS TO overwrite SD_ini.h   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!                           
*                           - Fix taptempo screen                                                             -> DONE                            
*                           - Remove AMP ABCD function completely                                             -> DONE
*                           - Adjust effectlayout in Scenepage                                                -> DONE    
========================================================================================================================*/
/*Axelman8*/
