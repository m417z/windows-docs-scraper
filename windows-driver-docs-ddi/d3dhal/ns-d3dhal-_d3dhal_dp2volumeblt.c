typedef struct _D3DHAL_DP2VOLUMEBLT {
  DWORD  dwDDDestSurface;
  DWORD  dwDDSrcSurface;
  DWORD  dwDestX;
  DWORD  dwDestY;
  DWORD  dwDestZ;
  D3DBOX srcBox;
  DWORD  dwFlags;
} D3DHAL_DP2VOLUMEBLT;