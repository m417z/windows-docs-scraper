typedef struct heaacwaveinfo_tag {
  WAVEFORMATEX wfx;
  WORD         wPayloadType;
  WORD         wAudioProfileLevelIndication;
  WORD         wStructType;
  WORD         wReserved1;
  DWORD        dwReserved2;
} HEAACWAVEINFO;