typedef struct _DDBLTFX {
  DWORD      dwSize;
  DWORD      dwDDFX;
  DWORD      dwROP;
  DWORD      dwDDROP;
  DWORD      dwRotationAngle;
  DWORD      dwZBufferOpCode;
  DWORD      dwZBufferLow;
  DWORD      dwZBufferHigh;
  DWORD      dwZBufferBaseDest;
  DWORD      dwZDestConstBitDepth;
#if ...
  union {
    DWORD               dwZDestConst;
    LPDIRECTDRAWSURFACE lpDDSZBufferDest;
  } DUMMYUNIONNAMEN;
  DWORD      dwZSrcConstBitDepth;
#elif
  union {
    DWORD               dwZSrcConst;
    LPDIRECTDRAWSURFACE lpDDSZBufferSrc;
  } DUMMYUNIONNAMEN;
  DWORD      dwAlphaEdgeBlendBitDepth;
  DWORD      dwAlphaEdgeBlend;
  DWORD      dwReserved;
  DWORD      dwAlphaDestConstBitDepth;
#elif
  union {
    DWORD               dwAlphaDestConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaDest;
  } DUMMYUNIONNAMEN;
  DWORD      dwAlphaSrcConstBitDepth;
#elif
  union {
    DWORD               dwAlphaSrcConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaSrc;
  } DUMMYUNIONNAMEN;
#else
  union {
    DWORD               dwFillColor;
    DWORD               dwFillDepth;
    DWORD               dwFillPixel;
    LPDIRECTDRAWSURFACE lpDDSPattern;
  } DUMMYUNIONNAMEN;
#endif
  DDCOLORKEY ddckDestColorkey;
  DDCOLORKEY ddckSrcColorkey;
} DDBLTFX;