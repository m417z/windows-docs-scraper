typedef struct {
  DWORD              dwFlags;
  LPBITMAPINFOHEADER lpbiOutput;
  LPARAM             lOutput;
  LPBITMAPINFOHEADER lpbiInput;
  LPARAM             lInput;
  LONG               lStartFrame;
  LONG               lFrameCount;
  LONG               lQuality;
  LONG               lDataRate;
  LONG               lKeyRate;
  DWORD              dwRate;
  DWORD              dwScale;
  DWORD              dwOverheadPerFrame;
  DWORD              dwReserved2;
  LONG( )(LPARAM lInput,LONG lFrame,LPVOID lpBits,LONG len)              *GetData;
  LONG( )(LPARAM lOutput,LONG lFrame,LPVOID lpBits,LONG len)              *PutData;
} ICCOMPRESSFRAMES;