typedef struct _DD_CANCREATESURFACEDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACEDESC       lpDDSurfaceDesc;
  DWORD                 bIsDifferentPixelFormat;
  HRESULT               ddRVal;
  VOID                  *CanCreateSurface;
} *PDD_CANCREATESURFACEDATA, DD_CANCREATESURFACEDATA;