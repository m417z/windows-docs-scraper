typedef struct _DD_SETOVERLAYPOSITIONDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSrcSurface;
  PDD_SURFACE_LOCAL     lpDDDestSurface;
  LONG                  lXPos;
  LONG                  lYPos;
  HRESULT               ddRVal;
  VOID                  *SetOverlayPosition;
} *PDD_SETOVERLAYPOSITIONDATA, DD_SETOVERLAYPOSITIONDATA;