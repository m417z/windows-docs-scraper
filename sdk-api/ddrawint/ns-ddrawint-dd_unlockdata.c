typedef struct _DD_UNLOCKDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  HRESULT               ddRVal;
  VOID                  *Unlock;
} *PDD_UNLOCKDATA, DD_UNLOCKDATA;