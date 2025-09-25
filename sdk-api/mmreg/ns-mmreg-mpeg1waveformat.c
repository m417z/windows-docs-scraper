typedef struct mpeg1waveformat_tag {
  WAVEFORMATEX wfx;
  WORD         fwHeadLayer;
  DWORD        dwHeadBitrate;
  WORD         fwHeadMode;
  WORD         fwHeadModeExt;
  WORD         wHeadEmphasis;
  WORD         fwHeadFlags;
  DWORD        dwPTSLow;
  DWORD        dwPTSHigh;
} MPEG1WAVEFORMAT;