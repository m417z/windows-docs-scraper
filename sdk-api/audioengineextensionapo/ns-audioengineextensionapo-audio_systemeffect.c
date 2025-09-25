typedef struct AUDIO_SYSTEMEFFECT {
  GUID                     id;
  BOOL                     canSetState;
  AUDIO_SYSTEMEFFECT_STATE state;
} AUDIO_SYSTEMEFFECT;