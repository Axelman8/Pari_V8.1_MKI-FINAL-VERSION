#include "interface/AxeEffect.h"
#include "interface/AxeSystem.h"

void AxeEffect::bypass() {
  _axe->disableEffect(_effectId);
  _bypassed = true;
}

void AxeEffect::enable() {
  _axe->enableEffect(_effectId);
  _bypassed = false;
}

void AxeEffect::toggle() { _bypassed ? enable() : bypass(); }

void AxeEffect::switchChannel(Channel channel) {
  _channel = channel;
  _axe->setEffectChannel(_effectId, channel);
}

void AxeEffect::incrementChannel() {
  if (++_channel >= _numChannels) {
    _channel = 0;
  }
  switchChannel(_channel);
}

void AxeEffect::decrementChannel() {
  if (_channel == 0) {
    _channel = _numChannels - 1;
  } else {
    _channel--;
  }
  switchChannel(_channel);
}

void AxeEffect::copyEffectName(char *buffer, byte max) {
  char tag[0];
  copyEffectNameAndTag(buffer, max, tag, 0);
}

void AxeEffect::copyEffectTag(char *buffer, byte max) {
  char name[0];
  copyEffectNameAndTag(name, 0, buffer, max);
}

// Thanks to https://forum.fractalaudio.com/members/alberta.7980/ for the hash
// wizardry

byte AxeEffect::offset() {
  // Needed because ID_MIDIBLOCK messes up the nice
  // blocks-of-four property in the IDs
  return _effectId > ID_MIDIBLOCK ? 3 : 0;
}

byte AxeEffect::hash() {
  byte hash = (_effectId - FIRST_EFFECT + offset()) / 4;
  unsigned last = arraySize(__EFFECT_NAME_TABLE) - 1;
  // Return 'unknown' for hash out of bounds
  if (hash < 0 || hash >= last) {
    hash = last;
  }
  return hash;
}

byte AxeEffect::blockNum() {
  unsigned last = arraySize(__EFFECT_NAME_TABLE) - 1;
  if (_effectId == ID_MIDIBLOCK || hash() == last) {
    return 0;
  }
  return ((_effectId - FIRST_EFFECT + offset()) % 4) + 1;
}

char AxeEffect::blockNumChar() {
  byte num = blockNum();
  return num > 0 ? num + ASCII_ZERO : '\0';
}

void AxeEffect::copyEffectNameAndTag(char *name, uint8_t szName, char *tag,
                                     uint8_t szTag) {
  char c = blockNumChar();
  EffectLabel label;
  memcpy_P(&label, &__EFFECT_NAME_TABLE[hash()], sizeof label);
  snprintf(name, szName, "%s%c", label.name, c);
  snprintf(tag, szTag, "%s%c", label.tag, c);
}

void AxeEffect::printEffectName(Print &printer, bool newline) {
  char c = blockNumChar();
  EffectLabel label;
  memcpy_P(&label, &__EFFECT_NAME_TABLE[hash()], sizeof label);
  printer.print(label.name);
  if (c)
    printer.print(c);
  if (newline)
    printer.println();
}

void AxeEffect::printEffectTag(Print &printer, bool newline) {
  char c = blockNumChar();
  EffectLabel label;
  memcpy_P(&label, &__EFFECT_NAME_TABLE[hash()], sizeof label);
  printer.print(label.tag);
  if (c)
    printer.print(c);
  if (newline)
    printer.println();
}

char AxeEffect::getChannelChar() { return 'A' + _channel; }

bool AxeEffect::isDrive() {
  return (_effectId >= ID_FUZZ1 && _effectId <= ID_FUZZ4);
}
bool AxeEffect::isDelay() {
  return (_effectId >= ID_DELAY1 && _effectId <= ID_DELAY4);
}
bool AxeEffect::isReverb() {
  return (_effectId >= ID_REVERB1 && _effectId <= ID_REVERB4);
}
bool AxeEffect::isChorus() {
  return (_effectId >= ID_CHORUS1 && _effectId <= ID_CHORUS4);
}
bool AxeEffect::isPhaser() {
  return (_effectId >= ID_PHASER1 && _effectId <= ID_PHASER4);
}
bool AxeEffect::isPitch() {
  return (_effectId >= ID_PITCH1 && _effectId <= ID_PITCH4);
}
bool AxeEffect::isCompressor() {
  return (_effectId >= ID_COMP1 && _effectId <= ID_COMP4);
}
bool AxeEffect::isInput() {  
return (_effectId >=   ID_INPUT1 && _effectId <=   ID_INPUT5); // USB Input);
}
bool AxeEffect::isOutput () {  
return (_effectId >=   ID_OUTPUT1 && _effectId <=   ID_OUTPUT4);
}
bool AxeEffect::isGrapheqEQ() {  
return (_effectId >=   ID_GRAPHEQ1 && _effectId <=   ID_GRAPHEQ4);
}
bool AxeEffect::isParaEQ() {  
return (_effectId >=   ID_PARAEQ1 && _effectId <=   ID_PARAEQ4);
}
bool AxeEffect::isDistort() {  
return (_effectId >=   ID_DISTORT1 && _effectId <=   ID_DISTORT4);
}
bool AxeEffect::isCab() {  
return (_effectId >=   ID_CAB1 && _effectId <=   ID_CAB4);
}
bool AxeEffect::isMultitap() {  
return (_effectId >=   ID_MULTITAP1 && _effectId <=   ID_MULTITAP4);
}
bool AxeEffect::isFlanger() {  
return (_effectId >=   ID_FLANGER1 && _effectId <=   ID_FLANGER4);
}
bool AxeEffect::isRotary() {  
return (_effectId >=   ID_ROTARY1 && _effectId <=   ID_ROTARY4);
}
bool AxeEffect::isWah() {  
return (_effectId >=   ID_WAH1 && _effectId <=   ID_WAH4);
}
bool AxeEffect::isFormant() {  
return (_effectId >=   ID_FORMANT1 && _effectId <=   ID_FORMANT4);
}
bool AxeEffect::isVolume() {  
return (_effectId >=   ID_VOLUME1 && _effectId <=   ID_VOLUME4);
}
bool AxeEffect::isTremolo() {  
return (_effectId >=   ID_TREMOLO1 && _effectId <=   ID_TREMOLO4);
}
bool AxeEffect::isFilter() {  
return (_effectId >=   ID_FILTER1 && _effectId <=   ID_FILTER4);
}
bool AxeEffect::isEnhancer() {  
return (_effectId >=   ID_ENHANCER1 && _effectId <=   ID_ENHANCER4);
}
bool AxeEffect::isMixer() {  
return (_effectId >=   ID_MIXER1 && _effectId <=   ID_MIXER4);
}
bool AxeEffect::isSynth() {  
return (_effectId >=   ID_SYNTH1 && _effectId <=   ID_SYNTH4);
}
bool AxeEffect::isVocoder() {  
return (_effectId >=   ID_VOCODER1 && _effectId <=   ID_VOCODER4);
}
bool AxeEffect::isMegatap() {  
return (_effectId >=   ID_MEGATAP1 && _effectId <=   ID_MEGATAP4);
}
bool AxeEffect::isCrossover() {  
return (_effectId >=   ID_CROSSOVER1 && _effectId <=   ID_CROSSOVER4);
}
bool AxeEffect::isGate() {  
return (_effectId >=   ID_GATE1 && _effectId <=   ID_GATE4);
}
bool AxeEffect::isRingmod() {  
return (_effectId >=   ID_RINGMOD1 && _effectId <=   ID_RINGMOD4);
}
bool AxeEffect::isMulticomp() {  
return (_effectId >=   ID_MULTICOMP1 && _effectId <=   ID_MULTICOMP4);
}
bool AxeEffect::isTentap() {  
return (_effectId >=   ID_TENTAP1 && _effectId <=   ID_TENTAP4);
}
bool AxeEffect::isResonator() {  
return (_effectId >=   ID_RESONATOR1 && _effectId <=   ID_RESONATOR4);
}
bool AxeEffect::isLooper() {  
return (_effectId >=   ID_LOOPER1 && _effectId <=   ID_LOOPER4);
}
bool AxeEffect::isTonematch() {  
return (_effectId >=   ID_TONEMATCH1 && _effectId <=   ID_TONEMATCH4);
}
bool AxeEffect::isRTA() {  
return (_effectId >=   ID_RTA1 && _effectId <=   ID_RTA4);
}
bool AxeEffect::isPlex() {  
return (_effectId >=   ID_PLEX1 && _effectId <=   ID_PLEX4);
}
// bool AxeEffect::isFbsend() {  
// return (_effectId >=   ID_FBSEND1 && _effectId <=   ID_FBSEND4);
// }
// bool AxeEffect::isFbreturn() {  
// return (_effectId >=   ID_FBRETURN1 && _effectId <=   ID_FBRETURN4);
// }
bool AxeEffect::isMultiplexer() {  
return (_effectId >=   ID_MULTIPLEXER1 && _effectId <=   ID_MULTIPLEXER4);
}
// bool AxeEffect::isIrplayer() {  
// return (_effectId >=   ID_IRPLAYER1 && _effectId <=   ID_IRPLAYER4);
// }






bool AxeEffect::defaultEffectFilter(const PresetNumber number,
                                    AxeEffect effect) {
  switch (effect.getEffectId()) {
  case ID_CONTROL:
  case ID_DISTORT1: // these are actually amps, fuz is distortion
  case ID_DISTORT2:
  case ID_DISTORT3:
  case ID_DISTORT4:
  case ID_CAB1:
  case ID_CAB2:
  case ID_CAB3:
  case ID_CAB4:
  case ID_TUNER:
  case ID_INPUT1:
  case ID_INPUT2:
  case ID_INPUT3:
  case ID_INPUT4:
  case ID_INPUT5:
  case ID_OUTPUT1:
  case ID_OUTPUT2:
  case ID_OUTPUT3:
  case ID_OUTPUT4:
  case ID_IRCAPTURE:
  case ID_RTA1:
  case ID_RTA2:
  case ID_RTA3:
  case ID_RTA4:
  case ID_LOOPER1:
  case ID_LOOPER2:
  case ID_LOOPER3:
  case ID_LOOPER4: 
  case ID_TONEMATCH1:
  case ID_TONEMATCH2:
  case ID_TONEMATCH3:
  case ID_TONEMATCH4:
  case ID_FBSEND1:
  case ID_FBSEND2:
  case ID_FBSEND3:
  case ID_FBSEND4:
  case ID_FBRETURN1:
  case ID_FBRETURN2:
  case ID_FBRETURN3:
  case ID_FBRETURN4:
  case ID_MULTIPLEXER1:
  case ID_MULTIPLEXER2:
  case ID_MULTIPLEXER3:
  case ID_MULTIPLEXER4:
  case ID_IRPLAYER1:
  case ID_IRPLAYER2:
  case ID_IRPLAYER3:
  case ID_IRPLAYER4:
  case ID_FOOTCONTROLLER:
  case ID_PRESET_FC:
    return false;
  default:
    return true;
  };
}
