typedef struct _D3DHAL_DP2BLT {
  DWORD dwSource;
  RECTL rSource;
  DWORD dwSourceMipLevel;
  DWORD dwDest;
  RECTL rDest;
  DWORD dwDestMipLevel;
  DWORD Flags;
} D3DHAL_DP2BLT;