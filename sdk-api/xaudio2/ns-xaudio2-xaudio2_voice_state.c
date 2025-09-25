typedef struct XAUDIO2_VOICE_STATE {
  void   *pCurrentBufferContext;
  UINT32 BuffersQueued;
  UINT64 SamplesPlayed;
} XAUDIO2_VOICE_STATE;