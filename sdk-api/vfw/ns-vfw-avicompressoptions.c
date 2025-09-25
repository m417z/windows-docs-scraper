typedef struct {
  DWORD  fccType;
  DWORD  fccHandler;
  DWORD  dwKeyFrameEvery;
  DWORD  dwQuality;
  DWORD  dwBytesPerSecond;
  DWORD  dwFlags;
  LPVOID lpFormat;
  DWORD  cbFormat;
  LPVOID lpParms;
  DWORD  cbParms;
  DWORD  dwInterleaveEvery;
} AVICOMPRESSOPTIONS, *LPAVICOMPRESSOPTIONS;