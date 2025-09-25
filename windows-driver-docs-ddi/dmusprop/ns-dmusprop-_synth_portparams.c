typedef struct _SYNTH_PORTPARAMS {
  DWORD ValidParams;
  DWORD Voices;
  DWORD ChannelGroups;
  DWORD AudioChannels;
  DWORD SampleRate;
  DWORD EffectsFlags;
  DWORD Share;
} SYNTH_PORTPARAMS, *PSYNTH_PORTPARAMS;