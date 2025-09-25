typedef struct XAUDIO2_BUFFER {
  UINT32     Flags;
  UINT32     AudioBytes;
  const BYTE *pAudioData;
  UINT32     PlayBegin;
  UINT32     PlayLength;
  UINT32     LoopBegin;
  UINT32     LoopLength;
  UINT32     LoopCount;
  void       *pContext;
} XAUDIO2_BUFFER;