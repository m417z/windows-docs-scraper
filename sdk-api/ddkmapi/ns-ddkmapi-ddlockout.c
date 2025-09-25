typedef struct _DDLOCKOUT {
  DWORD ddRVal;
  DWORD dwSurfHeight;
  DWORD dwSurfWidth;
  LONG  lSurfPitch;
  PVOID lpSurface;
  DWORD SurfaceCaps;
  DWORD dwFormatFlags;
  DWORD dwFormatFourCC;
  DWORD dwFormatBitCount;
  union {
    DWORD dwRBitMask;
    DWORD dwYBitMask;
  };
  union {
    DWORD dwGBitMask;
    DWORD dwUBitMask;
  };
  union {
    DWORD dwBBitMask;
    DWORD dwVBitMask;
  };
} DDLOCKOUT, *LPDDLOCKOUT;