typedef struct _IMAGELISTDRAWPARAMS {
  DWORD      cbSize;
  HIMAGELIST himl;
  int        i;
  HDC        hdcDst;
  int        x;
  int        y;
  int        cx;
  int        cy;
  int        xBitmap;
  int        yBitmap;
  COLORREF   rgbBk;
  COLORREF   rgbFg;
  UINT       fStyle;
  DWORD      dwRop;
  DWORD      fState;
  DWORD      Frame;
  COLORREF   crEffect;
} IMAGELISTDRAWPARAMS, *LPIMAGELISTDRAWPARAMS;