typedef struct _DD_CREATESURFACEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACEDESC       lpDDSurfaceDesc;
  PDD_SURFACE_LOCAL     *lplpSList;
  DWORD                 dwSCnt;
  HRESULT               ddRVal;
  VOID                  *CreateSurface;
} *PDD_CREATESURFACEDATA, DD_CREATESURFACEDATA;