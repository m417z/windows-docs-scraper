typedef struct _SIDEBANDAUDIO_SIDETONE_PARAMS {
  ULONG                             EpIndex;
  BOOL                              Immediate;
  LONG                              Channel;
  SIDEBANDAUDIO_SIDETONE_DESCRIPTOR Sidetone;
} SIDEBANDAUDIO_SIDETONE_PARAMS, *PSIDEBANDAUDIO_SIDETONE_PARAMS;