typedef struct _AVIFILEINFOW {
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
  WCHAR szFileType[64];
} AVIFILEINFOW, *LPAVIFILEINFOW;