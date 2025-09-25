typedef struct AUDIO_EFFECT {
  GUID               id;
  BOOL               canSetState;
  AUDIO_EFFECT_STATE state;
} AUDIO_EFFECT;