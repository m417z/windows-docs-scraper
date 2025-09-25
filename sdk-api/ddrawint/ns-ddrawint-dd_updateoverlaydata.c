typedef struct _DD_UPDATEOVERLAYDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDDestSurface;
  RECTL                 rDest;
  PDD_SURFACE_LOCAL     lpDDSrcSurface;
  RECTL                 rSrc;
  DWORD                 dwFlags;
  DDOVERLAYFX           overlayFX;
  HRESULT               ddRVal;
  VOID                  *UpdateOverlay;
} *PDD_UPDATEOVERLAYDATA, DD_UPDATEOVERLAYDATA;