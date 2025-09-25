typedef struct _DD_BLTDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDDestSurface;
  RECTL                 rDest;
  PDD_SURFACE_LOCAL     lpDDSrcSurface;
  RECTL                 rSrc;
  DWORD                 dwFlags;
  DWORD                 dwROPFlags;
  DDBLTFX               bltFX;
  HRESULT               ddRVal;
  VOID                  *Blt;
  BOOL                  IsClipped;
  RECTL                 rOrigDest;
  RECTL                 rOrigSrc;
  DWORD                 dwRectCnt;
  LPRECT                prDestRects;
  DWORD                 dwAFlags;
  DDARGB                ddargbScaleFactors;
} *PDD_BLTDATA, DD_BLTDATA;