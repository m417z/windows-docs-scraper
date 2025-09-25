typedef struct {
  LPBITMAPINFOHEADER lpbiIn;
  LPBITMAPINFOHEADER lpbiSuggest;
  int                dxSrc;
  int                dySrc;
  int                dxDst;
  int                dyDst;
  HIC                hicDecompressor;
} ICDRAWSUGGEST;