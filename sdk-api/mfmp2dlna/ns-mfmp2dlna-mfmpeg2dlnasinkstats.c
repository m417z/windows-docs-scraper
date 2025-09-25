typedef struct _MFMPEG2DLNASINKSTATS {
  DWORDLONG cBytesWritten;
  BOOL      fPAL;
  DWORD     fccVideo;
  DWORD     dwVideoWidth;
  DWORD     dwVideoHeight;
  DWORDLONG cVideoFramesReceived;
  DWORDLONG cVideoFramesEncoded;
  DWORDLONG cVideoFramesSkipped;
  DWORDLONG cBlackVideoFramesEncoded;
  DWORDLONG cVideoFramesDuplicated;
  DWORD     cAudioSamplesPerSec;
  DWORD     cAudioChannels;
  DWORDLONG cAudioBytesReceived;
  DWORDLONG cAudioFramesEncoded;
} MFMPEG2DLNASINKSTATS;