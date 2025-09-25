typedef struct {
  ULONG            InputChannels;
  ULONG            OutputChannels;
  KSAUDIO_MIX_CAPS Capabilities[1];
} KSAUDIO_MIXCAP_TABLE, *PKSAUDIO_MIXCAP_TABLE;