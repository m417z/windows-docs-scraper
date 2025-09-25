typedef struct {
  BOOL  Mute;
  LONG  Minimum;
  LONG  Maximum;
  union {
    LONG Reset;
    LONG Resolution;
  };
} KSAUDIO_MIX_CAPS, *PKSAUDIO_MIX_CAPS;