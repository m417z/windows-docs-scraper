typedef struct _DDOVERLAYFX {
  DWORD      dwSize;
  DWORD      dwAlphaEdgeBlendBitDepth;
  DWORD      dwAlphaEdgeBlend;
  DWORD      dwReserved;
  DWORD      dwAlphaDestConstBitDepth;
#if ...
  union {
    DWORD               dwAlphaDestConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaDest;
  } DUMMYUNIONNAMEN;
  DWORD      dwAlphaSrcConstBitDepth;
#else
  union {
    DWORD               dwAlphaSrcConst;
    LPDIRECTDRAWSURFACE lpDDSAlphaSrc;
  } DUMMYUNIONNAMEN;
#endif
  DDCOLORKEY dckDestColorkey;
  DDCOLORKEY dckSrcColorkey;
  DWORD      dwDDFX;
  DWORD      dwFlags;
} DDOVERLAYFX;