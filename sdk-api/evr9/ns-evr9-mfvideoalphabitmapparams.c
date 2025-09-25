typedef struct MFVideoAlphaBitmapParams {
  DWORD                 dwFlags;
  COLORREF              clrSrcKey;
  RECT                  rcSrc;
  MFVideoNormalizedRect nrcDest;
  FLOAT                 fAlpha;
  DWORD                 dwFilterMode;
} MFVideoAlphaBitmapParams;