typedef struct {
  DWORD              dwFlags;
  LPBITMAPINFOHEADER lpbiSrc;
  LPVOID             lpSrc;
  LPBITMAPINFOHEADER lpbiDst;
  LPVOID             lpDst;
  int                xDst;
  int                yDst;
  int                dxDst;
  int                dyDst;
  int                xSrc;
  int                ySrc;
  int                dxSrc;
  int                dySrc;
} ICDECOMPRESSEX;