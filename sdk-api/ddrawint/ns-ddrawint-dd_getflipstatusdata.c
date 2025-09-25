typedef struct _DD_GETFLIPSTATUSDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  DWORD                 dwFlags;
  HRESULT               ddRVal;
  VOID                  *GetFlipStatus;
} *PDD_GETFLIPSTATUSDATA, DD_GETFLIPSTATUSDATA;