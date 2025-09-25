typedef struct _D3DHAL_DP2TEXBLT {
  DWORD dwDDDestSurface;
  DWORD dwDDSrcSurface;
  POINT pDest;
  RECTL rSrc;
  DWORD dwFlags;
} D3DHAL_DP2TEXBLT;