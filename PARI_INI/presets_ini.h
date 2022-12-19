#pragma once

/*=========================================================================================================================*/
/*=========================================================================================================================*/

                            /* ==========================================================
                               ====                                                 =====
                               ====           here are all the presetnames          =====
                               ====                                                 =====
                               ====                 from 0 - 511                    =====
                               ====                                                 =====
                               ====     Paste the info from the Excel page here     =====
                               ====                                                 =====
                               ==========================================================*/  
/*=========================================================================================================================*/
/*=========================================================================================================================*/

void preset_Names(void)
{
  debugln(); debug(" -> Preset names are beeing read from presets.ini.h");
  switch (PresetNumb)
  {

// Delete all below: 
// -> set the cursor in front of case 0 and select (CTRL+SHIFT+END) and then DEL 
// PASTE HERE UNDER your presetnames from the excel file
    
case 0: 
strcpy(PresetName0,("==/MARSHALL PRE-AMPS\=="));
strcpy(PresetName1,("JMP-1 OD1"));
strcpy(PresetName2,("JMP-1 OD2"));
strcpy(PresetName3,("OD1 Bass JMP-1"));
strcpy(PresetName4,("OD2 Bass JMP-1"));
strcpy(PresetName5,("Brit Preamp"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 10: 
strcpy(PresetName0,("==/MARSHALL AMPS\=="));
strcpy(PresetName1,("Treble 1959SLP"));
strcpy(PresetName2,("Jumped 1959SLP"));
strcpy(PresetName3,("Normal chnl 1959SLP"));
strcpy(PresetName4,("BrownSound Plexi"));
strcpy(PresetName5,("FAS BrownSound Plexi"));
strcpy(PresetName6,("Treble 1987x"));
strcpy(PresetName7,("Jumped 1987x"));
strcpy(PresetName8,("Normal chnl 1987x"));
strcpy(PresetName9,("Green OD1 JVM410H"));

break;

case 20: 
strcpy(PresetName0,("OrangeOD1 JVM410H"));
strcpy(PresetName1,("Red OD1 JVM410H"));
strcpy(PresetName2,("OD2 Green JVM410H"));
strcpy(PresetName3,("OD2 Orange JVM410H"));
strcpy(PresetName4,("OD2 Red JVM410H"));
strcpy(PresetName5,("OrangeCrunch JoeSatch410"));
strcpy(PresetName6,("RedCrunch JoeSatch410"));
strcpy(PresetName7,("OrangeLead JoeSatch410"));
strcpy(PresetName8,("Red Lead JoeSatch410"));
strcpy(PresetName9,("Slash's AFD100 1&2 chnl"));

break;

case 30: 
strcpy(PresetName0,("JCM800 (with V30's)"));
strcpy(PresetName1,("Mod JCM800 (V30's)"));
strcpy(PresetName2,("JCM800 (w/GrnBacks)"));
strcpy(PresetName3,("FAS HotRod Marshall"));
strcpy(PresetName4,("SuperLead Plexi"));
strcpy(PresetName5,("Silver Jubilee"));
strcpy(PresetName6,("High100W Plexi"));
strcpy(PresetName7,("Jumped100W Plexi"));
strcpy(PresetName8,("Normal100W Plexi"));
strcpy(PresetName9,("1970 Plexi100W"));

break;

case 40: 
strcpy(PresetName0,("Brite1 Plexi50W"));
strcpy(PresetName1,("Brite1 Plexi50W -AltCab"));
strcpy(PresetName2,("Brite2 Plexi50W"));
strcpy(PresetName3,("Brite2 Plexi50W -AltCab"));
strcpy(PresetName4,("Jumped 50W Plexi"));
strcpy(PresetName5,("Normal 50W Plexi"));
strcpy(PresetName6,("6550Tube 50WPlexi"));
strcpy(PresetName7,("2204 Plexi50W"));
strcpy(PresetName8,("JTM45 Plexi"));
strcpy(PresetName9,("Jumped JTM45"));

break;

case 50: 
strcpy(PresetName0,("6CA7 Plexi 50W"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 60: 
strcpy(PresetName0,("==/FRIEDMAN AMPS\=="));
strcpy(PresetName1,("#1 Dirty Shirley"));
strcpy(PresetName2,("#2 Dirty Shirley"));
strcpy(PresetName3,("Small Box"));
strcpy(PresetName4,("Brown Eye 2010*"));
strcpy(PresetName5,("C45 Brown Eye*"));
strcpy(PresetName6,("Brown Eye V1*"));
strcpy(PresetName7,("B Eye FAT V1*"));
strcpy(PresetName8,("B Eye V2*"));
strcpy(PresetName9,("B Eye V3*"));

break;

case 70: 
strcpy(PresetName0,("Hairy Brown Eye 2010*"));
strcpy(PresetName1,("C45 Hairy Brown Eye*"));
strcpy(PresetName2,("Hairy BE V1*"));
strcpy(PresetName3,("Hairy BE FAT V1*"));
strcpy(PresetName4,("Hairy BE V2*"));
strcpy(PresetName5,("Hairy BE V3*"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 80: 
strcpy(PresetName0,("==/SPLAWN AMPS\=="));
strcpy(PresetName1,("OD1 Nitrous Splawn"));
strcpy(PresetName2,("OD2 Nitrous Splawn"));
strcpy(PresetName3,("Plexi OD1 Splawn"));
strcpy(PresetName4,("Plexi OD2 Splawn"));
strcpy(PresetName5,("HotRod OD1 Splawn"));
strcpy(PresetName6,("HotRod OD2 Splawn"));
strcpy(PresetName7,("JCM OD1 QRod Splawn"));
strcpy(PresetName8,("JCM OD2 QRod Splawn"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 90: 
strcpy(PresetName0,("==/CAMERON AMPS\=="));
strcpy(PresetName1,("Atomica (Brown Sound)"));
strcpy(PresetName2,("#2 Atomica"));
strcpy(PresetName3,("1A&2A Cameron CCV100"));
strcpy(PresetName4,("1B&2B Cameron CCV100"));
strcpy(PresetName5,("2C Cameron CCV100"));
strcpy(PresetName6,("2D Cameron CCV100"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 100: 
strcpy(PresetName0,("==/SOLDANO AMPS\=="));
strcpy(PresetName1,("Clean X88 preamp Soldano cS"));
strcpy(PresetName2,("Rhythm X88 pre Soldano"));
strcpy(PresetName3,("Lead X88 pre Soldano"));
strcpy(PresetName4,("Clean X99 pre Soldano"));
strcpy(PresetName5,("Lead X99 pre Soldano"));
strcpy(PresetName6,("Solodano99 Lead Bright"));
strcpy(PresetName7,("SLO-100 Clean Soldano"));
strcpy(PresetName8,("SLO-100 Rhythm Soldano"));
strcpy(PresetName9,("SLO-100 Lead Soldano"));

break;

case 110: 
strcpy(PresetName0,("==/BOGNER AMPS\=="));
strcpy(PresetName1,("Shiva Bogner"));
strcpy(PresetName2,("#1 Uberschall Bogner"));
strcpy(PresetName3,("Vintage Bogner Ecstasy"));
strcpy(PresetName4,("Modern Bogner Ecstasy"));
strcpy(PresetName5,("Fish Brown (preamp)"));
strcpy(PresetName6,("*Strato Fish (Bogner pre)"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 120: 
strcpy(PresetName0,("==/HOOK CAPTAIN 34 AMPS\=="));
strcpy(PresetName1,("Hook 1A Clean chnl"));
strcpy(PresetName2,("Hook 1A (Pull Gain=On)"));
strcpy(PresetName3,("Hook 1B (EQ Bypass On)"));
strcpy(PresetName4,("Hook 1B (PGain=On+EQByp)"));
strcpy(PresetName5,("Hook 1B w/Cln1 ToneStack"));
strcpy(PresetName6,("Hook 2A"));
strcpy(PresetName7,("Hook 2B"));
strcpy(PresetName8,("Hook 2B (Edge=OFF)"));
strcpy(PresetName9,("Hook 3A"));

break;

case 130: 
strcpy(PresetName0,("Hook 3A (Edge=OFF)"));
strcpy(PresetName1,("Hook 3B"));
strcpy(PresetName2,("Hook 3B (Edge=OFF)"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 140: 
strcpy(PresetName0,("==/MISC. AMPS\=="));
strcpy(PresetName1,("Blankenship Leeds (DZ)"));
strcpy(PresetName2,("Komet 60"));
strcpy(PresetName3,("Concorde Komet"));
strcpy(PresetName4,("High Delivernc60 Fryette"));
strcpy(PresetName5,("Lo Delivernce60 Fryette"));
strcpy(PresetName6,("PRSArchon1"));
strcpy(PresetName7,("PRSArchon#2 (BriteChnl)"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 150: 
strcpy(PresetName0,("==/ENGL AMPS\=="));
strcpy(PresetName1,("Powerball ENGL"));
strcpy(PresetName2,("Extra Powerball"));
strcpy(PresetName3,("1ENGL Savage (CntourOFF)"));
strcpy(PresetName4,("2ENGL Savage (Cntour ON)"));
strcpy(PresetName5,("2ENGL#2 Savage (Cntr=ON)"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 160: 
strcpy(PresetName0,("==/DIEZEL AMPS\=="));
strcpy(PresetName1,("#1Das Metall brite"));
strcpy(PresetName2,("#2Das Metall dark"));
strcpy(PresetName3,("2-VH4 Silver Diezel"));
strcpy(PresetName4,("3-VH4 Silver Diezel"));
strcpy(PresetName5,("4-VH4 Silver Diezel"));
strcpy(PresetName6,("Xtra 3-VH4 Silver"));
strcpy(PresetName7,("Xtra 4-VH4 Silver"));
strcpy(PresetName8,("Blue2 VH4 Diezel (GrnBk)"));
strcpy(PresetName9,("Blue3 VH4 Diezel (GrnBk)"));

break;

case 170: 
strcpy(PresetName0,("Blue4 VH4 Diezel (GrnBk)"));
strcpy(PresetName1,("-2 Herbert Diezel"));
strcpy(PresetName2,("+2 Herbert Diezel"));
strcpy(PresetName3,("Ch3 Herbert Diezel"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 180: 
strcpy(PresetName0,("==/EVH 5150 AMPS\=="));
strcpy(PresetName1,("EVH Modern Rig 5150 III"));
strcpy(PresetName2,("EVH 50Watt Blue"));
strcpy(PresetName3,("Green 5150 EVH III"));
strcpy(PresetName4,("Blue 5150 EVH III"));
strcpy(PresetName5,("Red 5150 EVH III"));
strcpy(PresetName6,("Clean Brite 5150 III"));
strcpy(PresetName7,("Crunch 5150 III"));
strcpy(PresetName8,("FAS 6160"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 190: 
strcpy(PresetName0,("==/5150 MARK HOLCOMB w/PRS\=="));
strcpy(PresetName1,("Block 5150 (MarkH PRS)"));
strcpy(PresetName2,("Lead 5150+ (MarkH PRS)"));
strcpy(PresetName3,("Clean 5150+ (MarkH PRS)*"));
strcpy(PresetName4,("CrunchBrt 5150+ (MH PRS)"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 200: 
strcpy(PresetName0,("==/OTHER MODERN AMPS\=="));
strcpy(PresetName1,("#2 Uberschall Bogner"));
strcpy(PresetName2,("Cornford MK50 II"));
strcpy(PresetName3,("CarvinVL100 (Vai)"));
strcpy(PresetName4,("CarvinVL300 ch3"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 210: 
strcpy(PresetName0,("==/MESA BOOGIE IIC AMPS\=="));
strcpy(PresetName1,("IIC+JPMesaRig (Petrucci)"));
strcpy(PresetName2,("Sandman IIC+MetallcRig"));
strcpy(PresetName3,("IIC++ Metal-attic Style"));
strcpy(PresetName4,("Red&Yllw IIC+ Tones"));
strcpy(PresetName5,("Green IIC+ JP"));
strcpy(PresetName6,("Yellow IIC+ JP"));
strcpy(PresetName7,("Yellow IIC+ Shred JP"));
strcpy(PresetName8,("Red IIC+ JP"));
strcpy(PresetName9,("Red IIC+ Shred JP"));

break;

case 220: 
strcpy(PresetName0,("Deep+Brite IIC+"));
strcpy(PresetName1,("Brite IIC+"));
strcpy(PresetName2,("Deep IIC+"));
strcpy(PresetName3,("IIC+ Combo"));
strcpy(PresetName4,("IIC+1X12"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 230: 
strcpy(PresetName0,("==/MESA BOOGIE MARK IV AMPS\=="));
strcpy(PresetName1,("Mark IV Rig w/USA 4x12"));
strcpy(PresetName2,("Clean Mark IV"));
strcpy(PresetName3,("Rhythm Mark IV"));
strcpy(PresetName4,("Lead Mark IV"));
strcpy(PresetName5,("Brite Lead Mark IV"));
strcpy(PresetName6,("Mid Gain Lead Mark IV"));
strcpy(PresetName7,("Mid Gain+BriteLeadMarkIV"));
strcpy(PresetName8,("Mark IV InstantGrat."));
strcpy(PresetName9,("MarkIV 1Extras, USA 4x12"));

break;

case 240: 
strcpy(PresetName0,("Mark IV 2-Extras"));
strcpy(PresetName1,("MarkIV 3-Extras NonSiml"));
strcpy(PresetName2,("MarkIV 4-Extras NonSimul"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 250: 
strcpy(PresetName0,("==/MESA BOOGIE RECTOS\=="));
strcpy(PresetName1,("Dual Rectifier ModernRig"));
strcpy(PresetName2,("Orange1-Norm Dual Recto"));
strcpy(PresetName3,("Orange1-Modern DualRecto"));
strcpy(PresetName4,("Red1-Modern Dual Recto"));
strcpy(PresetName5,("2Orange Vntg TripleRecto"));
strcpy(PresetName6,("2Red Vntg Triple Recto"));
strcpy(PresetName7,("Orange2 Mdrn TripleRecto"));
strcpy(PresetName8,("Red2 Mdrn Triple Recto"));
strcpy(PresetName9,("Thorendahl DualRectifier"));

break;

case 260: 
strcpy(PresetName0,("Dual Recto 1-Extras"));
strcpy(PresetName1,("Dual Recto 2-Extras"));
strcpy(PresetName2,("Dual Recto 3-Extras"));
strcpy(PresetName3,("Dual Recto FactoryXtra"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 270: 
strcpy(PresetName0,("==/MESA BOOGIE MISC.\=="));
strcpy(PresetName1,("2 Triple Crest"));
strcpy(PresetName2,("3 Triple Crest"));
strcpy(PresetName3,("Triple Crest Extra"));
strcpy(PresetName4,("TXLonestar InstantGrat"));
strcpy(PresetName5,("TX Lonestar Rig"));
strcpy(PresetName6,("Lonestar ATimmons Rig*"));
strcpy(PresetName7,("Subway Blues"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 280: 
strcpy(PresetName0,("==/MESA BOOGIE PREAMPS\=="));
strcpy(PresetName1,("Clean1 Triaxis USA Cab"));
strcpy(PresetName2,("*S.Coil Cleans -Triaxis"));
strcpy(PresetName3,("Green Lead Triaxis"));
strcpy(PresetName4,("Yellow Lead Triaxis"));
strcpy(PresetName5,("Red1 Lead Triaxis"));
strcpy(PresetName6,("Red2 Shred Triaxis"));
strcpy(PresetName7,("Triaxis Extras"));
strcpy(PresetName8,("Triaxis Metallic Rig"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 290: 
strcpy(PresetName0,("==/FRACTAL AUDIO AMPS\=="));
strcpy(PresetName1,("Big Hair FAS"));
strcpy(PresetName2,("Skull Crusher FAS"));
strcpy(PresetName3,("Brootalz FAS"));
strcpy(PresetName4,("Modern FAS"));
strcpy(PresetName5,("II Modern FAS"));
strcpy(PresetName6,("III Modern FAS"));
strcpy(PresetName7,("Lead 1 FAS (w/Grnbks)"));
strcpy(PresetName8,("Lead 2 FAS (w/V30s)"));
strcpy(PresetName9,("Crunch FAS"));

break;

case 300: 
strcpy(PresetName0,("Rhythm by FAS"));
strcpy(PresetName1,("Supertweed FAS"));
strcpy(PresetName2,("Class-A FAS"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 310: 
strcpy(PresetName0,("==/MISCELLANEOUS\=="));
strcpy(PresetName1,("XTC Rig AustinBuddy"));
strcpy(PresetName2,("ElectricIn2Acoustic"));
strcpy(PresetName3,("*SteelStringSings4Strats"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 320: 
strcpy(PresetName0,("==/FENDER AMPS\=="));
strcpy(PresetName1,("Jumped '59 Bassman"));
strcpy(PresetName2,("'59 Bassman Bright"));
strcpy(PresetName3,("'59 Bassman <4 Gain"));
strcpy(PresetName4,("Jumped Twd Deluxe"));
strcpy(PresetName5,("Twd Deluxe"));
strcpy(PresetName6,("Twd Deluxe - <3 Gain"));
strcpy(PresetName7,("Twd Twin HiPower"));
strcpy(PresetName8,("Twd Princeton"));
strcpy(PresetName9,("Twd Champ"));

break;

case 330: 
strcpy(PresetName0,("Twd EC Champ"));
strcpy(PresetName1,("Twd RCA PreTubes Champ"));
strcpy(PresetName2,("Brwn Concert"));
strcpy(PresetName3,("Brwn Super"));
strcpy(PresetName4,("Brwn Vibrolux"));
strcpy(PresetName5,("SuperReverb BlackFace"));
strcpy(PresetName6,("Nrml SuperReverb chnl"));
strcpy(PresetName7,("Deluxe Vibrato chnl"));
strcpy(PresetName8,("Deluxe Normal chnl"));
strcpy(PresetName9,("AA Vibroverb 2x10"));

break;

case 340: 
strcpy(PresetName0,("AB Vibroverb 2x10"));
strcpy(PresetName1,("*StratSRV 1X15 Vibroverb"));
strcpy(PresetName2,("Twin Vibrato chnl"));
strcpy(PresetName3,("Twin Normal chnl"));
strcpy(PresetName4,("Princeton Reverb"));
strcpy(PresetName5,("Tremolux"));
strcpy(PresetName6,("'65Bassman"));
strcpy(PresetName7,("'65Bassman Bass chnl"));
strcpy(PresetName8,("Dweezil's Bassman"));
strcpy(PresetName9,("'68 Bandmaster"));

break;

case 350: 
strcpy(PresetName0,("70's Twin Silver"));
strcpy(PresetName1,("70's Princeton Silver"));
strcpy(PresetName2,("Vibroking"));
strcpy(PresetName3,("Vibroking Fat"));
strcpy(PresetName4,("Blues Jr."));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 360: 
strcpy(PresetName0,("==/VOX & VINTAGE\=="));
strcpy(PresetName1,("AC-15 Vox"));
strcpy(PresetName2,("#1 AC-30 Top Boost"));
strcpy(PresetName3,("#2 AC-30 Top Boost"));
strcpy(PresetName4,("AC-30 Brite + Normal*"));
strcpy(PresetName5,("Hot BMay AC-30"));
strcpy(PresetName6,("'64 Gibson Scout"));
strcpy(PresetName7,("Supro DualTone Pagey"));
strcpy(PresetName8,("Brite Hiwatt DR103"));
strcpy(PresetName9,("Jumped Hiwatt DR103"));

break;

case 370: 
strcpy(PresetName0,("4Gtr Ampeg SVT"));
strcpy(PresetName1,("Roland JC120*"));
strcpy(PresetName2,("==/MORGAN AMPS\=="));
strcpy(PresetName3,("EF86 Bass AC20"));
strcpy(PresetName4,("12AX7 Bass AC20"));
strcpy(PresetName5,("EF86 Treble AC20"));
strcpy(PresetName6,("12AX7 Treble AC20"));
strcpy(PresetName7,("==/MATCHLESS & SAMPSON AMPS\=="));
strcpy(PresetName8,("Matchless DC 30"));
strcpy(PresetName9,("DC-30 EF86"));

break;

case 380: 
strcpy(PresetName0,("Chieftain1 Matchless"));
strcpy(PresetName1,("Chieftain2 Matchless"));
strcpy(PresetName2,("Bad Cat 30 Sampson"));
strcpy(PresetName3,("==/DIVIDED BY 13 AMPS\=="));
strcpy(PresetName4,("FTR37 Hi /13"));
strcpy(PresetName5,("FTR37 Lo /13"));
strcpy(PresetName6,("CJ Boost Mode /by 13"));
strcpy(PresetName7,("CJ Divide /13"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 390: 
strcpy(PresetName0,("==/DR. Z AMPS\=="));
strcpy(PresetName1,("Maz 8 Dr. Z "));
strcpy(PresetName2,("Maz 38 Dr. Z"));
strcpy(PresetName3,("Route 66 Dr. Z"));
strcpy(PresetName4,("==/RUBY AMPS \=="));
strcpy(PresetName5,("Ruby Rocket*"));
strcpy(PresetName6,("Ruby Rocket Brite chnl*"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 400: 
strcpy(PresetName0,("==/MISCELLANEOUS AMPS\=="));
strcpy(PresetName1,("Swart Atomic Space Tone"));
strcpy(PresetName2,("Carr Rambler"));
strcpy(PresetName3,("Carr Rambler"));
strcpy(PresetName4,("Buddha Twinmaster"));
strcpy(PresetName5,("Rockerverb50 Orange"));
strcpy(PresetName6,("Tiny Terror Orange"));
strcpy(PresetName7,("AD30 Orange"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 410: 
strcpy(PresetName0,("/==TRAINWRECK AMPS\=="));
strcpy(PresetName1,("Express Trainwreck"));
strcpy(PresetName2,("Brite Express Trainwreck"));
strcpy(PresetName3,("Liverpool Trainwreck"));
strcpy(PresetName4,("Brite Liverpool Trnwreck"));
strcpy(PresetName5,("Rocket Trainwreck"));
strcpy(PresetName6,("FAS Wreck"));
strcpy(PresetName7,("FAS Express"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 420: 
strcpy(PresetName0,("==/SUHR AMPS\=="));
strcpy(PresetName1,("18W #1 Suhr Badger"));
strcpy(PresetName2,("18W #2 Suhr Badger"));
strcpy(PresetName3,("30W # 1Suhr Badger"));
strcpy(PresetName4,("30W # 2Suhr Badger"));
strcpy(PresetName5,("==/CUSTOM AUDIO ELEC. AMPS)\=="));
strcpy(PresetName6,("Clean CAE 3+"));
strcpy(PresetName7,("Rhythm CAE 3+"));
strcpy(PresetName8,("Lead CAE 3+"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 430: 
strcpy(PresetName0,("==/CAROL-ANN AMPS\=="));
strcpy(PresetName1,("Clean TripTik"));
strcpy(PresetName2,("Classic TripTik"));
strcpy(PresetName3,("Modern TripTik"));
strcpy(PresetName4,("Cln Tucana Carol Ann"));
strcpy(PresetName5,("Lead Tucana Carol Ann"));
strcpy(PresetName6,("OD2 Carol Ann Overdrive"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 440: 
strcpy(PresetName0,("==/DUMBLE STYLE AMPS\=="));
strcpy(PresetName1,("Clean Dumble ODS100"));
strcpy(PresetName2,("RFord ODS100"));
strcpy(PresetName3,("PAB Ford ODS100"));
strcpy(PresetName4,("PAB Mid+ Ford ODS100"));
strcpy(PresetName5,("HRM Dumble ODS100"));
strcpy(PresetName6,("Mid+HRM ODS100"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 450: 
strcpy(PresetName0,("FAS GOT 2022"));
strcpy(PresetName1,("LT Brown"));
strcpy(PresetName2,("LT Filth"));
strcpy(PresetName3,("LT Clean Amps"));
strcpy(PresetName4,("Mark Day IceCream"));
strcpy(PresetName5,("Fluff Drggd UndR"));
strcpy(PresetName6,("MF preset"));
strcpy(PresetName7,("CT RIG 2022"));
strcpy(PresetName8,("AW Paisley tele"));
strcpy(PresetName9,("AW Rascal Lead"));

break;

case 460: 
strcpy(PresetName0,("Moke's Magical"));
strcpy(PresetName1,("AB Lotsa Liking"));
strcpy(PresetName2,("AB Strat Jimi"));
strcpy(PresetName3,("AB EVH Live"));
strcpy(PresetName4,("AB Vaughan"));
strcpy(PresetName5,("AB Dual Recto"));
strcpy(PresetName6,("AB Raging Machine"));
strcpy(PresetName7,("CC Sound on Sound"));
strcpy(PresetName8,("Dumble and Dumbler"));
strcpy(PresetName9,("FREMEN BE All in one [Axe3]"));

break;

case 470: 
strcpy(PresetName0,("Shiver clean 1"));
strcpy(PresetName1,("York Audio - Gift of Tone"));
strcpy(PresetName2,("Syn Rhythm"));
strcpy(PresetName3,("Devs GOT"));
strcpy(PresetName4,("Phil Collen III"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 480: 
strcpy(PresetName0,("- NOMA KILLS -"));
strcpy(PresetName1,("NKP Dream Theater"));
strcpy(PresetName2,("NKP metallica"));
strcpy(PresetName3,("NKP malmsteen"));
strcpy(PresetName4,("NKP muse (plug in baby)"));
strcpy(PresetName5,("NKP meshuggah"));
strcpy(PresetName6,("NKP hendrix"));
strcpy(PresetName7,("NKP nirvana"));
strcpy(PresetName8,("NKP guns N roses"));
strcpy(PresetName9,("NKP Slayer"));

break;

case 490: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("EL34 Kitchen Sink"));
strcpy(PresetName2,("Just Fckn' Mean"));
strcpy(PresetName3,("Mapro"));
strcpy(PresetName4,("Modern Fenders"));
strcpy(PresetName5,("Plexi Plus"));
strcpy(PresetName6,("ElectricLadyLunch"));
strcpy(PresetName7,("Euro"));
strcpy(PresetName8,("Fender '61 AVII OW Strat Demo"));
strcpy(PresetName9,("Rumblin' Teles!"));

break;

case 500: 
strcpy(PresetName0,("Heavy Hitters x 2"));
strcpy(PresetName1,("Boogie IIC++"));
strcpy(PresetName2,("JP2C Best Rig"));
strcpy(PresetName3,("Meshuggah"));
strcpy(PresetName4,("Evailution 1 AM8"));
strcpy(PresetName5,("J. Mayer III"));
strcpy(PresetName6,("Chugnuts"));
strcpy(PresetName7,("Ambient Guitar"));
strcpy(PresetName8,("GRINDING FORTON 2"));
strcpy(PresetName9,("Chugga Chugga!"));

break;

case 510: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("CC's Sound on Sound"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;


case 520: 
strcpy(PresetName0,("Fremen Boutique Bleus"));
strcpy(PresetName1,("Rockin' Train"));
strcpy(PresetName2,("Dr Z's blues"));
strcpy(PresetName3,("Carol-Ann OD2 lead 1"));
strcpy(PresetName4,("Carol-Ann OD2 lead 2"));
strcpy(PresetName5,("Carol-Ann OD2 lead 3"));
strcpy(PresetName6,("Fat Buddah"));
strcpy(PresetName7,("Bright Buddah"));
strcpy(PresetName8,("Bludojai Lead 1"));
strcpy(PresetName9,("Bludojai Lead 2"));

break;

case 530: 
strcpy(PresetName0,("Two Rock to rock"));
strcpy(PresetName1,("Two Rock to rock II"));
strcpy(PresetName2,("Zen Wreck"));
strcpy(PresetName3,("FAS Wreck"));
strcpy(PresetName4,("What the Fuchs is goin'"));
strcpy(PresetName5,("ODS-100 Lead 1"));
strcpy(PresetName6,("ODS-100 Lead 2"));
strcpy(PresetName7,("ODS-100 Lead 3"));
strcpy(PresetName8,("ODS-100 Lead 4 Joe B"));
strcpy(PresetName9,("ODS-100 HRM Mid lead"));

break;

case 540: 
strcpy(PresetName0,("ODS-100 Ford lead 1"));
strcpy(PresetName1,("ODS-100 Ford lead 2"));
strcpy(PresetName2,("ODS-100 Ford lead 3"));
strcpy(PresetName3,("Dumble and Dumbler"));
strcpy(PresetName4,("Fat ODS-100"));
strcpy(PresetName5,("Fat lead"));
strcpy(PresetName6,("Komet Concorde 1"));
strcpy(PresetName7,("Komet Concorde 2"));
strcpy(PresetName8,("Komet Concorde 3"));
strcpy(PresetName9,("Tucana blues 1"));

break;

case 550: 
strcpy(PresetName0,("Tucana blues 2"));
strcpy(PresetName1,("Hook blues"));
strcpy(PresetName2,("Warm BogFish lead"));
strcpy(PresetName3,("5F1 Tweed EC"));
strcpy(PresetName4,("5F8 Tweed Normal"));
strcpy(PresetName5,("Blues Jr Fat"));
strcpy(PresetName6,("Texas Blues - Lonestar"));
strcpy(PresetName7,("Texas Blues - Vibroking"));
strcpy(PresetName8,("Texas Blues - VibratoVerb"));
strcpy(PresetName9,("Texas Blues - Bandmaster"));

break;

case 560: 
strcpy(PresetName0,("Texas Blues - Super Reverb"));
strcpy(PresetName1,("Texas Blues - Princeton"));
strcpy(PresetName2,("Texas Blues - Dr Z"));
strcpy(PresetName3,("Texas Blues - Bassman"));
strcpy(PresetName4,("Dirty tweed"));
strcpy(PresetName5,("Andy Little Wing"));
strcpy(PresetName6,("Just one night"));
strcpy(PresetName7,("AC20 crunch"));
strcpy(PresetName8,("AC20 crunch 2"));
strcpy(PresetName9,("AC20 fusion 1"));

break;

case 570: 
strcpy(PresetName0,("AC20 fusion 2"));
strcpy(PresetName1,("AC20 fusion 3"));
strcpy(PresetName2,("Crunchy D30"));
strcpy(PresetName3,("Div/13 crunch"));
strcpy(PresetName4,("J. Mayer I"));
strcpy(PresetName5,("J. Mayer II"));
strcpy(PresetName6,("J. Mayer III"));
strcpy(PresetName7,("Fat Carol"));
strcpy(PresetName8,("Dirty Carol"));
strcpy(PresetName9,("Crunchy Rocket"));

break;

case 580: 
strcpy(PresetName0,("Dirty Texas Blues"));
strcpy(PresetName1,("Vintage Santana"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 590: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 600: 
strcpy(PresetName0,("FREMEN BRIT PACK"));
strcpy(PresetName1,("Plexi 50w Normal"));
strcpy(PresetName2,("Plexi 50w Jump"));
strcpy(PresetName3,("Plexi 50w Jump 2"));
strcpy(PresetName4,("Plexi 100w High"));
strcpy(PresetName5,("Plexi 100w 1970"));
strcpy(PresetName6,("Plexi 100w 1970 II"));
strcpy(PresetName7,("Plexi 50w 6550"));
strcpy(PresetName8,("Plexi 50w 6550 II"));
strcpy(PresetName9,("Plexi 1959SLP Jump"));

break;

case 610: 
strcpy(PresetName0,("Plexi 2204"));
strcpy(PresetName1,("Plexi + Klon"));
strcpy(PresetName2,("Plexi 1987x Jump"));
strcpy(PresetName3,("Brit 800"));
strcpy(PresetName4,("Brit 800 #34"));
strcpy(PresetName5,("Brit 800 Mod"));
strcpy(PresetName6,("Brit JVM OD2 Green"));
strcpy(PresetName7,("Brit JVM OD2 Orange"));
strcpy(PresetName8,("Brit JVM OD2 Red"));
strcpy(PresetName9,("Brit JMPre-1 OD1 BS"));

break;

case 620: 
strcpy(PresetName0,("Brit JMPre-1 OD2 BS"));
strcpy(PresetName1,("Brit Pre"));
strcpy(PresetName2,("Dual Brit JMP"));
strcpy(PresetName3,("Brit JTM45 1 fat"));
strcpy(PresetName4,("Brit JTM45 2 acid"));
strcpy(PresetName5,("Brit JTM45 3"));
strcpy(PresetName6,("Old Plexi 1"));
strcpy(PresetName7,("Old Plexi 2"));
strcpy(PresetName8,("Plexi AC/DC"));
strcpy(PresetName9,("Brit Silver"));

break;

case 630: 
strcpy(PresetName0,("Brit Super"));
strcpy(PresetName1,("Hell's Belles"));
strcpy(PresetName2,("Spawn Q-Rod OD1-1"));
strcpy(PresetName3,("Spawn Q-Rod OD1-2"));
strcpy(PresetName4,("Spawn Q-Rod OD1-3"));
strcpy(PresetName5,("Spawn Nitrous 1"));
strcpy(PresetName6,("Spawn Nitrous 2"));
strcpy(PresetName7,("Atomica High 1"));
strcpy(PresetName8,("Atomica High 2"));
strcpy(PresetName9,("Cameron CCV 2A"));

break;

case 640: 
strcpy(PresetName0,("Cameron CCV 2C"));
strcpy(PresetName1,("Evil Citrus"));
strcpy(PresetName2,("Toxic Citrus"));
strcpy(PresetName3,("FAS Crunch"));
strcpy(PresetName4,("Hellios"));
strcpy(PresetName5,("Plexi 50w 6CA7"));
strcpy(PresetName6,("Vox Populi"));
strcpy(PresetName7,("Vox Dei"));
strcpy(PresetName8,("The quick brown Vox 8sc"));
strcpy(PresetName9,("Vox stacked delays"));

break;

case 650: 
strcpy(PresetName0,("A30 blue"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 660: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 670: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 680: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 690: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 700: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 710: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 720: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 730: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 740: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 750: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 760: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 770: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 780: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 790: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 800: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 810: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 820: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 830: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 840: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 850: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 860: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 870: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 880: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 890: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 900: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 910: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 920: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 930: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 940: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 950: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 960: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 970: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 980: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 990: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 1000: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 1010: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("<EMPTY>"));

break;

case 1020: 
strcpy(PresetName0,("<EMPTY>"));
strcpy(PresetName1,("<EMPTY>"));
strcpy(PresetName2,("<EMPTY>"));
strcpy(PresetName3,("<EMPTY>"));
strcpy(PresetName4,("<EMPTY>"));
strcpy(PresetName5,("<EMPTY>"));
strcpy(PresetName6,("<EMPTY>"));
strcpy(PresetName7,("<EMPTY>"));
strcpy(PresetName8,("<EMPTY>"));
strcpy(PresetName9,("Axelman8"));

break;

 }
}
