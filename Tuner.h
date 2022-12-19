#pragma once


/*=======================================================================================================================================*/

uint8_t check[8] = {0x0, 0x1 ,0x3, 0x16, 0x1c, 0x8, 0x0};   //this is the checkmark when "IN TUNE"
char screenMessage[50];

TFT_eSPI* screen = new TFT_eSPI();

void onlyTuner()
{
  for ( currentSwitch = 0; currentSwitch < 18; currentSwitch++ ) 
  {
    if ((digitalRead(switches[currentSwitch]) != switchState[currentSwitch] ) && (switchState[currentSwitch] == HIGH)) 
    {
       switch ( currentSwitch ) {
          case 17:
          tempoflash.deleteSprite();
          Axe.toggleTuner();
          debugln(); debug(" Switch-18 ");
          delay(200);
          }
          break;
       }
    }
}


/*=======================================================================================================================================*/
//    Tuner on Screen 8 with the eSprite option from the BODMER library
/*---------------------------------------------------------------------------------------------------------------------------------------*/

byte tft_w = TUNER_TFT_WIDTH;
byte tft_h = TUNER_TFT_HEIGHT;

void drawCentreString(TFT_eSPI* canvas, const char* note, byte tft_h, byte tft_w)
{
  canvas->setTextDatum(MC_DATUM);
  canvas->setCursor(0, 0);
  canvas->drawString(note, tft_h/2, tft_w/2);
}


void drawArrow( int32_t xpos, int32_t ypos, int32_t h, int32_t w, int32_t r, uint32_t color) {
  int32_t x0, y0, x1, y1, x2, y2;
  x0 = xpos + (w / 2);
  y0 = ypos + (h / 2);
  x1 = xpos - (w / 2);
  y1 = ypos + (h / 2);
  x2 = xpos;
  y2 = ypos - (h / 2);

 
  CS8L;
  tft.fillTriangle(x0, y0, x1, y1, x2, y2, color);
  CS8H;
}


char lastNote[2];
char lastFineTune;
bool hasCleared = false;
TFT_eSprite* tunerNoteCanvas = NULL;

void displayTuner(TFT_eSPI* screen, const char *note, const byte string, const byte fineTune) 
{
   if (tunerScreen8 == 1)  // determine if we want the Tuner on screen 8 to start 
  {
  CS8L;

  tft.setRotation(1);
  if (tunerNoteCanvas == NULL) 
  {
    tunerNoteCanvas = new TFT_eSprite(screen);
    tunerNoteCanvas->setColorDepth(8);
    tunerNoteCanvas->createSprite(160, 128);
  }
  auto skipNoteDisplay = hasCleared && (note[0] == lastNote[0] && note[1] == lastNote[1]);
  lastNote[0] = note[0];
  lastNote[1] = note[1];  

  if (!hasCleared) 
  {
    screen->fillScreen(TFT_BLACK); 
    hasCleared = 1;
  }

  if (!skipNoteDisplay) 
  {
    sprintf(screenMessage, "%s", note);
    if (note[1] == '#' || note[1] == 'b') 
    {
      screenMessage[2] = '\0';
    }
    else 
    {
      screenMessage[1] = '\0';
    }

    tunerNoteCanvas->fillScreen(TFT_BLACK);
    tunerNoteCanvas->setTextSize(6);
    tunerNoteCanvas->setTextColor(TFT_GREEN);

    drawCentreString(tunerNoteCanvas, screenMessage, 160, 128/2);

    tunerNoteCanvas->fillRect(0, tft_h-53,160, 2, TFT_YELLOW);  // yellow line 
    tunerNoteCanvas->pushSprite(0, 0);
}
  
  if (lastFineTune != fineTune) 
  {
    // black out last marker (more efficient than full screen)
    int x = (lastFineTune / 127.0) * tft_w;

    // draw center line
    screen->fillRect(tft_w/2-1-3,tft_h-50-1, 5, 50, TFT_WHITE);
 
    if (tunerScreen8_Circle == 1)
    {screen->fillCircle(x, tft_h - 25, 15, TFT_BLACK);}
    else {drawArrow(x, 145, tft_h - 25, tft_h - 25, 50, TFT_BLACK);}

    // draw new marker
    lastFineTune = fineTune;
    auto tunerColour = fineTune > 60 && fineTune < 64 ? TFT_GREEN : TFT_RED;
    x = (fineTune / 127.0) * tft_w;

    if (tunerScreen8_Circle == 1)
    { screen->fillCircle(x, tft_h - 25, 15, tunerColour);}
    else {drawArrow(x, 145, tft_h - 25, tft_h - 25, 50, tunerColour);}
   }
  tft.fillRect(0, tft_h-53,160, 2, TFT_YELLOW);  // yellow line because of problem with screen width  
  CS8H;
 }
}


void onTunerData(const char *note, const byte string, const byte fineTune) 
   {
     displayTuner(screen, note, string, fineTune);
        }


/*=======================================================================================================================================*/
//   Tuner OFF
/*---------------------------------------------------------------------------------------------------------------------------------------*/

void onTunerStatus(bool engaged) {
  if (Axe.isTunerEngaged() == false)
  {
    if (auditionMode != 1)
  {
    getScenes = true;
    effectCycle = true;
    debugln(); debug(" *-> TUNER ended");
//    sceneTopscreens(); 
//    scenepageRebuild();  
//    ini_scenes();
    scenePage_selection();
    delay(200);
    }
  else
  {auditionmodePage_tuner_OFF_selection();}  //quick and dirty, but it works. 
  }
}

/*=======================================================================================================================================*/
/*Axelman8*/
