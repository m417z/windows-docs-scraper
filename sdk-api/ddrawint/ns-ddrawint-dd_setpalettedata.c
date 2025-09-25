typedef struct _DD_SETPALETTEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  PDD_PALETTE_GLOBAL    lpDDPalette;
  HRESULT               ddRVal;
  VOID                  *SetPalette;
  BOOL                  Attach;
} *PDD_SETPALETTEDATA, DD_SETPALETTEDATA;