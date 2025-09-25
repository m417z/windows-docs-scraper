typedef struct _D3DHAL_DP2BUFFERBLT {
  DWORD    dwDDDestSurface;
  DWORD    dwDDSrcSurface;
  DWORD    dwOffset;
  D3DRANGE rSrc;
  DWORD    dwFlags;
} D3DHAL_DP2BUFFERBLT;