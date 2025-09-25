typedef struct {
  DWORD              dwFlags;
  LPBITMAPINFOHEADER lpbiInput;
  LPVOID             lpInput;
  LPBITMAPINFOHEADER lpbiOutput;
  LPVOID             lpOutput;
  DWORD              ckid;
} ICDECOMPRESS;