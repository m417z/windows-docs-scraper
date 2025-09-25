typedef struct mpeglayer3waveformat_tag {
  WAVEFORMATEX wfx;
  WORD         wID;
  DWORD        fdwFlags;
  WORD         nBlockSize;
  WORD         nFramesPerBlock;
  WORD         nCodecDelay;
} MPEGLAYER3WAVEFORMAT;