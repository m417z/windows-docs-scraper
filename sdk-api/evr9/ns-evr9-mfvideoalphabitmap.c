typedef struct MFVideoAlphaBitmap {
  BOOL                     GetBitmapFromDC;
  union {
    HDC               hdc;
    IDirect3DSurface9 *pDDS;
  } bitmap;
  MFVideoAlphaBitmapParams params;
} MFVideoAlphaBitmap;