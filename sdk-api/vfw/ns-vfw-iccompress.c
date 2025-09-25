typedef struct {
  DWORD              dwFlags;
  LPBITMAPINFOHEADER lpbiOutput;
  LPVOID             lpOutput;
  LPBITMAPINFOHEADER lpbiInput;
  LPVOID             lpInput;
  LPDWORD            lpckid;
  LPDWORD            lpdwFlags;
  LONG               lFrameNum;
  DWORD              dwFrameSize;
  DWORD              dwQuality;
  LPBITMAPINFOHEADER lpbiPrev;
  LPVOID             lpPrev;
} ICCOMPRESS;