#pragma once


/*===========================================   -  Include library's  -  ================================================*/

#include <presets_ini.h>

/*=======================================================================================================================================*/
/* presetRange is to determen which bank you are in.  then it will display all 0-9 presets in that bank with page "preset-names"*/
/* ---------------------------------------------------------------------------------------------------------------------------------------*/

void presetRange()
{
  debugln(); debugln(); debug(" * function presetRange started on Preset_range.h"); 

switch (PresetNumb)
{
case 0 ... 9:   {PresetNumb = 0;} break; case 10 ... 19: {PresetNumb = 10;} break; case 20 ... 29: {PresetNumb = 20;} break; 
case 30 ... 39: {PresetNumb = 30;} break; case 40 ... 49: {PresetNumb = 40;} break; case 50 ... 59:{PresetNumb = 50;} break; 
case 60 ... 69: {PresetNumb = 60;} break; case 70 ... 79: {PresetNumb = 70;} break; case 80 ... 89:{PresetNumb = 80;} break; 
case 90 ... 99: {PresetNumb = 90;} break; case 100 ... 109: {PresetNumb = 100;} break; case 110 ... 119: {PresetNumb = 110;} break; 
case 120 ... 129: {PresetNumb = 120;} break; case 130 ... 139: {PresetNumb = 130;} break; case 140 ... 149: {PresetNumb = 140;} break;
case 150 ... 159: {PresetNumb = 150;} break; case 160 ... 169: {PresetNumb = 160;} break; case 170 ... 179: {PresetNumb = 170;} break; 
case 180 ... 189: {PresetNumb = 180;} break; case 190 ... 199: {PresetNumb = 190;} break; case 200 ... 209: {PresetNumb = 200;} break; 
case 210 ... 219: {PresetNumb = 210;} break; case 220 ... 229: {PresetNumb = 220;} break; case 230 ... 239: {PresetNumb = 230;} break; 
case 240 ... 249: {PresetNumb = 240;} break; case 250 ... 259: {PresetNumb = 250;} break; case 260 ... 269: {PresetNumb = 260;} break; 
case 270 ... 279: {PresetNumb = 270;} break; case 280 ... 289: {PresetNumb = 280;} break; case 290 ... 299: {PresetNumb = 290;} break;
case 300 ... 309: {PresetNumb = 300;} break; case 310 ... 319: {PresetNumb = 310;} break; case 320 ... 329: {PresetNumb = 320;} break; 
case 330 ... 339: {PresetNumb = 330;} break; case 340 ... 349: {PresetNumb = 340;} break; case 350 ... 359: {PresetNumb = 350;} break; 
case 360 ... 369: {PresetNumb = 360;} break; case 370 ... 379: {PresetNumb = 370;} break; case 380 ... 389: {PresetNumb = 380;} break; 
case 390 ... 399: {PresetNumb = 390;} break; case 400 ... 409: {PresetNumb = 400;} break; case 410 ... 419: {PresetNumb = 410;} break; 
case 420 ... 429: {PresetNumb = 420;} break; case 430 ... 439: {PresetNumb = 430;} break; case 440 ... 449: {PresetNumb = 440;} break;
case 450 ... 459: {PresetNumb = 450;} break; case 460 ... 469: {PresetNumb = 460;} break; case 470 ... 479: {PresetNumb = 470;} break; 
case 480 ... 489: {PresetNumb = 480;} break; case 490 ... 499: {PresetNumb = 490;} break; case 500 ... 509: {PresetNumb = 500;} break; 
case 510 ... 519: {PresetNumb = 510;} break;}
 if (strcmp(page, "preset") == 0)
 {
   debugln(); debugln();   debug(" * function preset_Names called on preset_range.h");
    preset_Names();
 }
}
