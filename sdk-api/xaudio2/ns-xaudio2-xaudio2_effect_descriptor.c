typedef struct XAUDIO2_EFFECT_DESCRIPTOR {
  IUnknown *pEffect;
  BOOL     InitialState;
  UINT32   OutputChannels;
} XAUDIO2_EFFECT_DESCRIPTOR;