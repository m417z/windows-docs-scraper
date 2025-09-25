typedef struct _DD_LOCKDATA {
  PDD_DIRECTDRAW_GLOBAL lpDD;
  PDD_SURFACE_LOCAL     lpDDSurface;
  DWORD                 bHasRect;
  RECTL                 rArea;
  LPVOID                lpSurfData;
  HRESULT               ddRVal;
  VOID                  *Lock;
  DWORD                 dwFlags;
  FLATPTR               fpProcess;
} *PDD_LOCKDATA, DD_LOCKDATA;