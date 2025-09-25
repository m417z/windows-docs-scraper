typedef struct _AVIFILEINFOA {
  DWORD dwMaxBytesPerSec;
  DWORD dwFlags;
  DWORD dwCaps;
  DWORD dwStreams;
  DWORD dwSuggestedBufferSize;
  DWORD dwWidth;
  DWORD dwHeight;
  DWORD dwScale;
  DWORD dwRate;
  DWORD dwLength;
  DWORD dwEditCount;
  char  szFileType[64];
} AVIFILEINFOA, *LPAVIFILEINFOA;