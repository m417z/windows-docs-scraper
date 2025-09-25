typedef struct {
  LONG         cbSize;
  DWORD        dwFlags;
  HIC          hic;
  DWORD        fccType;
  DWORD        fccHandler;
  LPBITMAPINFO lpbiIn;
  LPBITMAPINFO lpbiOut;
  LPVOID       lpBitsOut;
  LPVOID       lpBitsPrev;
  LONG         lFrame;
  LONG         lKey;
  LONG         lDataRate;
  LONG         lQ;
  LONG         lKeyCount;
  LPVOID       lpState;
  LONG         cbState;
} COMPVARS, *PCOMPVARS;