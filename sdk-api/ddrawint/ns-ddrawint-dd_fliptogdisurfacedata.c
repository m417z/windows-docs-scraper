typedef struct _DD_FLIPTOGDISURFACEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  DWORD                 dwToGDI;
  DWORD                 dwReserved;
  HRESULT               ddRVal;
  VOID                  *FlipToGDISurface;
} *PDD_FLIPTOGDISURFACEDATA, DD_FLIPTOGDISURFACEDATA;