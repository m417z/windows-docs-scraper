typedef struct _DD_SYNCSURFACEDATA {
  PDD_DIRECTDRAW_LOCAL lpDD;
  PDD_SURFACE_LOCAL    lpDDSurface;
  DWORD                dwSurfaceOffset;
  ULONG_PTR            fpLockPtr;
  LONG                 lPitch;
  DWORD                dwOverlayOffset;
  ULONG                dwDriverReserved1;
  ULONG                dwDriverReserved2;
  ULONG                dwDriverReserved3;
  ULONG                dwDriverReserved4;
  HRESULT              ddRVal;
} *PDD_SYNCSURFACEDATA, DD_SYNCSURFACEDATA;